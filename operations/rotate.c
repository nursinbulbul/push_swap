/* rotate ilk eleman sona gider diğerleri bir sola kayar*/
/* a: 1 2 3 4   ra sonrası  a: 2 3 4 1*/

#include "../push_swap.h"

void	ra(t_node **a)
{
	t_node	*first;
	t_node	*last;

	if (!a || !*a || !(*a)->next)
		return;

	first = *a;  /* first alınır*/
	*a = first->next;  /* head ilerletilir*/

	first->next = NULL;  /* first koparılır*/
	first->prev = NULL;

	last = *a;  /* sona gidilir*/
	while (last->next)
		last = last->next;

	last->next = first; /*sona eklenir */
	first->prev = last;

}

void	rb(t_node **b)
{
	t_node	*first;
	t_node	*last;

	if (!b || !*b || !(*b)->next)
		return;

	first = *b;
	*b = first->next;

	first->next = NULL;
	first->prev = NULL;

	last = *b;
	while (last->next)
		last = last->next;

	last->next = first;
	first->prev = last;

}

void	rr(t_node **a, t_node **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}