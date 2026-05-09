/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbulbul <nbulbul@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:24:31 by nbulbul           #+#    #+#             */
/*   Updated: 2026/05/09 15:38:26 by nbulbul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min_to_top(t_node **a, t_bench *bench)
{
	int	min_index;
	int	size;
	int	moves;

	min_index = get_min_index(*a);
	size = stack_size(*a);
	if (min_index <= size / 2)
	{
		while (min_index > 0)
		{
			exec_ra(a, bench);
			min_index--;
		}
	}
	else
	{
		moves = size - min_index;
		while (moves > 0)
		{
			exec_rra(a, bench);
			moves--;
		}
	}
}

void	insertion_sort(t_node **a, t_node **b, t_bench *bench)
{
	int	size;
	int	i;

	if (!a || !*a)
		return ;
	size = stack_size(*a);
	i = 0;
	while (i < size)
	{
		move_min_to_top(a, bench);
		exec_pb(a, b, bench);
		i++;
	}
	while (*b)
	{
		exec_pa(a, b, bench);
	}
}
