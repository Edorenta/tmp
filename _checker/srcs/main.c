/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 07:42:13 by pde-rent          #+#    #+#             */
/*   Updated: 2018/04/12 08:08:02 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

static inline int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	while ((*str == 32) || (*str > 8 && *str < 14))
		str++;
	sign = ((*str == '-') ? -1 : 1);
	if ((*str == '-') || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		res = res * 10 - (*str++ - '0');
	return (sign * (-res));
}

static inline int	ft_putmsg(char *err_msg)
{
	size_t	slen;

	slen = 0;
	while (err_msg[slen])
		++slen;
	if (!slen)
		return (0);
	write(1, err_msg, slen);
	write(1, "\n", 1);
	return (1);
}

static inline int	ft_isnum(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (!((str[i] > 47 && str[i] < 58) || str[i] == '-' || str[i] == '+'))
			return (0);
	return (1);
}

int					main(int ac, char **av)
{
	int c;
	int i;
	int last;

	if (ac < 2)
		return (ft_putmsg("error: please specify an integer list as argument"));
	i = 1;
	last = INT_MIN;
	while (i < ac)
	{
		if (!ft_isnum(av[i]))
			return (ft_putmsg("error: invalid arguments"));
		c = ft_atoi(av[i]);
		if (c < last)
			return (ft_putmsg("KO"));
		last = c;
		i++;
	}
	ft_putmsg("OK");
	return (0);
}
