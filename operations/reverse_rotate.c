/* reverse rotate stack'i ters yönde döndürme */

/* 1 2 3 4 -->  4 1 2 3 */

/* rra adımlar: 1 sona git 2 son node'u al*/
/* 3- onu kopar   4- başa koy*/


#include "../push_swap.h"

void	rra(t_node **a)
{
	t_node	*last;
	t_node	*second_last;

	if (!a || !*a || !(*a)->next)
		return;

	last = *a;
	while (last->next)
		last = last->next;

	second_last = last->prev;

	if (second_last)
		second_last->next = NULL;

	last->next = *a;
    (*a)->prev = last;

	last->prev = NULL;
	
	*a = last;
}

void	rrb(t_node **b)
{
	t_node	*last;
	t_node	*second_last;

	if (!b || !*b || !(*b)->next)
		return;

	last = *b;
	while (last->next)
		last = last->next;

	second_last = last->prev;

	if (second_last)
		second_last->next = NULL;

	last->next = *b;
    (*b)->prev = last;

    last->prev = NULL;

	*b = last;
}

/* örnek : a:  1 2 3 4   b: 5 6 7 */
/*  sonuc: 4 1 2 3  b: 7 5 6  */
void	rrr(t_node **a, t_node **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}