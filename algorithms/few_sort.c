/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   few_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbulbul <nbulbul@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 19:36:40 by nbulbul           #+#    #+#             */
/*   Updated: 2026/05/09 19:41:59 by nbulbul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_node **a, t_bench *bench)
{
	if ((*a)->index > (*a)->next->index)
		exec_sa(a, bench);
}

void	sort_three(t_node **a, t_bench *bench)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first < second && second < third)
		return ;
	if (first > second && second < third && first < third)
		exec_sa(a, bench);
	else if (first > second && second > third)
	{
		exec_sa(a, bench);
		exec_rra(a, bench);
	}
	else if (first > second && second < third && first > third)
		exec_ra(a, bench);
	else if (first < second && second > third && first < third)
	{
		exec_sa(a, bench);
		exec_ra(a, bench);
	}
	else if (first < second && second > third && first > third)
		exec_rra(a, bench);
}

void	sort_five(t_node **a, t_node **b, t_bench *bench)
{
	while (stack_size(*a) > 3)
	{
		move_min_to_top(a, bench);
		exec_pb(a, b, bench);
	}
	sort_three(a, bench);
	while (*b)
		exec_pa(a, b, bench);
}
