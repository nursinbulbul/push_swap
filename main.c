/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbulbul <nbulbul@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:33:58 by nbulbul           #+#    #+#             */
/*   Updated: 2026/05/09 19:12:40 by nbulbul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	t_bench	bench;
	t_ctx	c;

	a = NULL;
	b = NULL;
	init_bench(&bench);
	if (argc < 2)
		return (0);
	c.a = &a;
	c.b = &b;
	c.bench = &bench;
	c.argc = argc;
	c.argv = argv;
	if (setup(&c))
		return (1);
	if (!is_sorted(a))
		run_algorithm(&a, &b, &bench, c.flag_mode);
	cleanup(a, b, &bench, argv);
	return (0);
}
