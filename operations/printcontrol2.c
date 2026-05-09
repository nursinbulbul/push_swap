/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printcontrol2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbulbul <nbulbul@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 16:47:29 by nbulbul           #+#    #+#             */
/*   Updated: 2026/05/09 16:48:14 by nbulbul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_rra(t_node **a, t_bench *bench)
{
	rra(a);
	write(1, "rra\n", 4);
	bench->rra++;
	bench->total_ops++;
}

void	exec_rrb(t_node **b, t_bench *bench)
{
	rrb(b);
	write(1, "rrb\n", 4);
	bench->rrb++;
	bench->total_ops++;
}

void	exec_pa(t_node **a, t_node **b, t_bench *bench)
{
	pa(a, b);
	write(1, "pa\n", 3);
	bench->pa++;
	bench->total_ops++;
}

void	exec_pb(t_node **a, t_node **b, t_bench *bench)
{
	pb(a, b);
	write(1, "pb\n", 3);
	bench->pb++;
	bench->total_ops++;
}
