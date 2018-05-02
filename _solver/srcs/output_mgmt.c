/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_mgmt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 13:47:44 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/27 13:47:46 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		put_operation(const char *op, t_env *env)
{
	if (!OPT_JSON)
	{
		((TOT_OP) != 1 && !OPT_FREEZE) ? ft_putchar(32) : 0;
		psfd(op, 1);
		(OPT_FREEZE) ? put_pause(env) : 0;
		//ft_putchar(10);
	}
	else
	{
		FIRST_ELEM ? ft_putchar(',') : 0;
		psfd("{\"op\":\"", 1);
		psfd(op, 1);
		put_stack("\",\"a\":[", &(env->a_first), 0);
		put_stack("],\"b\":[", &(env->b_first), 0);
		psfd("]}", 1);
		!FIRST_ELEM ? SET_FIRST : 0;
	}
}

void		put_stack(char *str, t_elem **start, int nl)
{
	t_elem	*tmp;

	tmp = *start;
	psfd(str, 1);
	while (tmp)
	{
		if (tmp != *start)
			nl ? psfd(" ", 1) : psfd(", ", 1);
		ft_putnbr(tmp->val);
		tmp = tmp->next;
	}
	nl ? ft_putchar('\n') : 0;
}

void		put_revstack(char *str, t_elem **end, int nl)
{
	t_elem	*tmp;

	tmp = *end;
	psfd(str, 1);
	while (tmp)
	{
		(tmp == *end) ? 0 : ft_putchar(32);
		ft_putnbr(tmp->val);
		tmp = tmp->prev;
	}
	nl ? ft_putchar('\n') : 0;
}

void		put_pause(t_env *env)
{
	char	c[1];

	ft_putchar('\n');
	read(0, &c, 1);
	if (OPT_RPRINT)
		put_revstack("Stack A: ", &(env->a_last), 1);
	else
		put_stack("Stack A: ", &(env->a_first), 1);
	if (OPT_RPRINT)
		put_revstack("Stack B: ", &(env->b_last), 1);
	else
		put_stack("Stack B: ", &(env->b_first), 1);
	!OPT_JSON ? ft_putchar('\n') : 0;
}

void		put_stacks(t_env *env)
{
	if (OPT_RPRINT)
		put_revstack("Stack A: ", &(env->a_last), 1);
	else
		put_stack("Stack A: ", &(env->a_first), 1);
	if (OPT_RPRINT)
		put_revstack("Stack B: ", &(env->b_last), 1);
	else
		put_stack("Stack B: ", &(env->b_first), 1);
}
