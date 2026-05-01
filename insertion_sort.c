#include "push_swap.h"


/*nodeların hepsini gezip minimum değerin bulunduğu nodeu bulur*/

int	get_min_index(t_node *a)
{
	int	min;
	int	index;
	int	i;

	if (!a)
		return (0);

	min = a->value;
	index = 0;
	i = 0;
	while (a)
	{
		if (a->value < min)
		{
			min = a->value;
			index = i;
		}
		a = a->next;
		i++;
	}
	return (index);
}

/*min değeri olan nodeu en başa alır*/

void	move_min_to_top(t_node **a)
{
	int	min_index;
	int	size;
	int	moves;

	min_index = get_min_index(*a);
	size = stack_size(*a);

    /*min index stackte üst yarıdaysa*/
	if (min_index <= size / 2)
	{
		while (min_index > 0)
		{
			exec_ra(a); /*yazdırabilmek için exec kullandık*/
			min_index--;
		}
	}
    /*min index alt yarıdaysa*/
	else
	{
		moves = size - min_index; /*reverse rotate işleminin kaç defa tekrarlanacağını hesaplar*/
		while (moves > 0)
		{
			exec_rra(a);
			moves--;
		}
	}
}

void	insertion_sort(t_node **a, t_node **b)
{
	int	size;
	int	i;

	if (!a || !*a)
		return;

	size = stack_size(*a);
	i = 0;
    /*bu döngüde a stackte min değeri bulup her seferinde b'ye aktarıyor*/
	while (i < size)
	{
		move_min_to_top(a);
		pb(a, b);
		i++;
	}
    /*b stackte artık büyük değer en üstte azalarak gidiyor burdan a'ya aktarma yapıyoruz küçükten büyüğe sıralama olması için*/
	while (*b)
	{
		pa(a, b);
	}
}