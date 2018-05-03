/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:50:48 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/21 15:50:49 by pde-rent         ###   ########.fr       */
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
	if (++TOT_CMP && val > env->b_first->val && val < env->b_last->val)
		return ;
	while (++TOT_CMP && tmp && (tmp->val > val || tmp->prev->val < val))
	{
		i++;
		tmp = tmp->next;
	}
	if (i < env->b_size / 2)
		while (++TOT_CMP && (env->b_first->val > val || env->b_last->val < val))
			op_rb(env);
	else
		while (++TOT_CMP && (env->b_first->val > val || env->b_last->val < val))
			op_rrb(env);
}

static void	optimize_order(t_env *env)
{
	int		i;
	t_elem	*tmp;

	i = 0;
	tmp = env->b_first;
	if (tmp)
	{
		while (++TOT_CMP && tmp->next && tmp->val > tmp->next->val && ++i)
			tmp = tmp->next;
		if (!tmp)
			return ;
		if (i > env->b_size / 2)
			while (++TOT_CMP && env->b_last->val > env->b_first->val)
				op_rrb(env);
		else
			while (++TOT_CMP && env->b_last->val > env->b_first->val)
				op_rb(env);
	}
}

static void	push_to_b(t_env *env)
{
	int		val;
	int		done;
	t_elem	*tmp;

	done = 0;
	if (++TOT_CMP && env->a_first && env->a_first->next)
		if (++TOT_CMP && env->a_first->val > env->a_first->next->val)
			op_sa(env);
	tmp = env->b_first;
	val = env->a_first->val;
	while (++TOT_CMP && tmp && val < tmp->val)
		tmp = tmp->next;
	if (!tmp && !done && ++done)
		optimize_order(env);
	tmp = env->b_first;
	while (++TOT_CMP && tmp && val > tmp->val)
		tmp = tmp->next;
	if (!tmp && !done && ++done)
		optimize_order(env);
	if (!done && ++done)
		optimize_rotate(env);
	op_pb(env);
}

static int	choose_pivot(t_env *env)
{
	int		i;
	int		split;
	t_elem	*tmp;
	t_elem	*tmp2;

	split = (env->a_size <= 400) ? 2 : 7;
	tmp = env->a_first;
	while (tmp->next)
	{
		i = 0;
		tmp2 = env->a_first;
		while (tmp2)
		{
			if (tmp2->val < tmp->val)
				i++;
			if (i > (env->a_size + 1) / split)
				break ;
			tmp2 = tmp2->next;
		}
		if (i == (env->a_size + 1) / split)
			break ;
		tmp = tmp->next;
	}
	return (tmp->val);
}

void		quick_sort(t_env *env)
{
	t_elem	*tmp;

	while (!is_sorted(env))
	{
		env->pivot = choose_pivot(env);
		while (++TOT_CMP && env->a_first->val < env->pivot)
			push_to_b(env);
		while (1)
		{
			tmp = env->a_first;
			while (++TOT_CMP && tmp && tmp->val >= env->pivot)
				tmp = tmp->next;
			if (!tmp)
				break ;
			while (++TOT_CMP && env->a_first->val < env->pivot)
				push_to_b(env);
			if (++TOT_CMP && env->a_first->next && A_FIRST > A_NEXT &&
				A_NEXT > env->pivot)
				op_sa(env);
			(!is_sorted(env)) ? op_ra(env) : 0;
		}
	}
	optimize_order(env);
	while (env->b_first)
		op_pa(env);
}
