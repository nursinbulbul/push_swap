/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykale <aykale@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:48:31 by aykale            #+#    #+#             */
/*   Updated: 2026/05/09 15:48:31 by aykale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	select_strategy(t_node **a, t_node **b,
			t_bench *bench, double disorder)
{
	int	number;

	number = stack_size(*a);
	if (disorder < 0.2)
	{
		bench->big_o = "O(n^2)";
		selection_sort(a, b, bench);
	}
	else if (disorder < 0.5)
	{
		bench->big_o = "O(n√n)";
		chunk_sort(a, b, find_root(number), bench);
	}
	else
	{
		bench->big_o = "O(n*k)";
		radix_sort(a, b, bench);
	}
}

void	adaptive_sort_process(t_node **a, t_node **b, t_bench *bench)
{
	double	disorder;

	if (!a || !*a || is_sorted(*a))
		return ;
	disorder = measure_disorder_process(*a);
	bench->disorder_percent = (int)(disorder * 100);
	select_strategy(a, b, bench, disorder);
}

static int	count_inversions(t_node *stack)
{
	int		inversions;
	t_node	*i;
	t_node	*j;

	inversions = 0;
	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->index > j->index)
				inversions++;
			j = j->next;
		}
		i = i->next;
	}
	return (inversions);
}

double	measure_disorder_process(t_node *stack)
{
	int	inversions;
	int	number;

	if (!stack)
		return (0.0);
	number = stack_size(stack);
	if (number < 2)
		return (0.0);
	inversions = count_inversions(stack);
	return ((double)inversions / ((double)number * (number - 1) / 2.0));
}
