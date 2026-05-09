/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: nbulbul <nbulbul@student.42kocaeli.com.    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2026/05/09 15:28:18 by nbulbul           #+#    #+#             */
/*   Updated: 2026/05/09 15:28:18 by nbulbul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	rra(t_node **a)
{
	t_node *last;
	t_node *second_last;

	if (!a || !*a || !(*a)->next)
		return ;

	last = *a;
	while (last->next)
		last = last->next;

	second_last = last->prev;

	if (second_last)
		second_last->next = NULL;

	last->next = *a;
	(*a)->prev = last;

	last->prev = NULL;

	*a = last;
}

void	rrb(t_node **b)
{
	t_node *last;
	t_node *second_last;

	if (!b || !*b || !(*b)->next)
		return ;

	last = *b;
	while (last->next)
		last = last->next;

	second_last = last->prev;

	if (second_last)
		second_last->next = NULL;

	last->next = *b;
	(*b)->prev = last;

	last->prev = NULL;

	*b = last;
}

void	rrr(t_node **a, t_node **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}