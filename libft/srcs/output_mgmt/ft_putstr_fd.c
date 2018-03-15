/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:43:41 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 18:09:14 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output_mgmt.h"

void	ft_putstr_fd(char const *str, int fd)
{
	char const *ptr = str;

	while (*ptr != '\0')
		++ptr;
	write(fd, str, ptr - str);
}
