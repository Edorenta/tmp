/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:12:45 by pde-rent          #+#    #+#             */
/*   Updated: 2018/08/20 05:16:05 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tffront(t_env *env, int pos)
{
	while (pos--)
		op_ra(env);
	op_pb(env);
}

void	tfback(t_env *env, int pos)
{
	pos = env->a_size - pos;
	while (pos--)
		op_rra(env);
	op_pb(env);
}

void	push_min(t_env *env)
{
	int		min;
	int		i;
	int		pos;
	t_elem	*tmp;

	while (!is_sorted(env) && env->a_first && env->a_first->next)
	{
		i = 0;
		pos = 0;
		tmp = env->a_first;
		min = tmp->val;
		while (tmp->next)
		{
			tmp = tmp->next;
			++i;
			if (tmp->val < min && (pos = i))
				min = tmp->val;
		}
		(pos <= env->a_size / 2) ? tffront(env, pos) : tfback(env, pos);
	}
	while (env->b_first)
		op_pa(env);
}
