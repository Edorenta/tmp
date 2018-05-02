/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 11:27:14 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/24 11:27:17 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ez_bubble_sort(t_env *env)
{
	t_elem	*tmp;
	int		i;
	int		step;

	while (1)
	{
		step = 0;
		i = 0;
		tmp = env->a_first;
		while (++TOT_CMP && tmp->next && tmp->val < tmp->next->val)
		{
			++step;
			tmp = tmp->next;
		}
		if (tmp->next)
		{
			while (i++ < step)
				op_ra(env);
			op_sa(env);
			while (step--)
				op_rra(env);
		}
		else
			break ;
	}
}

void			fifo_bubble_sort(t_env *env)
{
	while (!is_sorted(env))
	{
		while (++TOT_CMP && env->a_first->next
			&& env->a_first->val < env->a_first->next->val)
			op_pb(env);
		op_sa(env);
		if (++TOT_CMP && env->b_first && env->b_first->val > env->a_first->val)
		{
			op_ra(env);
			while (++TOT_CMP && env->b_first
				&& env->b_first->val > env->a_last->val)
				op_pa(env);
			op_rra(env);
		}
	}
	while (env->b_first)
		op_pa(env);
}

static void		lifo_bubble_sort2(t_env *env)
{
	if (++TOT_CMP && env->a_first->val > env->a_first->next->val)
		op_sa(env);
	if (++TOT_CMP && env->b_first && env->b_first->val > env->a_first->val)
	{
		op_ra(env);
		while (++TOT_CMP && env->b_first
			&& env->b_first->val > env->a_last->val)
			op_pa(env);
		op_rra(env);
	}
}

void			lifo_bubble_sort(t_env *env)
{
	while (!is_sorted(env))
	{
		while (++TOT_CMP && env->a_first->val < env->a_last->val)
		{
			lifo_bubble_sort2(env);
			op_pb(env);
		}
		while (env->a_last->val < env->a_first->val && ++TOT_CMP)
		{
			while (++TOT_CMP && env->b_first
				&& env->b_first->val > env->a_last->val)
				op_pa(env);
			op_rra(env);
			while (++TOT_CMP && env->a_first->val < env->a_last->val)
			{
				lifo_bubble_sort2(env);
				op_pb(env);
			}
		}
	}
	while (env->b_first)
		op_pa(env);
}
