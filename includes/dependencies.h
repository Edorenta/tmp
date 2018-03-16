/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 19:38:16 by pde-rent          #+#    #+#             */
/*   Updated: 2017/03/21 13:33:02 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEPENDENCIES_H
# define DEPENDENCIES_H

# include <stdarg.h>

# include "../libft/includes/libft.h"

# define FLAGS_FMT		"diouxXDOUeEfFgGaAcCsSpnb\0"
# define FLAGS_NUM		"diouDOUxXpb\0"
# define FLAGS_WIDTH	"hljzL\0"
# define FLAGS_PADDING	"0+- #_\0"

typedef struct		s_modifier
{
	union
	{
		char		t[6];
		struct
		{
			char	zero;
			char	plus;
			char	minus;
			char	space;
			char	hash;
			char	uscore;
		}			pad;
	}				flag;
	char			conversion;
	char			length;
	int				size;
	int				precision;
}					t_modifier;

# define NEW_MODIFIER (t_modifier){{{0, 0, 0, 0, 0, 0}}, 0, 0, -1, -1};

void				db_print_modifier(t_modifier *mod);
void				convert(t_modifier *mod, t_array *d, va_list ap);
int					fmt_int(t_modifier *mod,
	t_array *d, va_list ap, int b);
int					fmt_uint(t_modifier *mod,
	t_array *d, va_list ap, int b);
int					fta_itoa_base(t_array *d, intmax_t n, int b, char info);

int					fmt_di(t_modifier *mod, t_array *d, va_list ap);
int					fmt_s(t_modifier *mod, t_array *d, va_list ap);
int					fmt_ws(t_modifier *mod, t_array *d, va_list ap);
int					fmt_c(t_modifier *mod, t_array *d, va_list ap);
int					fmt_wc(t_modifier *mod, t_array *d, va_list ap);
int					fmt_o(t_modifier *mod, t_array *d, va_list ap);
int					fmt_x(t_modifier *mod, t_array *d, va_list ap);
int					fmt_cx(t_modifier *mod, t_array *d, va_list ap);
int					fmt_u(t_modifier *mod, t_array *d, va_list ap);
int					fmt_b(t_modifier *mod, t_array *d, va_list ap);
int					fmt_p(t_modifier *mod, t_array *d, va_list ap);
int					fmt_n(t_modifier *mod, t_array *d, va_list ap);

#endif
