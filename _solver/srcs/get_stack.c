/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 09:56:43 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 09:56:47 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	free_stack(t_elem **start, t_elem **end)
{
	t_elem	*tmp1;
	t_elem	*tmp2;

	if (start && *start)
	{
		tmp1 = *start;
		while (tmp1->next)
		{
			tmp2 = tmp1;
			tmp1 = tmp1->next;
			free(tmp2);
			tmp2 = NULL;
		}
		free(tmp1);
		tmp1 = NULL;
		*start = NULL;
		end = NULL;
	}
}

int		add_to_stack(t_elem **start, t_elem **end, int nbr)
{
	t_elem	*newby;
	t_elem	*tmp;

	if (!(newby = (t_elem*)malloc(sizeof(*newby))))
		return (-1);
	newby->next = NULL;
	newby->val = nbr;
	newby->prev = *end;
	*end = newby;
	if (*start)
	{
		tmp = *start;
		while (tmp->next && tmp->val != nbr)
			tmp = tmp->next;
		if (tmp->val == nbr)
		{
			free(newby);
			newby = NULL;
			return (-1);
		}
		tmp->next = newby;
	}
	else
		*start = newby;
	return (1);
}

static int	push_to_stack(char *str, t_env *env)
{
	int nbr;

	nbr = 0;
	if (ft_atoi_mod(str, &nbr) < 0 ||
		add_to_stack(&(A1), &(A4), nbr) < 0)
	{
		free_stack(&(A1), &(A4));
		return (-1);
	}
	else if (++A_SIZE)
		return (1);
	return (0);
}

static int	split_push(char *str, int spaces, t_env *env)
{
	char	av[spaces][10];
	char	*p;
	int		i;
	int		j;

	i = 0;
	p = str;
	while (*p)
	{
		while (*p && is_space(*p))
			p++;
		j = -1;
		while (*p && (*p >= '0' && *p <= '9'))
			av[i][++j] = *p++;
		av[i][++j] = '\0';
		dprintf(1, "tok[%d] : %s\n", i, av[i]);
		i++;
	}
	dprintf(1, "tokens: %d theorical: %d\n", i, spaces + 1);
	i = -1;
	while (++i < (spaces + 1))
		push_to_stack(av[i], env);
	return (spaces + 1);
}

int			get_stack(int ac, char **av, t_env *env)
{
	int		i;
	int		j;
	int		spaces;

	i = env->index;
	j = i;
	while (j < ac && i > 0 && av[i])
	{
		//dprintf(1, "ok\n");
		if (!full_digits(av[i]))
			return (-1);
		//dprintf(1, "ok\n");
		spaces = space_in(av[i]);
		//dprintf(1, "ok\n");
		//dprintf(1, "spaces in: %d\n", spaces);
		if (spaces)
		{
			ac += spaces;
			j += split_push(av[i], spaces, env);
			i++;
		}
		else
		{
			//dprintf(1, "av: %s\n", av[i]);
			j += push_to_stack(av[i], env);
			i++;
		}
	}
	//dprintf(1, "pushed to stack: %d\n", j - env->index);
	return (j);
}
