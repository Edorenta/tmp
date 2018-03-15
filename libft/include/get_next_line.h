/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:15:12 by pde-rent          #+#    #+#             */
/*   Updated: 2018/02/08 10:54:17 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef UNISTD_H
# include <unistd.h>
#endif
#ifndef STDLIB_H
# include <stdlib.h>
#endif
# include "string_mgmt.h"
# include "memory_mgmt.h"

# define OPEN_MAX 5000
# define BUFF_SIZE 42
# ifndef IS
#	define IS(x) if (!x) return (0);
# endif

int		get_next_line(const int fd, char **line);

#endif
