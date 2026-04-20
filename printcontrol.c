#include "push_swap.h"

void	exec_sa(t_node **a)
{
	sa(a);
	write(1, "sa\n", 3);
}

void	exec_sb(t_node **b)
{
	sb(b);
	write(1, "sb\n", 3);
}


void	exec_ra(t_node **a)
{
	ra(a);
	write(1, "ra\n", 3);
}

void	exec_rb(t_node **b)
{
	rb(b);
	write(1, "rb\n", 3);
}


void	exec_rra(t_node **a)
{
	rra(a);
	write(1, "rra\n", 4);
}

void	exec_rrb(t_node **b)
{
	rrb(b);
	write(1, "rrb\n", 4);
}
