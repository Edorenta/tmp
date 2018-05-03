/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_extract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:32:18 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/24 11:32:22 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n < -9)
			ft_putnbr(-(n / 10));
		ft_putchar('0' - n % 10);
	}
	else if (n < 10)
		ft_putchar('0' + n);
	else
	{
		ft_putnbr(n / 10);
		ft_putchar('0' + n % 10);
	}
}

void	psfd(const char *s, int fd)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
}

int		ft_puterr_fd(const char *s, int fd, int ret)
{
	psfd(s, fd);
	return (ret);
}

int		ft_strequ(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i] && s2[i])
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
		if ((s1[i]) != (s2[i]))
			return (0);
		return (1);
	}
	return (0);
}
