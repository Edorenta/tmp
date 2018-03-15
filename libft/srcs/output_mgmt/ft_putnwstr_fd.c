/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 06:16:18 by pde-rent          #+#    #+#             */
/*   Updated: 2017/09/22 21:06:28 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output_mgmt.h"
#include "unicode.h"

void		ft_putnwstr(const wchar_t *wstr, int fd, size_t n)
{
	size_t		i;

	i = (ft_wcslen(wstr));
	n = i > n ? n : i;
	i = 0;
	while (wstr[i])
	{
		ft_putwchar_fd(wstr[i], fd);
		i++;
	}
}