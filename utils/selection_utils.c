/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbulbul <nbulbul@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 19:29:10 by nbulbul           #+#    #+#             */
/*   Updated: 2026/05/11 16:27:48 by nbulbul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_small_sizes(t_node **a, t_node **b, t_bench *bench)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
	{
		bench->algorithm = "Adaptive";
		bench->big_o = "O(1)";
		sort_two(a, bench);
		return (1);
	}
	if (size == 3)
	{
		bench->algorithm = "Adaptive";
		bench->big_o = "O(1)";
		sort_three(a, bench);
		return (1);
	}
	if (size <= 5)
	{
		bench->algorithm = "Adaptive";
		bench->big_o = "O(1)";
		sort_five(a, b, bench);
		return (1);
	}
	return (0);
}

static void	run_big_algorithms(t_node **a, t_node **b, t_bench *bench,
		int flag_mode)
{
	if (flag_mode == 1)
	{
		bench->algorithm = "Selection";
		bench->big_o = "O(n²)";
		selection_sort(a, b, bench);
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
		bench->big_o = "O(n log n)";
		radix_sort(a, b, bench);
	}
	else
	{
		bench->algorithm = "Adaptive";
		adaptive_sort_process(a, b, bench);
	}
}

void	run_algorithm(t_node **a, t_node **b, t_bench *bench, int flag_mode)
{
	bench->disorder_percent = (int)(measure_disorder_process(*a) * 100);
	if (flag_mode == 0 && handle_small_sizes(a, b, bench))
		return ;
	run_big_algorithms(a, b, bench, flag_mode);
}
