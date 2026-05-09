#include "../push_swap.h"

/* a stackten b stacke taşır*/
/* a: 3 2 1 b:empty  --->  a: 2 1  b:3*/
/* a'nın head'i ni çıkar b'nin başına ekle*/
void	pb(t_node **a, t_node **b)
{
	t_node	*temp;

	if (!a || !*a)  /* a nın boş olmaması gerek*/
		return;

	temp = *a; /*taşıyacağımız node  a nın ilk elemanı*/
	*a = (*a)->next;  /* a yı ilerlet*/
	if (*a) /* a stack’inin yeni ilk elemanı varsa onun geri bağlantısını sıfırla */
		(*a)->prev = NULL;

	temp->next = *b; /*b ye ekle */
	if (*b)   /* B stack’inin yeni head’inin prev pointer’ını güncelle*/
		(*b)->prev = temp;

	temp->prev = NULL;
	*b = temp;

}

void	pa(t_node **a, t_node **b)
{
	t_node	*temp;

	if (!b || !*b)
		return;

	temp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;

	temp->next = *a;
	if (*a)
		(*a)->prev = temp;

	temp->prev = NULL;
	*a = temp;

}