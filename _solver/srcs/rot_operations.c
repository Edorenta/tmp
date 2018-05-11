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

	if (++OP && A1 && (A1)->next)
	{
		new_end = A1;
		A1 = A2;
		A1->prev = NULL;
		new_end->prev = A4;
		new_end->next = NULL;
		A4->next = new_end;
		A4 = new_end;
		put_operation("ra", env);
	}
}

void	op_rb(t_env *env)
{
	t_elem	*new_end;

	if (++OP && B1 && (B1)->next)
	{
		new_end = B1;
		B1 = B2;
		B1->prev = NULL;
		new_end->prev = B4;
		new_end->next = NULL;
		B4->next = new_end;
		B4 = new_end;
		put_operation("rb", env);
	}
}

void	op_rr(t_env *env)
{
	t_elem	*new_end;

	if (++OP && A1 && A2)
	{
		new_end = A1;
		A1 = A2;
		A1->prev = NULL;
		new_end->prev = A4;
		new_end->next = NULL;
		A4->next = new_end;
		A4 = new_end;
	}
	if (B1 && B2)
	{
		new_end = B1;
		B1 = B2;
		B1->prev = NULL;
		new_end->prev = B4;
		new_end->next = NULL;
		B4->next = new_end;
		B4 = new_end;
	}
	put_operation("rr", env);
}
