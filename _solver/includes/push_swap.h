/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:22:20 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/05 10:22:23 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# define A_FIRST		env->a_first->val
# define A_NEXTF		env->a_first->next
# define B_NEXTF		env->b_first->next
# define A_NEXT			A_NEXTF->val
# define A_LAST			env->a_last->val
# define IS_SET(X)		ft_strequ(X, av[env->index])
# define SET_PRINT		(env->options ^= (1 << 0))
# define SET_RPRINT		(env->options ^= (1 << 1))
# define SET_FREEZE		(env->options ^= (1 << 2))
# define SET_OP_CNT		(env->options ^= (1 << 3))
# define SET_CMP_CNT	(env->options ^= (1 << 4))
# define SET_BASIC		(env->options ^= (1 << 5))
# define SET_RBASIC		(env->options ^= (1 << 6))
# define SET_JSON		(env->options ^= (1 << 7))
# define SET_FIRST		(env->options ^= (1 << 8))
# define OPT_PRINT		(env->options & (1 << 0))
# define OPT_RPRINT		(env->options & (1 << 1))
# define OPT_FREEZE		(env->options & (1 << 2))
# define OPT_OP_CNT		(env->options & (1 << 3))
# define OPT_CMP_CNT	(env->options & (1 << 4))
# define OPT_BASIC		(env->options & (1 << 5))
# define OPT_RBASIC		(env->options & (1 << 6))
# define OPT_JSON		(env->options & (1 << 7))
# define FIRST_ELEM		(env->options & (1 << 8))
# define TOT_OP			(env->tot_op)
# define TOT_CMP		(env->tot_cmp)

typedef struct		s_elem
{
	int				val;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;

typedef struct		s_env
{
	int				index;
	int				options;
	int				a_size;
	int				b_size;
	int				tot_op;
	int				tot_cmp;
	int				pivot;
	int				choice;
	t_elem			*a_first;
	t_elem			*b_first;
	t_elem			*a_last;
	t_elem			*b_last;
}					t_env;

void				op_sa(t_env *env);
void				op_sb(t_env *env);
void				op_ss(t_env *env);
void				op_pa(t_env *env);
void				op_pb(t_env *env);
void				op_ra(t_env *env);
void				op_rb(t_env *env);
void				op_rr(t_env *env);
void				op_rra(t_env *env);
void				op_rrb(t_env *env);
void				op_rrr(t_env *env);

int					get_stack(int ac, char **av, t_env *env);
void				begin_sort(t_env *env);
void				init_op1(t_env *env);

int					is_sorted(t_env *env);
void				free_stack(t_elem **start, t_elem **end);
void				put_stack(char *str, t_elem **start, int nl);
void				put_revstack(char *str, t_elem **start, int nl3);
void				put_stacks(t_env *env);
void				put_pause(t_env *env);
void				put_operation(const char *op, t_env *env);

void				ez_bubble_sort(t_env *env);
void				fifo_bubble_sort(t_env *env);
void				lifo_bubble_sort(t_env *env);
void				push_min(t_env *env);
void				quick_sort(t_env *env);

int					ft_putchar(char c);
void				ft_putnbr(int n);
void				psfd(char const *s, int fd);
int					ft_puterr_fd(char const *s, int fd, int ret);
int					ft_strequ(char const *s1, char const *s2);

#endif
