/*burda linked list yani stack imiz için yeni 
bir node oluşturuyoruz.bir sayı alır onu linked list düğümüne çevirir*/


#include "push_swap.h"

t_node *new_node(int value)
{
	t_node *node;    /*bu yeni node'u tutacak*/

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;  /*node içine sayı koyuyoruz*/
	node->index = 1; /*node indexi için bi başlangıç değeri vermemiz gerekiyor, henüz hesaplanmadığını belirtir*/
	node->next = NULL;
	node->prev = NULL; /*node henüz zincire bağlı değil*/
	return (node); /*oluşturulan nodeu geri verir*/
}


/*kısacaaa bir integer'ı aldı ve onu linked list için
yeni bir node haline getirir*/

/*burda index değerinin atamasını yapıyoruz her bir node için*/
/*0dan başlayarak küçükten büyüğe bir indexleme oluyor*/
/*örneğin stack 2,3,1 ise indexleri sırasıyla 2->1, 3->2, 1->0 olur*/
void assign_index(t_node *stack)
{
	t_node *i;
	t_node *j;

	if (!stack)
		return;

	i = stack; /*indexleme için kullanıcaz*/
	while (i)
	{
		int rank = 0;  /*her seferinde sıfırlıyorum çünkü iç döngüde rank için arttırma yapması lazım 0dan*/
		j = stack; /*kontrol ederken gezmek için kullanıcaz*/

		while (j)
		{
			if (j->value < i->value) 
				rank++;
			j = j->next;
		}

		i->index = rank;
		i = i->next;
	}
}

/*bu yardımcı fonksiyon en büyük indexi bulur ve onun stack içindeki pozisyonunu döner*/
int find_max_index_position(t_node *b)
{
	int max;
	int pos;
	int max_pos;

	if (!b)
		return (-1);

	max = b->index;
	pos = 0;
	max_pos = 0;

	while (b)
	{
		if (b->index > max)
		{
			max = b->index;
			max_pos = pos;
		}
		pos++;
		b = b->next;
	}
	return (max_pos);
}