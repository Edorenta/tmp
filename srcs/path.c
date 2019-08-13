/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 18:26:05 by pde-rent          #+#    #+#             */
/*   Updated: 2018/06/20 18:26:08 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*new_path(t_env *env)
{
	t_path *p;

	(p = (t_path *)malloc(sizeof(t_path)))
	? 0 : put_error(env, "t_path malloc failed");
	p->prev = NULL;
	p->next = NULL;
	p->room = env->start;
	return (p);
}

t_path	*duplicate_path(t_env *env, t_path *path)
{
	t_path *p;
	t_path *new;

	p = path;
	new = new_path(env);
	while (p && p->prev && p->prev->room)
		p = p->prev;
	while (p && p->next)
	{
		p = p->next;
		new = add_path(env, new, p->room);
	}
	return (new);
}

void	del_ant_path(t_path *path)
{
	if (path && path->rooms)
		free(path->rooms);
	// if (path)
	// 	free (path);
}

void	put_ant_path(t_path *path)
{
	if (!path || !path->rooms)
		return ;
	while (p && p->prev)
		p = p->prev;
	while (p && p->room && &(p->room->id[0]))
	{
		if (&(p->room->id[0]))
			p->next ? pstr(1, p->room->id, '-') : pstr(1, p->room->id, '\0');
		p = p->next;
	}
	write(1, "\n", 1);
}
