/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 00:41:20 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:32:09 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	char			*tmp;

	tmp = (void *)0;
	while (*str)
	{
		if (*str == (char)c)
			tmp = str;
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (tmp);
}
