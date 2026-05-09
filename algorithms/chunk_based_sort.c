/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbulbul <nbulbul@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:23:40 by nbulbul           #+#    #+#             */
/*   Updated: 2026/05/09 16:49:41 by nbulbul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_in_range(t_node *a, int min, int max)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (a->index >= min && a->index <= max)
			return (pos);
		pos++;
		a = a->next;
	}
	return (-1);
}

void	chunk_sort(t_node **a, t_node **b, int range, t_bench *bench)
{
	push_chunks_to_b(a, b, range, bench);
	push_back_to_a(a, b, bench);
}

void	push_chunks_to_b(t_node **a, t_node **b, int range, t_bench *bench)
{
	int	i;
	int	max;
	int	pos;

	i = 0;
	max = range;
	while (*a)
	{
		pos = find_index_in_range(*a, i, max);
		if (pos == -1)
		{
			i += range;
			max += range;
		}
		else
		{
			bring_to_top_a(a, pos, bench);
			exec_pb(a, b, bench);
		}
	}
}

void	push_back_to_a(t_node **a, t_node **b, t_bench *bench)
{
	int	max_pos;

	while (*b)
	{
		max_pos = find_max_index_position(*b);
		bring_to_top_b(b, max_pos, bench);
		exec_pa(a, b, bench);
	}
}
