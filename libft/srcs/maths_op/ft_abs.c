/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:59:21 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:34:34 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_iabs(int nb)
{
	return ((nb < 0) ? -nb : nb);
}

long		ft_labs(long nb)
{
	return ((nb < 0) ? -nb : nb);
}

long long	ft_llabs(long long nb)
{
	return ((nb < 0) ? -nb : nb);
}

double		ft_dabs(double nb)
{
	return ((nb < 0) ? -nb : nb);
}