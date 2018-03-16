/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 19:16:43 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/04 20:52:58 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <math.h>

int		fta_dtoa(t_array *sstr, long double x, int b)
{
	char const *const	base = "0123456789ABCDEF\0";
	double				mantissa;
	double				intg;
	int					ret;

	ret = 1 + fta_itoa_base(sstr, (long long)x, b, 0);
	fta_append(sstr, ",", 1);
	while ((mantissa = modf(x, &intg)) != 0.)
	{
		x *= b;
		fta_append(sstr, (void *)base + ((long long)x % b), 1);
		ret++;
	}
	return (ret);
}

int		fmt_f(void)
{
	return (0);
}
