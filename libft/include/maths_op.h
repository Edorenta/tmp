/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_operators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:31:16 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/14 18:00:56 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_OP_H
# define MATHS_OP_H

#ifndef STDINT_H
# include <stdint.h>
#endif

int			ft_iabs(int nb);
long		ft_labs(long nb);
long long	ft_llabs(long long nb);
double		ft_dabs(double nb);
int			ft_ipow(int nb, uint8_t exp);
long		ft_lpow(long nb, uint8_t exp);
long long	ft_llpow(long long nb, uint8_t exp);
double		ft_dpow(double nb, uint8_t exp);
int			ft_fact(int nb);
long		ft_fibo(int nb);
int			ft_gcd(int x, int y);
int			ft_rand(int min, int max);
int			ft_sqrt(int nb);

#endif
