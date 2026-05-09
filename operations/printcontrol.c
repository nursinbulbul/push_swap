/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printcontrol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykale <aykale@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:48:48 by aykale            #+#    #+#             */
/*   Updated: 2026/05/09 15:48:48 by aykale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_sa(t_node **a, t_bench *bench)
{
	sa(a);
	write(1, "sa\n", 3);
	bench->sa++;
	bench->total_ops++;
}

void	exec_sb(t_node **b, t_bench *bench)
{
	sb(b);
	write(1, "sb\n", 3);
	bench->sb++;
	bench->total_ops++;
}

void	exec_ra(t_node **a, t_bench *bench)
{
	ra(a);
	write(1, "ra\n", 3);
	bench->ra++;
	bench->total_ops++;
}

void	exec_rb(t_node **b, t_bench *bench)
{
	rb(b);
	write(1, "rb\n", 3);
	bench->rb++;
	bench->total_ops++;
}

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
