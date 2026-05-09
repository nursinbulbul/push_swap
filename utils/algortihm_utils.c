/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algortihm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbulbul <nbulbul@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:30:14 by nbulbul           #+#    #+#             */
/*   Updated: 2026/05/09 16:50:39 by nbulbul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	find_root(int total_len)
{
	int	root;

	if (total_len <= 0)
		return (0);
	root = 1;
	while (root * root <= total_len)
	{
		if (root * root == total_len)
			return (root);
		root++;
	}
	return (root - 1);
}

void	bring_to_top_a(t_node **a, int pos, t_bench *bench)
{
	int	size;

	size = stack_size(*a);
	if (pos <= size / 2)
	{
		while (pos--)
			exec_ra(a, bench);
	}
	else
	{
		pos = size - pos;
		while (pos--)
			exec_rra(a, bench);
	}
}

void	bring_to_top_b(t_node **b, int pos, t_bench *bench)
{
	int	size;

	size = stack_size(*b);
	if (pos <= size / 2)
	{
		while (pos--)
			exec_rb(b, bench);
	}
	else
	{
		pos = size - pos;
		while (pos--)
			exec_rrb(b, bench);
	}
}
