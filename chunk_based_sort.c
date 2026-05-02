#include "push_swap.h"

/*min-max ile aralık(range) belirliyoruz ve bu aralıktaki nodeları buluyoruz*/
/*node pozisyonunu, stack içindeki yerini, geri döndürüyor*/
int find_index_in_range(t_node *a, int min, int max)
{
	int pos = 0;

	while (a)
	{
		if (a->index >= min && a->index <= max)
			return (pos);
		pos++;
		a = a->next;
	}
	return (-1);
}

/*nodeları indexe göre sıralama*/
void bring_to_top(t_node **a, int pos)
{
	int size = stack_size(*a);

	if (pos <= size / 2)
	{
		while (pos--)
			ra(a);
	}
	else
	{
		pos = size - pos;
		while (pos--)
			rra(a);
	}
}

/*stackte ayrım yaptığımız her bir chunkı bye taşır*/
/*bde düzenlenmiş nodeları tekrar aya gönderir*/
/*range bizim için kontrol edilecek index aralığı olacak*/
void chunk_sort(t_node **a, t_node **b, int range)
{
	push_chunks_to_b(a, b,range);
	push_back_to_a(a, b);
}

void push_chunks_to_b(t_node **a, t_node **b, int range)
{
	int i = 0;
	int max = range;
	int pos;

	while (*a)
	{
		pos = find_index_in_range(*a, i, max);

		if (pos == -1)
		{
			i += range;
			max += range;
		}
		else
		{
			bring_to_top(a, pos);
			pb(a, b);
		}
	}
}

/*bdeki düzenlenmiş stacki aya aktarma*/
void push_back_to_a(t_node **a, t_node **b)
{
	int max_pos;

	while (*b)
	{
		max_pos = find_max_index_position(*b);
		bring_to_top(b, max_pos);
		pa(a, b);
	}
}