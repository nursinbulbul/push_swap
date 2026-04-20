#ifndef push_swap
# define push_swap

# include <stdlib.h>
# include <unistd.h>

/*STRUCT */

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

/*  PARSING  */

t_node	*create_stack(int argc, char **argv);
int		ft_atoi_safe(char *str);
int		has_duplicate(t_node *a);
void	error_exit(void);

/*  STACK  */

t_node	*new_node(int value);
void	add_back(t_node **stack, t_node *new);
int		stack_size(t_node *a);

/*  OPERATIONS  */

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

/*  UTILS  */

void	free_stack(t_node *a);

#endif