/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:25:21 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/05 10:25:23 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

inline static int	putuse(int fd)
{
	const char *use = "--- usage ---\n./push_swap [general options](...) "

	"[sorting options](...) [integers](...)\n"
	"  general options:\n"
	"    -p:  prints stack A before and after being sorted ascendingly\n"
	"    -rp: prints stack A before and after being sorted descendingly\n"
	"    -f:  awaits for the user to tap ENTER at each operation\n"
	"    -o:  prints the total number of operations done through sorting\n"
	"    -c:  prints the total number of comparisons done through sorting\n"
	"    -b:  prints only the resulting integers array sorted ascendingly\n"
	"    -rb: prints only the resulting integers array sorted descendingly\n"
	"    -j:  prints -b as JSON on both stacks at each operation\n"
	"  sorting algorithm options:\n"
	"    -s0: basic stack A comparison-only bubble sort\n"
	"    -s1: s0 improvement by caching comparisons in stack B\n"
	"    -s2: s1 improvement by pushing to B from two sided A (min push)\n"
	"    -s3: insertion sort implementation\n"
	"    -s4: quick sort implementation - default parameter";
	return (ft_puterr_fd(use, fd, 0));
}

inline static int	check_input(int ac, char **av)
{
	if (ac < 2)
		return (putuse(1));
	return (1);
}

inline static void	algo_option(int ac, char **av, t_env *env)
{
	(OPT_PRINT && OPT_RPRINT) ? SET_RPRINT : 0;
	if (ac <= env->index)
		return ;
	if (av[env->index][0] == '-' && av[env->index][1] == 's')
	{
		if (IS_SET("-s0") && ++(env->index))
			env->choice = 0;
		else if (IS_SET("-s1") && ++(env->index))
			env->choice = 1;
		else if (IS_SET("-s2") && ++(env->index))
			env->choice = 2;
		else if (IS_SET("-s3") && ++(env->index))
			env->choice = 3;
		else if (IS_SET("-s4") && ++(env->index))
			env->choice = 4;
	}
}

inline static void	get_options(int ac, char **av, t_env *env)
{
	while (ac > env->index)
	{
		if (ft_strequ("-b", av[env->index]) && (env->index)++)
			SET_BASIC;
		else if (ft_strequ("-rb", av[env->index]) && ++(env->index))
			SET_RBASIC;
		else if (ft_strequ("-p", av[env->index]) && ++(env->index))
			SET_PRINT;
		else if (ft_strequ("-rp", av[env->index]) && ++(env->index))
			SET_RPRINT;
		else if (ft_strequ("-f", av[env->index]) && ++(env->index))
			SET_FREEZE;
		else if (ft_strequ("-o", av[env->index]) && ++(env->index))
			SET_OP_CNT;
		else if (ft_strequ("-c", av[env->index]) && ++(env->index))
			SET_CMP_CNT;
		else if (ft_strequ("-b", av[env->index]) && ++(env->index))
			SET_BASIC;
		else if (ft_strequ("-rc", av[env->index]) && ++(env->index))
			SET_RBASIC;
		else if (ft_strequ("-j", av[env->index]) && ++(env->index))
			SET_JSON;
		else
			break ;
	}
}

int					main(int ac, char **av)
{
	t_env	env;

	env.a_first = NULL;
	env.b_first = NULL;
	env.a_last = NULL;
	env.b_last = NULL;
	env.index = 1;
	env.a_size = 0;
	env.b_size = 0;
	env.tot_op = 0;
	env.tot_cmp = 0;
	env.options = 0;
	env.choice = 4;
	check_input(ac, av);
	get_options(ac, av, &env);
	algo_option(ac, av, &env);
	if (get_stack(ac, av, &env) >= 0)
		begin_sort(&env);
	else
	{
		psfd("Error\n", 2);
		putuse(2);
	}
	return (0);
}
