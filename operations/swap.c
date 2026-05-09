/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: nbulbul <nbulbul@student.42kocaeli.com.    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2026/05/09 15:29:50 by nbulbul           #+#    #+#             */
/*   Updated: 2026/05/09 15:29:50 by nbulbul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sa(t_node **a)
{
	t_node *first;
	t_node *second;

	if (!a || !*a || !(*a)->next)
		return ;

	first = *a;
	second = first->next;

	first->next = second->next;

	if (second->next)
		second->next->prev = first;

	second->next = first;
	first->prev = second;
	second->prev = NULL;

	*a = second;
}

void	sb(t_node **b)
{
	t_node *first;
	t_node *second;

	if (!b || !*b || !(*b)->next)
		return ;

	first = *b;
	second = first->next;

	first->next = second->next;
	if (second->next)
		second->next->prev = first;

	second->next = first;
	first->prev = second;
	second->prev = NULL;

	*b = second;
}

void	ss(t_node **a, t_node **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}
