/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:36:07 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/05 10:36:08 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra(t_env *env)
{
	t_elem	*new_end;

	if (++(TOT_OP) && env->a_first && (env->a_first)->next)
	{
		new_end = env->a_first;
		env->a_first = env->a_first->next;
		env->a_first->prev = NULL;
		new_end->prev = env->a_last;
		new_end->next = NULL;
		env->a_last->next = new_end;
		env->a_last = new_end;
		put_operation("ra", env);
	}
}

void	op_rb(t_env *env)
{
	t_elem	*new_end;

	if (++(TOT_OP) && env->b_first && (env->b_first)->next)
	{
		new_end = env->b_first;
		env->b_first = env->b_first->next;
		env->b_first->prev = NULL;
		new_end->prev = env->b_last;
		new_end->next = NULL;
		env->b_last->next = new_end;
		env->b_last = new_end;
		put_operation("rb", env);
	}
}

void	op_rr(t_env *env)
{
	t_elem	*new_end;

	if (++(TOT_OP) && env->a_first && env->a_first->next)
	{
		new_end = env->a_first;
		env->a_first = env->a_first->next;
		env->a_first->prev = NULL;
		new_end->prev = env->a_last;
		new_end->next = NULL;
		env->a_last->next = new_end;
		env->a_last = new_end;
	}
	if (env->b_first && env->b_first->next)
	{
		new_end = env->b_first;
		env->b_first = env->b_first->next;
		env->b_first->prev = NULL;
		new_end->prev = env->b_last;
		new_end->next = NULL;
		env->b_last->next = new_end;
		env->b_last = new_end;
	}
	put_operation("rr", env);
}
