/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 11:30:03 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/24 11:30:06 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					is_sorted(t_env *env)
{
	t_elem	*tmp;

	tmp = env->a_first;
	while (tmp && tmp->next && tmp->val < tmp->next->val)
		tmp = tmp->next;
	if (tmp && tmp->next)
		return (0);
	return (1);
}

void				algo_picker(t_env *env)
{
	void	(*choices[5])(t_env*);

	choices[0] = ez_bubble_sort;
	choices[1] = fifo_bubble_sort;
	choices[2] = lifo_bubble_sort;
	choices[3] = push_min;
	choices[4] = quick_sort;
	if (env->a_first)
		choices[env->choice](env);
}

inline static void	put_tot(t_env *env)
{
	if (OPT_CMP_CNT)
	{
		psfd("Total comparisons:\t", 1);
		ft_putnbr(TOT_CMP);
		ft_putchar('\n');
	}
	if (OPT_OP_CNT)
	{
		psfd("Total operations:\t", 1);
		ft_putnbr(TOT_OP);
		ft_putchar('\n');
	}
}

void				begin_sort(t_env *env)
{
	OPT_JSON ? psfd("{\"Stacks\":[", 1) : 0;
	OPT_JSON ? put_operation("init", env) : 0;
	if (OPT_PRINT || OPT_RPRINT)
	{
		psfd("-------- BEFORE SORT --------\n", 1);
		put_stacks(env);
		ft_putchar('\n');
	}
	env->a_first ? init_op1(env) : 0;
	env->a_first ? algo_picker(env) : 0;
	(OPT_FREEZE || OPT_JSON) ? 0 : ft_putchar('\n');
	if (OPT_PRINT || OPT_RPRINT)
	{
		psfd("\n-------- AFTER SORT -------\n", 1);
		put_stacks(env);
		(OPT_OP_CNT || OPT_CMP_CNT) ? ft_putchar('\n') : 0;
	}
	if (OPT_BASIC || OPT_RBASIC)
		(OPT_RBASIC) ? put_revstack("", &(env->a_last), 1)
		: put_stack("", &(env->a_first), 1);
	free_stack(&(env->a_first), &(env->a_last));
	free_stack(&(env->b_first), &(env->b_last));
	(OPT_OP_CNT || OPT_CMP_CNT) ? put_tot(env) : 0;
	OPT_JSON ? psfd("]}\n", 1) : 0;
}
