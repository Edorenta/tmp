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

	if (++OP && A1 && A2)
	{
		new_start = A4;
		A4 = A3;
		A4->next = NULL;
		new_start->next = A1;
		new_start->prev = NULL;
		A1->prev = new_start;
		A1 = new_start;
		put_operation("rra", env);
	}
}

void	op_rrb(t_env *env)
{
	t_elem	*new_start;

	if (++OP && B1 && B2)
	{
		new_start = B4;
		B4 = B3;
		B4->next = NULL;
		new_start->next = B1;
		new_start->prev = NULL;
		B1->prev = new_start;
		B1 = new_start;
		put_operation("rrb", env);
	}
}

void	op_rrr(t_env *env)
{
	t_elem	*new_start;

	if (++OP && A1 && A2)
	{
		new_start = A4;
		A4 = A3;
		A4->next = NULL;
		new_start->next = A1;
		new_start->prev = NULL;
		A1->prev = new_start;
		A1 = new_start;
	}
	if (B1 && B2)
	{
		new_start = B4;
		B4 = B3;
		B4->next = NULL;
		new_start->next = B1;
		new_start->prev = NULL;
		B1->prev = new_start;
		B1 = new_start;
	}
	put_operation("rrr", env);
}
