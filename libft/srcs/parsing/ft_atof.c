/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 12:39:02 by pde-rent          #+#    #+#             */
/*   Updated: 2017/01/13 13:53:56 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths_op.h"
#include "char_class.h"
#ifndef STDINT_H
# include <stdint.h>
#endif

static	double	floating_part(const char *str, int i)
{
	uint8_t	n;
	double	f;

	n = 0;
	f = 0.0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		f = (f * 10.0) + (str[i] - '0');
		++i;
		++n;
	}
	return (f / ft_dpow(10.0, n));
}

double			ft_atof(const char *str)
{
	double		res;
	int8_t		neg;
	const char	*ptr;

	ptr = str;
	neg = 0;
	res = 0.0;
	while (ft_isspace(*ptr))
		ptr++;
	if (*ptr == '-')
	{
		neg = 1;
		++ptr;
	}
	while (*ptr >= '0' && *ptr <= '9')
	{
		res = (res * 10.0) + (*ptr - '0');
		++ptr;
	}
	if (*ptr == '.')
	{
		ptr++;
		res += floating_part(str, (int)(ptr - str));
	}
	return (neg ? -res : res);
}
