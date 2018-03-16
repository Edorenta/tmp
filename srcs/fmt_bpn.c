/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 19:16:43 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/04 20:52:58 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		fmt_b(t_modifier *m, t_array *d, va_list ap)
{
	if (mod->flag.pad.hash)
		fta_append(d, "b", 1);
	return (fmt_uint(m, d, ap, 2));
}

int		fmt_p(t_modifier *m, t_array *d, va_list ap)
{
	(void)m;
	fta_append(d, "0x", 2);
	mod->length = 'L';
	return (fmt_uint(m, d, ap, 16));
}

int		fmt_n(t_modifier *m, t_array *d, va_list ap)
{
	int		*arg;

	arg = va_arg(ap, void *);
	mod->size = 0;
	mod->precision = -1;
	if (mod->length == 'H')
		*(char *)arg = (char)d->size;
	else if (mod->length == 'h')
		*(short *)arg = (short)d->size;
	else if (mod->length == 'l' || mod->length == 'z')
		*(long *)arg = (long)d->size;
	else if (mod->length == 'L')
		*(long long *)arg = (long long)d->size;
	else if (mod->length == 'j')
		*(intmax_t *)arg = (intmax_t)d->size;
	else
		*(int *)arg = (int)d->size;
	return (0);
}
