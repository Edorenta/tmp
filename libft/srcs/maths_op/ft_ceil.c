/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:29:41 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 18:58:21 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_iceil(double n)
{
	if (((double)((int)n) == n))
		return (n);
	return ((int)n + 1);
}

long		ft_lceil(double n)
{
	if (((double)((long)n) == n))
		return (n);
	return ((long)n + 1);
}

long long	ft_llceil(double n)
{
	if (((double)((long long)n) == n))
		return (n);
	return ((long long)n + 1);
}
