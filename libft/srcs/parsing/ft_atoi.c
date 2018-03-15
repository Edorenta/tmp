/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 12:39:02 by pde-rent          #+#    #+#             */
/*   Updated: 2017/01/13 13:53:56 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "char_class.h"

int		ft_atoi(const char *str)
{
	int		res;
	int		sign;

	while (ft_isspace(*str))
		++str;
	sign = *str == '-' ? -1 : 1;
	if (*str == '+' || *str == '-')
		++str;
	res = 0;
	while (ft_isdigit(*str))
		res = 10 * res + sign * (*str++ - '0');
	return (res);
}
