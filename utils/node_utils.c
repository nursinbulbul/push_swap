/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykale <aykale@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:52:57 by aykale            #+#    #+#             */
/*   Updated: 2026/05/09 15:52:57 by aykale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	assign_index(t_node *stack)
{
	t_node	*i;
	t_node	*j;
	int		rank;

	if (!stack)
		return ;
	i = stack;
	while (i)
	{
		rank = 0;
		j = stack;
		while (j)
		{
			if (j->value < i->value)
				rank++;
			j = j->next;
		}
		i->index = rank;
		i = i->next;
	}
}

int	find_max_index_position(t_node *b)
{
	int	max;
	int	pos;
	int	max_pos;

	if (!b)
		return (-1);
	max = b->index;
	pos = 0;
	max_pos = 0;
	while (b)
	{
		if (b->index > max)
		{
			max = b->index;
			max_pos = pos;
		}
		pos++;
		b = b->next;
	}
	return (max_pos);
}

int	get_min_index(t_node *a)
{
	int	min;
	int	index;
	int	i;

	if (!a)
		return (0);
	min = a->value;
	index = 0;
	i = 0;
	while (a)
	{
		if (a->value < min)
		{
			min = a->value;
			index = i;
		}
		a = a->next;
		i++;
	}
	return (index);
}
