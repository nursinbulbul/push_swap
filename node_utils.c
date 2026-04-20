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
	node->next = NULL;
	node->prev = NULL; /*node henüz zincire bağlı değil*/
	return (node); /*oluşturulan nodeu geri verir*/
}


/*kısacaaa bir integer'ı aldı ve onu linked list için
yeni bir node haline getirir*/