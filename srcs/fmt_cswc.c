/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_alpha.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 19:16:43 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/04 20:52:58 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unicode.h"
#include "ft_printf.h"

int		fmt_s(t_modifier *mod, t_array *sstr, va_list ap)
{
	char	*arg;
	int		ret;

	arg = va_arg(ap, char *);
	if (arg == NULL)
		arg = "(null)";
	ret = (mod->precision >= 0 ? MIN(ft_strlen(arg), (size_t)mod->precision)
		: ft_strlen(arg));
	fta_append(sstr, (void *)arg, ret);
	return (ret);
}

int		fmt_ws(t_modifier *mod, t_array *sstr, va_list ap)
{
	wchar_t	*arg;
	size_t	len;

	arg = va_arg(ap, wchar_t *);
	if (arg == NULL)
		arg = L"(null)";
	fta_reserve(sstr, 4 * ft_wcslen(arg));
	if (mod->precision >= 0)
		len = ft_wstrnconv((char *)ARRAY_END(sstr), arg, mod->precision);
	else
		len = ft_wstrconv((char *)ARRAY_END(sstr), arg);
	sstr->size += len;
	return (len);
}

int		fmt_c(t_modifier *mod, t_array *sstr, va_list ap)
{
	unsigned char	arg;

	(void)mod;
	arg = (char)va_arg(ap, int);
	fta_append(sstr, (void *)&arg, 1);
	return (1);
}

int		fmt_wc(t_modifier *mod, t_array *sstr, va_list ap)
{
	wint_t	arg;
	size_t	ret;

	(void)mod;
	arg = va_arg(ap, wint_t);
	fta_reserve(sstr, 4);
	ret = ft_witoa((char *)ARRAY_END(sstr), arg);
	sstr->size += ret;
	return ((int)ret);
}
