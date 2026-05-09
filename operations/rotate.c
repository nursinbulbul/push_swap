/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: nbulbul <nbulbul@student.42kocaeli.com.    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2026/05/09 15:29:05 by nbulbul           #+#    #+#             */
/*   Updated: 2026/05/09 15:29:05 by nbulbul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ra(t_node **a)
{
	t_node *first;
	t_node *last;

	if (!a || !*a || !(*a)->next)
		return ;

	first = *a;
	*a = first->next;

	first->next = NULL;
	first->prev = NULL;

	last = *a;
	while (last->next)
		last = last->next;

	last->next = first;
	first->prev = last;
}

void	rb(t_node **b)
{
	t_node *first;
	t_node *last;

	if (!b || !*b || !(*b)->next)
		return ;

	first = *b;
	*b = first->next;

	first->next = NULL;
	first->prev = NULL;

	last = *b;
	while (last->next)
		last = last->next;

	last->next = first;
	first->prev = last;
}

void	rr(t_node **a, t_node **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}