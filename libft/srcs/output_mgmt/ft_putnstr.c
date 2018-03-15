/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:43:41 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/25 17:48:17 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output_mgmt.h"

void	ft_putnstr(char const *str, size_t n)
{
	char const *ptr = str;

	while (*ptr != '\0')
		++ptr;
	n = (ptr - str) > n ? n : (ptr - str);
	write(1, str, n);
}
