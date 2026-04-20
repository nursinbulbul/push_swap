
#include "../push_swap.h"

void	sa(t_node **a)
{
	t_node	*first;
	t_node	*second;

	if (!a || !*a || !(*a)->next)  /* 2 eleman yoksa swap yapamayız*/
		return;

	first = *a;  
	second = first->next;

	first->next = second->next;   /* örneğin stack 3 2 1 olsun 
    first 3 second 2 olacak burada 3 artık 1'i gösterir*/
	if (second->next) /* eğer seconddan sonra bir node varsa onun previni düzelt*/
		second->next->prev = first; /*3 2 1 iken 2 3 1 oldu ama 1 nodeunun previ yanlış olabilir*/

	second->next = first;
	first->prev = second; /*2 -> 3 olur*/
	second->prev = NULL;

	*a = second; /* yeni head*/

	/*write(1, "sa\n", 3);  bunlar olmadı çift print oluyor*/
}


void    sb(t_node **b)
{
    t_node *first;
    t_node *second;

    if (!b || !*b || !(*b)->next)
		return;

	first = *b;
	second = first->next;

	first->next = second->next;
	if (second->next)
		second->next->prev = first;

	second->next = first;
	first->prev = second;
	second->prev = NULL;

	*b = second;

	/*write(1, "sb\n", 3);*/
}


/*hem sa hem sb yapar*/
/* a: 3 2 1 b: 6 5 4 diyelim*/
/* a: 2 3 1  b: 5 6 4 olur */
void	ss(t_node **a, t_node **b)
{
    sa(a);
	sb(b);
	write(1, "ss\n", 3);
}


