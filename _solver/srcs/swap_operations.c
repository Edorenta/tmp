/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:35:54 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/05 10:35:57 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_env *env)
{
	t_elem	*tmp1;

	if (A1 && A2)
	{
		tmp1 = A2;
		A2->next
		? A2->next->prev = A1 : 0;
		!(A2->next) ? A4 = A1 : 0;
		A2 = A2->next;
		A1->prev = tmp1;
		tmp1->prev = NULL;
		tmp1->next = A1;
		A1 = tmp1;
		++OP;
		put_operation("sa", env);
	}
}

void	op_sb(t_env *env)
{
	t_elem	*tmp1;

	if (++OP && B1 && B2)
	{
		tmp1 = B2;
		B2->next
		? B2->next->prev = B1 : 0;
		!(B2->next) ? B4 = B1 : 0;
		B2 = B2->next;
		B1->prev = tmp1;
		tmp1->prev = NULL;
		tmp1->next = B1;
		B1 = tmp1;
		put_operation("sb", env);
	}
}

void	op_ss(t_env *env)
{
	t_elem	*tmp1;

	if (++OP && A1 && A2)
	{
		tmp1 = A2;
		A2->next ? A2->next->prev = A1 : 0;
		!(A2->next) ? A4 = A1 : 0;
		A2 = A2->next;
		A1->prev = tmp1;
		tmp1->prev = NULL;
		tmp1->next = A1;
		A1 = tmp1;
	}
	if (B1 && B2 && (tmp1 = B2))
	{
		B2->next ? B2->next->prev = B1 : 0;
		!(B2->next) ? B4 = B1 : 0;
		B2 = B2->next;
		B1->prev = tmp1;
		tmp1->prev = NULL;
		tmp1->next = B1;
		B1 = tmp1;
	}
	put_operation("ss", env);
}

void	op_pa(t_env *env)
{
	t_elem	*tmp1;

	if (++OP && B1)
	{
		tmp1 = B1;
		B1 = tmp1->next;
		(B1) ? B1->prev = NULL : 0;
		!(B1) ? B4 = NULL : 0;
		A1 ? A1->prev = tmp1 : 0;
		tmp1->next = A1;
		A1 = tmp1;
		!((A1)->next) ? A4 = A1 : 0;
		put_operation("pa", env);
		A_SIZE++;
		B_SIZE--;
	}
}

void	op_pb(t_env *env)
{
	t_elem	*tmp1;

	if (++OP && A1)
	{
		tmp1 = A1;
		A1 = tmp1->next;
		(A1) ? A1->prev = NULL : 0;
		!(A1) ? A4 = NULL : 0;
		B1 ? B1->prev = tmp1 : 0;
		tmp1->next = B1;
		B1 = tmp1;
		!(B2) ? B4 = B1 : 0;
		put_operation("pb", env);
		B_SIZE++;
		A_SIZE--;
	}
}
