/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbulbul <nbulbul@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:34:11 by nbulbul           #+#    #+#             */
/*   Updated: 2026/05/09 15:38:57 by nbulbul          ###   ########.fr       */
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

static int	num_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	putnbr(int n)
{
	char	buf[12];
	int		i;
	int		tmp;

	tmp = n;
	i = num_len(n);
	buf[i] = '\0';
	if (n == 0)
	{
		buf[0] = '0';
		write(2, buf, 1);
		return ;
	}
	if (n == -2147483648)
	{
		write(2, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(2, "-", 1);
		n = -n;
	}
	while (n > 0)
	{
		buf[--i] = (n % 10) + '0';
		n /= 10;
	}
	write(2, buf, num_len(tmp));
}

static void	putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
}

void	print_bench(t_bench *b)
{
	putstr("[bench] disorder: ");
	putnbr(b->disorder_percent);
	putstr(".00%\n");
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
	putstr("[bench] total_ops: ");
	putnbr(b->total_ops);
	write(2, "\n", 1);
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
