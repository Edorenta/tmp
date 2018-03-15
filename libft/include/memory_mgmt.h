/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:15:12 by pde-rent          #+#    #+#             */
/*   Updated: 2018/02/08 10:54:17 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_MANAGEMENT_H
# define MEMORY_MANAGEMENT_H

#ifndef STDDEF_H
# include <stddef.h>
#endif

void	ft_memdel(void **mem);
void	ft_swap(int *a, int *b);
void	ft_bzero(void *mem, size_t n);
void	*ft_memalloc(size_t size);
void	*ft_memset(void *mem, int c, size_t n);
void	*ft_memdup(const void *mem, size_t n);
void	*ft_memchr(const void *mem, int c, size_t n);
void	*ft_memcpy(void *mem2, const void *mem1, size_t n);
void	*ft_memmove(void *mem2, const void *mem1, size_t n);
void	*ft_memccpy(void *mem2, const void *mem1, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_safe_calloc(size_t count, size_t size);
void	*ft_realloc(void *mem, size_t old_size, size_t new_size, size_t factor);
void	ft_exit(char const *const fnc, char const *const str);
int		ft_memcmp(const void *mem2, const void *mem1, size_t n);

#endif
