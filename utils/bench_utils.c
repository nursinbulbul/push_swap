/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbulbul <nbulbul@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:00:28 by nbulbul           #+#    #+#             */
/*   Updated: 2026/05/09 17:05:09 by nbulbul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	write_num_buf(char *buf, int n, int *i)
{
	while (n > 0)
	{
		buf[--(*i)] = (n % 10) + '0';
		n /= 10;
	}
}

static void	handle_special_numbers(int n)
{
	if (n == 0)
		write(2, "0", 1);
	else if (n == -2147483648)
		write(2, "-2147483648", 11);
}

void	putnbr(int n)
{
	char	buf[12];
	int		i;
	int		tmp;

	if (n == 0 || n == -2147483648)
		return (handle_special_numbers(n));
	tmp = n;
	i = num_len(n);
	buf[i] = '\0';
	if (n < 0)
	{
		write(2, "-", 1);
		n = -n;
	}
	write_num_buf(buf, n, &i);
	write(2, buf, num_len(tmp));
}

void	putstr(char *s)
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
