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
		tmp = A1;
		while (++CMP && tmp->next && tmp->val < tmp->next->val)
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
		while (++CMP && A2 && A1->val < A2->val)
			op_pb(env);
		op_sa(env);
		if (++CMP && B1 && B1->val > A1->val)
		{
			op_ra(env);
			while (++CMP && B1 && B1->val > A4->val)
				op_pa(env);
			op_rra(env);
		}
	}
	while (B1)
		op_pa(env);
}

static void		lifo_bubble_sort2(t_env *env)
{
	if (++CMP && A1->val > A2->val)
		op_sa(env);
	if (++CMP && B1 && B1->val > A1->val)
	{
		op_ra(env);
		while (++CMP && B1 && B1->val > A4->val)
			op_pa(env);
		op_rra(env);
	}
}

void			lifo_bubble_sort(t_env *env)
{
	while (!is_sorted(env))
	{
		while (++CMP && A1->val < A4->val)
		{
			lifo_bubble_sort2(env);
			op_pb(env);
		}
		while (A4->val < A1->val && ++CMP)
		{
			while (++CMP && B1 && B1->val > A4->val)
				op_pa(env);
			op_rra(env);
			while (++CMP && A1->val < A4->val)
			{
				lifo_bubble_sort2(env);
				op_pb(env);
			}
		}
	}
	while (B1)
		op_pa(env);
}
