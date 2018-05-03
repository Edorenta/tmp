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

int			is_space(const char c)
{
	return ((c < 14 && c > 7) || c == 32);
}

int			space_in(const char *str)
{
	const char	*p = str;
	int			i;
	int			prev;

	prev = 1;
	i = 0;
	while (*p)
	{
		(is_space(*p) && !prev) ? i++ : 0;
		prev = is_space(*p) ? 1 : 0;
		p++;
	}
	i = prev ? --i : i;
	return (i);
}

int			full_digits(const char *str)
{
	const char	*p = str;

	while (*p && ((*p >= '0' && *p <= '9') || is_space(*p)))
		p++;
	return (*p == '\0' ? 1 : 0);	
}

int		ft_atoi_mod(char *s, int *nbr)
{
	int		nb;
	int		i;
	int		sign;

	nb = 0;
	sign = (s[0] == '-' && s[1]) ? 1 : 0;
	i = sign;
	while (i >= 0 && s[i])
	{
		if (nb == 214748364 && ((sign && s[i] > 56) || (!sign && s[i] > 55)))
			i = -2;
		else if (s[i] < 48 || s[i] > 57 || nb > 214748364)
			i = -2;
		else
		{
			nb = nb * 10 + s[i] - 48;
			i++;
		}
	}
	if (sign)
		nb = -nb;
	*nbr = nb;
	return (i);
}
