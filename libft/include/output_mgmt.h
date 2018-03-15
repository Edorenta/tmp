/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_management.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:15:12 by pde-rent          #+#    #+#             */
/*   Updated: 2018/02/08 10:54:17 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FD_MANAGEMENT_H
# define FD_MANAGEMENT_H

#ifndef UNISTD_H
# include <unistd.h>
#endif
#ifndef STDINT_H
# include <stdint.h>
#endif
#ifndef STDDEF_H
# include <stddef.h>
#endif

# define BASE_UCASE     "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\0"
# define BASE_LCASE     "0123456789abcdefghijklmnopqrstuvwxyz\0"
# define STR_NULL       "(null)\n\0"

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnstr(char *str, size_t n);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnstr_fd(char *str, int fd, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_base(int n,uint8_t base);
void	ft_putnbr_fd(int n, int fd);
void	ft_putwchar(const wchar_t wstr);
void	ft_putwstr(const wchar_t *wstr);
void	ft_putwchar_fd(const wchar_t wstr, int fd);
void	ft_putwstr_fd(const wchar_t *wstr, int fd);
void	ft_putwnstr(const wchar_t *wstr, size_t n);
void	ft_putwnstr_fd(const wchar_t *wstr, int fd, size_t n);
void	ft_print_bits(unsigned int x, uint8_t bits);
void	ft_print_memory(const void *addr, size_t size);
int		get_next_line(int fd, char **line);

#endif
