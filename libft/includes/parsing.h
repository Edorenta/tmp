/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:15:12 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 10:25:26 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define BASE_UCASE     "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\0"
# define BASE_LCASE     "0123456789abcdefghijklmnopqrstuvwxyz\0"
# define STR_NULL       "(null)\n\0"
# ifndef STDINT_H
#  include <stdint.h>
# endif

char	*ft_itoa(int n);
int		ft_atoi(const char *str);
double	ft_atof(const char *str);
char	*ft_itoa_base(int n, uint8_t base);
int		ft_atoi_base(const char *str, uint8_t base);

#endif
