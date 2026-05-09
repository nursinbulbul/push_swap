/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbulbul <nbulbul@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:24:49 by nbulbul           #+#    #+#             */
/*   Updated: 2026/05/09 15:38:29 by nbulbul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_node *a)
{
	int	max;
	int	bits;

	max = 0;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

int	get_bit(int index, int i)
{
	return ((index >> i) % 2);
}

void	process_bit(t_node **a, t_node **b, int size, int bit_index,
		t_bench *bench)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (get_bit((*a)->index, bit_index) == 1)
			exec_ra(a, bench);
		else
			exec_pb(a, b, bench);
		j++;
	}
	while (*b)
		exec_pa(a, b, bench);
}

void	radix_sort(t_node **a, t_node **b, t_bench *bench)
{
	int	max_bits;
	int	i;
	int	size;

	if (!a || !*a)
		return ;
	size = stack_size(*a);
	max_bits = get_max_bits(*a);
	i = 0;
	while (i < max_bits)
	{
		process_bit(a, b, size, i, bench);
		i++;
	}
}
