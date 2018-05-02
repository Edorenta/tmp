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

	if (env->a_first && A_NEXTF)
	{
		tmp1 = A_NEXTF;
		A_NEXTF->next
		? A_NEXTF->next->prev = env->a_first : 0;
		!(A_NEXTF->next) ? env->a_last = env->a_first : 0;
		A_NEXTF = A_NEXTF->next;
		env->a_first->prev = tmp1;
		tmp1->prev = NULL;
		tmp1->next = env->a_first;
		env->a_first = tmp1;
		++(TOT_OP);
		put_operation("sa", env);
	}
}

void	op_sb(t_env *env)
{
	t_elem	*tmp1;

	if (++(TOT_OP) && env->b_first && B_NEXTF)
	{
		tmp1 = B_NEXTF;
		B_NEXTF->next
		? B_NEXTF->next->prev = env->b_first : 0;
		!(B_NEXTF->next) ? env->b_last = env->b_first : 0;
		B_NEXTF = B_NEXTF->next;
		env->b_first->prev = tmp1;
		tmp1->prev = NULL;
		tmp1->next = env->b_first;
		env->b_first = tmp1;
		put_operation("sb", env);
	}
}

void	op_ss(t_env *env)
{
	t_elem	*tmp1;

	if (++(TOT_OP) && env->a_first && A_NEXTF)
	{
		tmp1 = A_NEXTF;
		A_NEXTF->next ? A_NEXTF->next->prev = env->a_first : 0;
		!(A_NEXTF->next) ? env->a_last = env->a_first : 0;
		A_NEXTF = A_NEXTF->next;
		env->a_first->prev = tmp1;
		tmp1->prev = NULL;
		tmp1->next = env->a_first;
		env->a_first = tmp1;
	}
	if (env->b_first && B_NEXTF && (tmp1 = B_NEXTF))
	{
		B_NEXTF->next ? B_NEXTF->next->prev = env->b_first : 0;
		!(B_NEXTF->next) ? env->b_last = env->b_first : 0;
		B_NEXTF = B_NEXTF->next;
		env->b_first->prev = tmp1;
		tmp1->prev = NULL;
		tmp1->next = env->b_first;
		env->b_first = tmp1;
	}
	put_operation("ss", env);
}

void	op_pa(t_env *env)
{
	t_elem	*tmp1;

	if (++(TOT_OP) && env->b_first)
	{
		tmp1 = env->b_first;
		env->b_first = tmp1->next;
		(env->b_first) ? env->b_first->prev = NULL : 0;
		!(env->b_first) ? env->b_last = NULL : 0;
		env->a_first ? env->a_first->prev = tmp1 : 0;
		tmp1->next = env->a_first;
		env->a_first = tmp1;
		!((env->a_first)->next) ? env->a_last = env->a_first : 0;
		put_operation("pa", env);
		env->a_size++;
		env->b_size--;
	}
}

void	op_pb(t_env *env)
{
	t_elem	*tmp1;

	if (++(TOT_OP) && env->a_first)
	{
		tmp1 = env->a_first;
		env->a_first = tmp1->next;
		(env->a_first) ? env->a_first->prev = NULL : 0;
		!(env->a_first) ? env->a_last = NULL : 0;
		env->b_first ? env->b_first->prev = tmp1 : 0;
		tmp1->next = env->b_first;
		env->b_first = tmp1;
		!(B_NEXTF) ? env->b_last = env->b_first : 0;
		put_operation("pb", env);
		env->b_size++;
		env->a_size--;
	}
}
