#include "push_swap.h"


/*radix sıralama yaparken bitler üzerinde çalışacağımız ve bit bit ilerleyeceğimiz için*/
/*nodeların içerdiği valueların kaç basamaklı olduğunu (kaç bit olduğunu) hesaplayacağız*/
/*en büyük index kaç bit ile yazılıyor*/
int	get_max_bits(t_node *a)
{
	int	max;
	int	bits;

	max = 0;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}

	bits = 0;
	while ((max >> bits) != 0)
		bits++;

	return (bits);
}
/*kaçıncı bitte olduğumuzu verir*/
/*5->101 bit olarak yazılırsa  5 >> 0 = 5 -> 101    5 % 2 = 1  bu durumda 1 return olur*/
/* 5 >> 1 = 2 -> 10   2 % 2 = 0  0 return olur*/
/* >> bu işaret biti sağa kaydırmaya yarıyor yani 5 bitlik sistemde 101 ise 5 >> 1 dediğimizde 10 veriyor(virgül kaydırmak gibi)*/
int	get_bit(int index, int i)
{
	return ((index >> i) % 2);
}

/*bite göre elemanları ayırıp adan bye dağıtma yapar*/
void	process_bit(t_node **a, t_node **b, int size, int bit_index)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (get_bit((*a)->index, bit_index) == 1)
			exec_ra(a);
		else
			pb(a, b);
		j++;
	}
	while (*b)
		pa(a, b);
}

void	radix_sort(t_node **a, t_node **b)
{
	int	max_bits;
	int	i;
	int	size;

	if (!a || !*a)
		return;
	size = stack_size(*a);
	max_bits = get_max_bits(*a);
	i = 0;
	while (i < max_bits) /*en büyük index biti kadar çalışacak*/
	{
		process_bit(a, b, size, i);
		i++;
	}
}
