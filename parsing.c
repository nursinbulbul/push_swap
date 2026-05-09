/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykale <aykale@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:49:42 by aykale            #+#    #+#             */
/*   Updated: 2026/05/09 15:49:42 by aykale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicate(t_node *a)
{
	t_node	*tmp;
	t_node	*check;

	if (!a)
		return (0);
	tmp = a;
	while (tmp)
	{
		check = tmp->next;
		while (check)
		{
			if (tmp->value == check->value)
				return (1);
			check = check->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

static void	handle_error(t_node **stack)
{
	free_stack(stack);
	error_exit();
}

static int	get_next_number(char **str, t_node **stack)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	if (**str < '0' || **str > '9')
		handle_error(stack);
	while (**str >= '0' && **str <= '9')
	{
		result = result * 10 + (**str - '0');
		if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
			handle_error(stack);
		(*str)++;
	}
	return ((int)(result * sign));
}

static void	parse_string_to_stack(t_node **stack, char *str)
{
	int		value;
	t_node	*node;

	while (*str)
	{
		while (*str == ' ' || (*str >= 9 && *str <= 13))
			str++;
		if (!*str)
			break ;
		value = get_next_number(&str, stack);
		node = new_node(value);
		if (!node)
			handle_error(stack);
		add_back(stack, node);
	}
}

t_node	*create_stack(int argc, char **argv)
{
	t_node	*stack;
	int		i;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		parse_string_to_stack(&stack, argv[i]);
		i++;
	}
	if (has_duplicate(stack))
		handle_error(&stack);
	return (stack);
}
