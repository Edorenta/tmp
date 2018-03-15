/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 00:40:45 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:31:22 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	while (*str != c && *str != '\0')
		str++;
	return (*str == c ? (char *)str : (void *)0);
}

int		contains(char const *str, char c)
{
	char const	*p = str;

	while (*p != '\0' && *p != c)
		p++;
	return (*p == '\0' ? -1 : p - str);
}
