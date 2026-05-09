/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbulbul <nbulbul@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 18:26:18 by nbulbul           #+#    #+#             */
/*   Updated: 2026/05/09 18:29:22 by nbulbul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	parse_flags(int argc, char **argv, int *start_idx)
{
	int	flag_mode;

	flag_mode = 0;
	while (*start_idx < argc && argv[*start_idx][0] == '-'
		&& argv[*start_idx][1] == '-')
	{
		if (!ft_strcmp(argv[*start_idx], "--simple"))
			flag_mode = 1;
		else if (!ft_strcmp(argv[*start_idx], "--medium"))
			flag_mode = 2;
		else if (!ft_strcmp(argv[*start_idx], "--complex"))
			flag_mode = 3;
		else if (!ft_strcmp(argv[*start_idx], "--bench"))
			flag_mode = 3;
		else if (ft_strcmp(argv[*start_idx], "--adaptive"))
			return (-1);
		(*start_idx)++;
	}
	return (flag_mode);
}

void	run_algorithm(t_node **a, t_node **b, t_bench *bench, int flag_mode)
{
	if (flag_mode == 1)
	{
		bench->algorithm = "Insertion";
		bench->big_o = "O(n^2)";
		insertion_sort(a, b, bench);
	}
	else if (flag_mode == 2)
	{
		bench->algorithm = "Chunk";
		bench->big_o = "O(n√n)";
		chunk_sort(a, b, find_root(stack_size(*a)), bench);
	}
	else if (flag_mode == 3)
	{
		bench->algorithm = "Radix";
		bench->big_o = "O(n*k)";
		radix_sort(a, b, bench);
	}
	else
	{
		bench->algorithm = "Adaptive";
		adaptive_sort_process(a, b, bench);
	}
}

int	setup(t_ctx *c)
{
	c->start_idx = 1;
	c->flag_mode = parse_flags(c->argc, c->argv, &c->start_idx);
	if (c->flag_mode == -1 || c->start_idx == c->argc)
		return (write(2, "Error\n", 6), 1);
	*(c->a) = create_stack(c->argc - c->start_idx + 1, &c->argv[c->start_idx
			- 1]);
	if (!*(c->a))
		return (1);
	assign_index(*(c->a));
	return (0);
}

void	cleanup(t_node *a, t_node *b, t_bench *bench, char **argv)
{
	if (!ft_strcmp(argv[1], "--bench"))
		print_bench(bench);
	free_stack(&a);
	free_stack(&b);
}
