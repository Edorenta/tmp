/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 19:16:43 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/04 20:52:58 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline const char
	*ptr_atoi(char const *str, int *ret, va_list ap)
{
	if (*str == '*')
	{
		*ret = va_arg(ap, unsigned);
		return (str + 1);
	}
	*ret = 0;
	while ('0' <= *str && *str <= '9')
		*ret = 10 * (*ret) + *str++ - '0';
	return (str);
}

static inline void
	get_len(char c, char *len_mod)
{
	if ((c == 'h' || c == 'l') && *len_mod == c)
		*len_mod = c - 32;
	else if (*len_mod == 0 || !(c == 'h' && *len_mod != 'H'))
		*len_mod = c;
}

static inline const char
	*match(char const *str, t_modifier *mod, va_list ap)
{
	int			n;

	while (*str != '\0')
	{
		if (*str == '.')
			str = ptr_atoi(str + 1, &(mod->precision), ap) - 1;
		else if (('1' <= *str && *str <= '9') || *str == '*')
			str = ptr_atoi(str, &(mod->size), ap) - 1;
		else if ((n = is_in(*str, FLAGS_PADDING)) >= 0)
			mod->flag.t[n] = 1;
		else if (is_in(*str, FLAGS_WIDTH) >= 0)
			get_len(*str, &(mod->length));
		else if ((mod->conversion = *str))
			return (str + 1);
		str++;
	}
	return (str);
}

int
	ft_vasprintf(char **ret, char const *str, va_list ap)
{
	t_array		sstr;
	t_modifier	mod;
	char const	*ptr;

	sstr = NEW_ARRAY(char);
	fta_reserve(&sstr, ft_strlen(str));
	while (*str != '\0')
	{
		mod = NEW_MODIFIER;
		if (*str == '%' && (str = match(str + 1, &mod, ap)) && mod.conversion)
			convert(&mod, &sstr, ap);
		ptr = str;
		while (*ptr != '\0' && *ptr != '%')
			ptr++;
		if (ptr != str)
			fta_append(&sstr, (void *)str, ptr - str);
		str = ptr;
	}
	fta_append(&sstr, "\0", 1);
	fta_trim(&sstr);
	*ret = sstr.data;
	return (sstr.size - 1);
}
