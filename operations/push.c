/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykale <aykale@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:48:59 by aykale            #+#    #+#             */
/*   Updated: 2026/05/09 15:48:59 by aykale           ###   ########.fr       */
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