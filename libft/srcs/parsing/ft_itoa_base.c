/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:37:29 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/14 17:58:25 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths_op.h"
#include "parsing.h"
#ifndef STDINT_H
#	include <stdlib.h>
#endif

static void		get_base(int n, uint8_t b, char *res, int *p)
{
	if (n <= (int)-b || (int)b <= n)
		get_base(n / (int)b, b, res, p);
	res[(*p)++] = BASE_LCASE[ft_iabs(n % (int)b)];
}

char			*ft_itoa_base(int value, uint8_t base)
{
	char	*res;
	int		p;

	if (base < 2 || 36 < base
		|| !(res = (char *)malloc(sizeof(char) * (sizeof(int) * 8 + 1))))
		return ((void *)0);
	p = 0;
	if (value < 0)
		res[p++] = '-';
	get_base(value, base, res, &p);
	res[p] = '\0';
	return (res);
}
