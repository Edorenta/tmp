/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   public.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 19:16:43 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/04 20:52:58 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** _format_ is the string describing the expected output,
** the data being given through a unknown number
** of parameters following _format_.
** All those functions return the number of bytes written.
*/

/*
** Writes on the standard output.
*/

int		ft_printf(char const *fmt, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, fmt);
	ret = ft_vprintf(fmt, ap);
	va_end(ap);
	return (ret);
}

/*
** Writes on the provided file descriptor _fd_.
*/

int		ft_dprintf(int fd, char const *fmt, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, fmt);
	ret = ft_vdprintf(fd, fmt, ap);
	va_end(ap);
	return (ret);
}

/*
** Writes in the provided string _s_.
*/

int		ft_sprintf(char *s, char const *fmt, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, fmt);
	ret = ft_vsprintf(s, fmt, ap);
	va_end(ap);
	return (ret);
}

/*
** Writes into the provided string _s_, but not more than _n_ bytes
*/

int		ft_snprintf(char *s, size_t n, char const *fmt, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, fmt);
	ret = ft_vsnprintf(s, n, fmt, ap);
	va_end(ap);
	return (ret);
}

/*
** Allocates a string, writes into it, and returns a void pointer to
** it through _ret_
*/

int		ft_asprintf(char **strp, char const *fmt, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, fmt);
	ret = ft_vasprintf(strp, fmt, ap);
	va_end(ap);
	return (ret);
}
