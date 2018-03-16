/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 19:16:43 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/04 20:52:58 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline int
	print(t_modifier *mod, t_array *sstr, va_list ap)
{
	int			i;
	const char	*c = "diouxXcCsSpbn\0";
	const void	*t[] = {&fmt_di, &fmt_di, &fmt_o, &fmt_u, &fmt_x,
			&fmt_cx, &fmt_c, &fmt_wc, &fmt_s, &fmt_ws,
			&fmt_p, &fmt_b, &fmt_n};

	if (mod->length == 'l' && is_in(mod->conversion, "cs\0") >= 0)
		mod->conversion -= 32;
	if (is_in(mod->conversion, "DOU\0") >= 0)
	{
		mod->conversion += 32;
		mod->length = 'l';
	}
	i = 0;
	while (c[i] != '\0' && mod->conversion != c[i])
		i++;
	if (c[i] != '\0')
		return (((int (*)())t[i])(mod, sstr, ap));
	fta_append(sstr, &mod->conversion, 1);
	return (1);
}

static inline int
	precision(t_modifier *mod, t_array *sstr, va_list ap)
{
	size_t	before;
	size_t	after;
	int		width;
	int		len;

	before = sstr->size;
	width = print(mod, sstr, ap);
	after = sstr->size;
	len = width;
	if (len < mod->precision && is_in(mod->conversion, FLAGS_NUM) >= 0)
	{
		while (len < mod->precision && ++len)
			fta_append(sstr, "0", 1);
		fta_swap(sstr, after - width, after);
	}
	return (len);
}

void
	convert(t_modifier *mod, t_array *sstr, va_list ap)
{
	size_t	before;
	size_t	after;
	int		width;
	int		len;

	before = sstr->size;
	width = precision(mod, sstr, ap);
	after = sstr->size;
	len = after - before;
	if (len < mod->size)
	{
		if (mod->flag.pad.zero
			&& mod->precision == -1
			&& !mod->flag.pad.minus)
		{
			while (len < mod->size && ++len)
				fta_append(sstr, "0", 1);
			before = after - width;
		}
		else
			while (len < mod->size && ++len)
				fta_append(sstr, " ", 1);
		if (!mod->flag.pad.minus)
			fta_swap(sstr, before, after);
	}
}
