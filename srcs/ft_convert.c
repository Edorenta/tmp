/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 02:02:14 by pde-rent          #+#    #+#             */
/*   Updated: 2017/01/31 18:07:49 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline int
	pf_print(t_modifier *m, t_array *d, va_list ap)
{
	int			i;
	char const	*c = "diouxXcCsSpbn";
	void *const	t[] = {&pf_cv_di, &pf_cv_di, &pf_cv_o, &pf_cv_u, &pf_cv_x,
			&pf_cv_cx, &pf_cv_c, &pf_cv_wc, &pf_cv_s, &pf_cv_ws,
			&pf_cv_p, &pf_cv_b, &pf_cv_n};

	if (m->length == 'l' && contains("cs", m->conversion) >= 0)
		m->conversion -= 32;
	if (contains("DOU", m->conversion))
	{
		m->conversion += 32;
		m->length = 'l';
	}
	i = 0;
	while (c[i] != '\0' && m->conversion != c[i])
		i++;
	if (c[i] != '\0')
		return (((int (*)())t[i])(m, d, ap));
	fta_append(d, &m->conversion, 1);
	return (1);
}

static inline int
	pf_precision(t_modifier *m, t_array *d, va_list ap)
{
	size_t	before;
	size_t	after;
	int		width;
	int		len;

	before = d->size;
	width = pf_print(m, d, ap);
	after = d->size;
	len = width;
	if (len < m->precision && contains(FTPF_NUMERIC, m->conversion) >= 0)
	{
		while (len < m->precision && ++len)
			fta_append(d, "0", 1);
		fta_swap(d, after - width, after);
	}
	return (len);
}

void
	pf_convert(t_modifier *m, t_array *d, va_list ap)
{
	size_t	before;
	size_t	after;
	int		width;
	int		len;

	before = d->size;
	width = pf_precision(m, d, ap);
	after = d->size;
	len = after - before;
	if (len < m->size)
	{
		if (m->booleans.n.zero
			&& m->precision == -1
			&& !m->booleans.n.minus)
		{
			while (len < m->size && ++len)
				fta_append(d, "0", 1);
			before = after - width;
		}
		else
			while (len < m->size && ++len)
				fta_append(d, " ", 1);
		if (!m->booleans.n.minus)
			fta_swap(d, before, after);
	}
}
