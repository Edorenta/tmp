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
	t_elem	*tmp;

	i = 0;
	tmp = B2;
	if (++CMP && A1->val > B1->val && A1->val < B4->val)
		return ;
	while (++CMP && tmp && (tmp->val > A1->val || tmp->prev->val < A1->val))
	{
		i++;
		tmp = tmp->next;
	}
	if (i < B_SIZE / 2)
		while (++CMP && (B1->val > A1->val || B4->val < A1->val))
			op_rb(env);
	else
		while (++CMP && (B1->val > A1->val || B4->val < A1->val))
			op_rrb(env);
}

static void	optimize_order(t_env *env)
{
	int		i;
	t_elem	*tmp;

	i = 0;
	tmp = B1;
	if (tmp)
	{
		while (++CMP && tmp->next && tmp->val > tmp->next->val && ++i)
			tmp = tmp->next;
		if (!tmp)
			return ;
		if (i > B_SIZE / 2)
			while (++CMP && B4->val > B1->val)
				op_rrb(env);
		else
			while (++CMP && B4->val > B1->val)
				op_rb(env);
	}
}

static void	push_to_b(t_env *env)
{
	int		val;
	int		done;
	t_elem	*tmp;

	done = 0;
	if (++CMP && A1 && A2)
		if (++CMP && A1->val > A2->val)
			op_sa(env);
	tmp = B1;
	val = A1->val;
	while (++CMP && tmp && val < tmp->val)
		tmp = tmp->next;
	if (!tmp && !done && ++done)
		optimize_order(env);
	tmp = B1;
	while (++CMP && tmp && val > tmp->val)
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

	split = 2 + (A_SIZE / 100);
	tmp = A1;
	while (tmp->next)
	{
		i = 0;
		tmp2 = A1;
		while (tmp2)
		{
			if (tmp2->val < tmp->val)
				i++;
			if (i > (A_SIZE + 1) / split)
				break ;
			tmp2 = tmp2->next;
		}
		if (i == (A_SIZE + 1) / split)
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
		PIVOT = choose_pivot(env);
		while (++CMP && A1->val < PIVOT)
			push_to_b(env);
		while (1)
		{
			tmp = A1;
			while (++CMP && tmp && tmp->val >= PIVOT)
				tmp = tmp->next;
			if (!tmp)
				break ;
			while (++CMP && A1->val < PIVOT)
				push_to_b(env);
			if (++CMP && A2 && A1->val > A2->val && A2->val > PIVOT)
				op_sa(env);
			(!is_sorted(env)) ? op_ra(env) : 0;
		}
	}
	optimize_order(env);
	while (B1)
		op_pa(env);
}
