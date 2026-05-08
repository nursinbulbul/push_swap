#include "push_swap.h"

/*stack'in sonuna yeni node ekler*/
void add_back(t_node **stack, t_node *new)
{
	t_node *tmp;  /*listeyi gezmek için geçici pointer*/

	if (!stack || !new) /*stack yoksa new node yoksa*/
		return;

	new->next = NULL; /*listenin sonu*/

	if (*stack == NULL)
	{
		*stack = new;
		return;
	}

	tmp = *stack;  /*listenin sonuna kadar ilerler */
	while (tmp->next)
		tmp = tmp->next; /*son node yeni node'u gösterir*/

	tmp->next = new;
	new->prev = tmp;
}


/*stackte kaç node olduğunu sayar*/
/*bunu algoritmayı kurarken 
çrneğin stack_size <= 3 ise .... fonksiyonuna gönder şeklinde kullanacağız*/
int stack_size(t_node *a)
{
	int count;

	count = 0;
	while (a) /*a stack'i null olduğu sürece devam et*/
	{
		count++; /*bir sonraki node'a geç*/ 
		a = a->next; 
	}
	return (count);
}

/* stackteki tüm nodeları tek tek freeler*/
/* orjinal stack'i değiştirmemiz gerektiğinden
çift ** */
void free_stack(t_node **a)
{
	t_node *tmp;

	if (!a)
		return;

	while (*a)  /* *a = stack */
	{
		tmp = (*a)->next; /*sıradaki nodde'u kaydet*/
        /* [a]->3->2->1 ise tmp = 2*/
		free(*a); /* 3 silindi*/
		*a = tmp; /* [a] -> 2 -> 1*/
	}
}
/*başlangıç:
3 → 2 → 1
1. free(3)
→ 2 → 1
2. free(2)
→ 1
3. free(1)
→ NULL*  yani tüm nodelar silinir memory leak olmaz stack null olur*/