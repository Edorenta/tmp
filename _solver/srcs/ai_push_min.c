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
	pos = A_SIZE - pos;
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

	while (!is_sorted(env) && A1 && A2)
	{
		i = 0;
		pos = 0;
		tmp = A1;
		min = tmp->val;
		while (tmp->next)
		{
			tmp = tmp->next;
			++i;
			if (tmp->val < min && (min = tmp->val))
				pos = i;
		}
		(pos <= A_SIZE / 2) ? tffront(env, pos) : tfback(env, pos);
	}
	while (B1)
		op_pa(env);
}
