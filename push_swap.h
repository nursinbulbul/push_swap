/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykale <aykale@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:49:51 by aykale            #+#    #+#             */
/*   Updated: 2026/05/09 15:49:51 by aykale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_bench
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		total_ops;
	int		disorder_percent;
	char	*algorithm;
	char	*big_o;
}	t_bench;

typedef struct s_ctx
{
	t_node	**a;
	t_node	**b;
	t_bench	*bench;
	int		flag_mode;
	int		start_idx;
	int		argc;
	char	**argv;
}	t_ctx;

void	print_bench(t_bench *b);
void	init_bench(t_bench *bench);
t_node	*create_stack(int argc, char **argv);
int		ft_atoi_safe(char *str);
int		has_duplicate(t_node *a);
void	error_exit(void);
t_node	*new_node(int value);
void	assign_index(t_node *stack);
int		find_max_index_position(t_node *b);
void	add_back(t_node **stack, t_node *new);
int		stack_size(t_node *a);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
void	exec_sa(t_node **a, t_bench *bench);
void	exec_sb(t_node **b, t_bench *bench);
void	exec_ra(t_node **a, t_bench *bench);
void	exec_rb(t_node **b, t_bench *bench);
void	exec_rra(t_node **a, t_bench *bench);
void	exec_rrb(t_node **b, t_bench *bench);
void	exec_pa(t_node **a, t_node **b, t_bench *bench);
void	exec_pb(t_node **a, t_node **b, t_bench *bench);
void	free_stack(t_node **a);
void	insertion_sort(t_node **a, t_node **b, t_bench *bench);
void	chunk_sort(t_node **a, t_node **b, int range, t_bench *bench);
void	push_chunks_to_b(t_node **a, t_node **b, int range, t_bench *bench);
void	push_back_to_a(t_node **a, t_node **b, t_bench *bench);
int		get_bit(int index, int i);
int		get_max_bits(t_node *a);
void	process_bit(t_node **a, t_node **b, int bit_index, t_bench *bench);
void	radix_sort(t_node **a, t_node **b, t_bench *bench);
int		find_root(int total_len);
void	adaptive_sort_process(t_node **a, t_node **b, t_bench *bench);
double	measure_disorder_process(t_node *stack);
int		is_sorted(t_node *stack);
int		get_min_index(t_node *a);
void	bring_to_top_a(t_node **a, int pos, t_bench *bench);
void	bring_to_top_b(t_node **b, int pos, t_bench *bench);
void	putnbr(int n);
void	putstr(char *s);
void	run_algorithm(t_node **a, t_node **b, t_bench *bench, int flag_mode);
int		setup(t_ctx *c);
void	cleanup(t_node *a, t_node *b, t_bench *bench, char **argv);
void	sort_five(t_node **a, t_node **b, t_bench *bench);
void	sort_three(t_node **a, t_bench *bench);
void	sort_two(t_node **a, t_bench *bench);
void	move_min_to_top(t_node **a, t_bench *bench);
#endif