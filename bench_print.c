/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbulbul <nbulbul@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:34:11 by nbulbul           #+#    #+#             */
/*   Updated: 2026/05/09 17:02:04 by nbulbul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_bench(t_bench *bench)
{
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->total_ops = 0;
	bench->disorder_percent = 0;
	bench->algorithm = 0;
	bench->big_o = 0;
}

static void	print_strategy(t_bench *b)
{
	putstr("[bench] strategy: ");
	if (b->algorithm)
		putstr(b->algorithm);
	else
		putstr("Unknown");
	putstr(" / ");
	if (b->big_o)
		putstr(b->big_o);
	else
		putstr("Unknown");
	write(2, "\n", 1);
}

static void	print_push_swap_ops(t_bench *b)
{
	putstr("[bench] sa: ");
	putnbr(b->sa);
	putstr(" sb: ");
	putnbr(b->sb);
	putstr(" ss: ");
	putnbr(b->ss);
	putstr(" pa: ");
	putnbr(b->pa);
	putstr(" pb: ");
	putnbr(b->pb);
	write(2, "\n", 1);
}

static void	print_rotate_ops(t_bench *b)
{
	putstr("[bench] ra: ");
	putnbr(b->ra);
	putstr(" rb: ");
	putnbr(b->rb);
	putstr(" rr: ");
	putnbr(b->rr);
	putstr(" rra: ");
	putnbr(b->rra);
	putstr(" rrb: ");
	putnbr(b->rrb);
	putstr(" rrr: ");
	putnbr(b->rrr);
	write(2, "\n", 1);
}

void	print_bench(t_bench *b)
{
	putstr("[bench] disorder: ");
	putnbr(b->disorder_percent);
	putstr(".00%\n");
	print_strategy(b);
	putstr("[bench] total_ops: ");
	putnbr(b->total_ops);
	write(2, "\n", 1);
	print_push_swap_ops(b);
	print_rotate_ops(b);
}
