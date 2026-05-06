#include "push_swap.h"
#include <stdio.h>

/*void print_stack(t_node *a)
{
	while (a)
	{
		printf("value: %d | index: %d\n", a->value, a->index);
		a = a->next;
	}
	printf("------\n");
}

int main(int argc, char **argv)
{
	t_node *a;
	t_node *b;

	if (argc < 2)
		return (0);

	a = create_stack(argc, argv);
	b = NULL;

	// 🔥 indexleri hesapla
	assign_index(a);

	printf("=== BEFORE SORT ===\n");
	print_stack(a);

	// 🔥 chunk sort çalıştır
	chunk_sort(&a, &b);

	printf("=== AFTER SORT ===\n");
	print_stack(a);

	// cleanup
	free_stack(&a);
	free_stack(&b);

	return (0);
}
	*/