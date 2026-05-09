# ifndef push_swap
# define push_swap

# include <stdlib.h>
# include <unistd.h>

/*STRUCT */

typedef struct s_node
{
	int				value;
	int index;   /*chunk kullanırken index tutmak gerektiği için güncel index tutacak*/
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

void print_bench(t_bench *b);
void	init_bench(t_bench *bench);

/*  PARSING  */

t_node	*create_stack(int argc, char **argv);
int		ft_atoi_safe(char *str);
int		has_duplicate(t_node *a);
void	error_exit(void);

/*  STACK  */

t_node	*new_node(int value);
void assign_index(t_node *stack);
int find_max_index_position(t_node *b);
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

/* EXEC FUNCTIONS */
void	exec_sa(t_node **a, t_bench *bench);
void	exec_sb(t_node **b, t_bench *bench);
void	exec_ra(t_node **a, t_bench *bench);
void	exec_rb(t_node **b, t_bench *bench);
void	exec_rra(t_node **a, t_bench *bench);
void	exec_rrb(t_node **b, t_bench *bench);
void exec_pa(t_node **a, t_node **b, t_bench *bench);
void exec_pb(t_node **a, t_node **b, t_bench *bench);

/*  UTILS  */

void	free_stack(t_node **a);

/* SORTING ALGORITHMS */
void	insertion_sort(t_node **a, t_node **b, t_bench *bench);
void chunk_sort(t_node **a, t_node **b, int range, t_bench *bench);
void push_chunks_to_b(t_node **a, t_node **b, int range, t_bench *bench);
void push_back_to_a(t_node **a, t_node **b, t_bench *bench);
int		get_bit(int index, int i);
int		get_max_bits(t_node *a);
void	process_bit(t_node **a, t_node **b, int size, int bit_index, t_bench *bench);
void	radix_sort(t_node **a, t_node **b, t_bench *bench);
int	find_root(int total_len);
void	adaptive_sort_process(t_node **a, t_node **b, t_bench *bench);
double	measure_disorder_process(t_node *stack);
int is_sorted(t_node *stack);
int	get_min_index(t_node *a);


#endif