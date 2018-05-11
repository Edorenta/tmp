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
	t_elem	*tmp;

	i = 0;
	tmp = B2;
	if (A1->val > B1->val && A1->val < B4->val)
		return ;
	while (tmp && (tmp->val > A1->val || tmp->prev->val < A1->val))
	{
		i++;
		tmp = tmp->next;
	}
	if (i < B_SIZE / 2)
		while (B1->val > A1->val || B4->val < A1->val)
			op_rb(env);
	else
		while (B1->val > A1->val || B4->val < A1->val)
			op_rrb(env);
}

static void	optimize_order(t_env *env)
{
	int		i;
	t_elem	*tmp;

	i = 0;
	tmp = B1;
	if (!tmp)
		return ;
	while (tmp->next && tmp->val > tmp->next->val && ++i)
		tmp = tmp->next;
	if (!tmp)
		return ;
	if (i > B_SIZE / 2)
		while (B4->val > B1->val)
			op_rrb(env);
	else
		while (B4->val > B1->val)
			op_rb(env);
}

static void	push_to_b(t_env *env)
{
	int		val;
	int		done;
	t_elem	*tmp;

	done = 0;
	if (A1 && A2)
		if (A1->val > A2->val)
			op_sa(env);
	tmp = B1;
	val = A1->val;
	while (tmp && val < tmp->val)
		tmp = tmp->next;
	if (!tmp && !done && ++done)
		optimize_order(env);
	tmp = B1;
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
	if (A2 && A1->val > A2->val)
		op_sa(env);
	if (A3 && A4->val < A3->val)
	{
		op_rra(env);
		while (A3 && A4->val < 
			A3->val)
		{
			op_pb(env);
			op_rb(env);
			op_rra(env);
		}
		op_rra(env);
		op_sa(env);
		while (B1)
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
	while (A4->val < A1->val)
	{
		if (A1->val > A2->val && A4->val != A2->val)
			op_sa(env);
		op_rra(env);
		if (A1->val > A2->val && A4->val != A2->val)
			op_sa(env);
		while (A2 && A4->val > A1->val && A4->val < A2->val)
		{
			push_to_b(env);
			op_rra(env);
			if (A1->val > A2->val && A4->val != A2->val)
				op_sa(env);
		}
	}
	while (B1)
	{
		op_pa(env);
		if (A1->val > A2->val && A4->val != A2->val)
			op_sa(env);
	}
	init_op2(env);
}
