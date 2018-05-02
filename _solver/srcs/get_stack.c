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

int		ft_atoi_mod(char *s, int *nbr)
{
	int		nb;
	int		i;
	int		sign;

	nb = 0;
	sign = (s[0] == '-' && s[1]) ? 1 : 0;
	i = sign;
	while (i >= 0 && s[i])
	{
		if (nb == 214748364 && ((sign && s[i] > 56) || (!sign && s[i] > 55)))
			i = -2;
		else if (s[i] < 48 || s[i] > 57 || nb > 214748364)
			i = -2;
		else
		{
			nb = nb * 10 + s[i] - 48;
			i++;
		}
	}
	if (sign)
		nb = -nb;
	*nbr = nb;
	return (i);
}

int		get_stack(int ac, char **av, t_env *env)
{
	int		i;
	int		nbr;

	i = env->index;
	nbr = 0;
	while (i < ac && i > 0)
	{
		if (ft_atoi_mod(av[i], &nbr) < 0)
		{
			i = -1;
			free_stack(&(env->a_first), &(env->a_last));
		}
		else if (add_to_stack(&(env->a_first), &(env->a_last), nbr) < 0)
		{
			i = -1;
			free_stack(&(env->a_first), &(env->a_last));
		}
		else if (++env->a_size)
			++i;
	}
	return (i);
}
