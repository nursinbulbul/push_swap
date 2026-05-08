#include "push_swap.h"




/*min değeri olan nodeu en başa alır*/

void	move_min_to_top(t_node **a, t_bench *bench)
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
			exec_ra(a, bench); /*yazdırabilmek için exec kullandık*/
			min_index--;
		}
	}
    /*min index alt yarıdaysa*/
	else
	{
		moves = size - min_index; /*reverse rotate işleminin kaç defa tekrarlanacağını hesaplar*/
		while (moves > 0)
		{
			exec_rra(a, bench);
			moves--;
		}
	}
}

void	insertion_sort(t_node **a, t_node **b, t_bench *bench)
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
		move_min_to_top(a, bench);
		pb(a, b);
		i++;
	}
    /*b stackte artık büyük değer en üstte azalarak gidiyor burdan a'ya aktarma yapıyoruz küçükten büyüğe sıralama olması için*/
	while (*b)
	{
		pa(a, b);
	}
}