

#include "push_swap.h"

void	adaptive_sort_process(t_node **a, t_node **b, t_bench *bench)
{
	double	disorder;
	int		number;

	if (!a || !*a || is_sorted(*a))
		return ;
	number = stack_size(*a);
	disorder = measure_disorder_process(*a);
	if (disorder < 0.2)
		insertion_sort(a, b, bench);
	else if (disorder < 0.5)
		chunk_sort(a, b, find_root(number), bench);
	else
		radix_sort(a, b, bench);
}



static int	count_inversions(t_node *stack)
{
	int		inversions;
	t_node	*i;
	t_node	*j;

	inversions = 0;
	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->index > j->index)
				inversions++;
			j = j->next;
		}
		i = i->next;
	}
	return (inversions);
}

double	measure_disorder_process(t_node *stack)
{
	int	inversions;
	int	number;

	if (!stack)
		return (0.0);
	number = stack_size(stack);
	if (number < 2)
		return (0.0);
	inversions = count_inversions(stack);
	return ((double)inversions / ((double)number * (number - 1) / 2.0));
}