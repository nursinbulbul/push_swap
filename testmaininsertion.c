#include "push_swap.h"
#include <stdio.h>

/*void	print_stack_debug(t_node *stack, char name)
{
	printf("%c stack: ", name);
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;

	if (argc < 2)
		return (0);

	// stack oluştur
	a = create_stack(argc, argv);

	printf("=== BEFORE SORT ===\n");
	print_stack_debug(a, 'A');
	print_stack_debug(b, 'B');

	// insertion sort çalıştır
	insertion_sort(&a, &b);

	printf("\n=== AFTER SORT ===\n");
	print_stack_debug(a, 'A');
	print_stack_debug(b, 'B');

	// memory temizleme (çok önemli)
	free_stack(&a);
	free_stack(&b);

	return (0);
}
	*/