/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: nbulbul <nbulbul@student.42kocaeli.com.    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2026/05/09 15:27:17 by nbulbul           #+#    #+#             */
/*   Updated: 2026/05/09 15:27:17 by nbulbul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	pb(t_node **a, t_node **b)
{
	t_node *temp;

	if (!a || !*a)
		return ;

	temp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;

	temp->next = *b;
	if (*b)
		(*b)->prev = temp;

	temp->prev = NULL;
	*b = temp;
}

void	pa(t_node **a, t_node **b)
{
	t_node *temp;

	if (!b || !*b)
		return ;

	temp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;

	temp->next = *a;
	if (*a)
		(*a)->prev = temp;

	temp->prev = NULL;
	*a = temp;
}