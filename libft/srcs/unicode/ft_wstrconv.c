/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstrconv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 06:16:18 by pde-rent          #+#    #+#             */
/*   Updated: 2017/09/22 21:06:28 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unicode.h"

size_t		ft_wstrconv(char *buff, const wchar_t *wstr)
{
	size_t	ret;

	ret = 0;
	while (*wstr != 0)
		ret += ft_witoa(buff + ret, (wint_t)*(wstr++));
	return (ret);
}