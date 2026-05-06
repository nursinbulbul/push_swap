#include "push_swap.h"
#include <stdio.h>

void	print_stack_debug(t_node *stack, char name)
{
	printf("%c stack: ", name);
	while (stack)
	{
		printf("%d(%d) ", stack->value, stack->index);
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

	// 1. stack oluştur
	a = create_stack(argc, argv);

	// 2. index ata (ÇOK ÖNEMLİ)
	assign_index(a);

	printf("=== BEFORE RADIX ===\n");
	print_stack_debug(a, 'A');
	print_stack_debug(b, 'B');

	// 3. radix çalıştır
	radix_sort(&a, &b);

	printf("\n=== AFTER RADIX ===\n");
	print_stack_debug(a, 'A');
	print_stack_debug(b, 'B');

	// 4. memory temizle
	free_stack(&a);
	free_stack(&b);

	return (0);
}