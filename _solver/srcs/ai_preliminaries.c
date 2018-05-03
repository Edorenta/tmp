/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preliminaries.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 11:35:11 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/24 11:35:13 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	optimize_rotate(t_env *env)
{
	int		i;
	int		val;
	t_elem	*tmp;

	i = 0;
	val = env->a_first->val;
	tmp = env->b_first->next;
	if (val > env->b_first->val && val < env->b_last->val)
		return ;
	while (tmp && (tmp->val > val || tmp->prev->val < val))
	{
		i++;
		tmp = tmp->next;
	}
	if (i < env->b_size / 2)
		while (env->b_first->val > val || env->b_last->val < val)
			op_rb(env);
	else
		while (env->b_first->val > val || env->b_last->val < val)
			op_rrb(env);
}

static void	optimize_order(t_env *env)
{
	int		i;
	t_elem	*tmp;

	i = 0;
	tmp = env->b_first;
	if (!tmp)
		return ;
	while (tmp->next && tmp->val > tmp->next->val && ++i)
		tmp = tmp->next;
	if (!tmp)
		return ;
	if (i > env->b_size / 2)
		while (env->b_last->val > env->b_first->val)
			op_rrb(env);
	else
		while (env->b_last->val > env->b_first->val)
			op_rb(env);
}

static void	push_to_b(t_env *env)
{
	int		val;
	int		done;
	t_elem	*tmp;

	done = 0;
	if (env->a_first && env->a_first->next)
		if (env->a_first->val > env->a_first->next->val)
			op_sa(env);
	tmp = env->b_first;
	val = env->a_first->val;
	while (tmp && val < tmp->val)
		tmp = tmp->next;
	if (!tmp && !done && ++done)
		optimize_order(env);
	tmp = env->b_first;
	while (tmp && val > tmp->val)
		tmp = tmp->next;
	if (!tmp && !done && ++done)
		optimize_order(env);
	if (!done && ++done)
		optimize_rotate(env);
	op_pb(env);
}

static void	init_op2(t_env *env)
{
	if (env->a_first->next && env->a_first->val > env->a_first->next->val)
		op_sa(env);
	if (env->a_last->prev && env->a_last->val < env->a_last->prev->val)
	{
		op_rra(env);
		while (env->a_last->prev && env->a_last->val < env->a_last->prev->val)
		{
			op_pb(env);
			op_rb(env);
			op_rra(env);
		}
		op_rra(env);
		op_sa(env);
		while (env->b_first)
		{
			op_pa(env);
			op_ra(env);
		}
		op_ra(env);
		op_ra(env);
	}
}

void		init_op1(t_env *env)
{
	while (env->a_last->val < env->a_first->val)
	{
		if (A_FIRST > A_NEXT && A_LAST != A_NEXT)
			op_sa(env);
		op_rra(env);
		if (A_FIRST > A_NEXT && A_LAST != A_NEXT)
			op_sa(env);
		while (env->a_first->next && A_LAST > A_FIRST && A_LAST < A_NEXT)
		{
			push_to_b(env);
			op_rra(env);
			if (A_FIRST > A_NEXT && A_LAST != A_NEXT)
				op_sa(env);
		}
	}
	while (env->b_first)
	{
		op_pa(env);
		if (A_FIRST > A_NEXT && A_LAST != A_NEXT)
			op_sa(env);
	}
	init_op2(env);
}
