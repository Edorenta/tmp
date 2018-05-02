/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 12:17:53 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/29 12:17:56 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rra(t_env *env)
{
	t_elem	*new_start;

	if (++(TOT_OP) && env->a_first && env->a_first->next)
	{
		new_start = env->a_last;
		env->a_last = env->a_last->prev;
		env->a_last->next = NULL;
		new_start->next = env->a_first;
		new_start->prev = NULL;
		env->a_first->prev = new_start;
		env->a_first = new_start;
		put_operation("rra", env);
	}
}

void	op_rrb(t_env *env)
{
	t_elem	*new_start;

	if (++(TOT_OP) && env->b_first && env->b_first->next)
	{
		new_start = env->b_last;
		env->b_last = env->b_last->prev;
		env->b_last->next = NULL;
		new_start->next = env->b_first;
		new_start->prev = NULL;
		env->b_first->prev = new_start;
		env->b_first = new_start;
		put_operation("rrb", env);
	}
}

void	op_rrr(t_env *env)
{
	t_elem	*new_start;

	if (++(TOT_OP) && env->a_first && env->a_first->next)
	{
		new_start = env->a_last;
		env->a_last = env->a_last->prev;
		env->a_last->next = NULL;
		new_start->next = env->a_first;
		new_start->prev = NULL;
		env->a_first->prev = new_start;
		env->a_first = new_start;
	}
	if (env->b_first && env->b_first->next)
	{
		new_start = env->b_last;
		env->b_last = env->b_last->prev;
		env->b_last->next = NULL;
		new_start->next = env->b_first;
		new_start->prev = NULL;
		env->b_first->prev = new_start;
		env->b_first = new_start;
	}
	put_operation("rrr", env);
}
