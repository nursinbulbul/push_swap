#include "push_swap.h"

int is_sorted(t_node *stack)
{
    if (!stack)
        return (1);
    while (stack->next)
    {
        if (stack->index > stack->next->index)
            return (0);
        stack = stack->next;
    }
    return (1);
}

int	find_root(int total_len)
{
	int	root;

	if (total_len <= 0)
		return (0);
	root = 1;
	while (root * root <= total_len)
	{
		if (root * root == total_len)
			return (root);
		root++;
	}
	return (root - 1);
}