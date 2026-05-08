#include "push_swap.h"

/* create stack argümanlardan sayı alır her sayıyı
node'a çevirir stack oluşturur en sonda duplicate kontrolü yapar */
// t_node *create_stack(int argc, char **argv)
// {
// 	t_node	*stack;
// 	t_node	*node;
// 	int		i;
// 	int		value;

// 	stack = NULL;
// 	i = 1;   /*av[0] program adı olduğundan*/

// 	while (i < argc)
// 	{
// 		value = ft_atoi_safe(argv[i]);  /*string ->int */

// 		node = new_node(value);  /*int -> node*/
// 		if (!node)
// 		{
// 			free_stack(&stack);    /*memory leak engelliyoruuzz*/
// 			error_exit();
// 		}

// 		add_back(&stack, node);  /*listeye ekledik*/
// 		i++;
// 	}

// 	if (has_duplicate(stack))
// 	{
// 		free_stack(&stack);
// 		error_exit();
// 	}

// 	return (stack);
// }   

/* burda stringi int'e çeviriyoruz yanlış input varsa programı durduruyoryuz
*/
// int ft_atoi_safe(char *str)
// {
// 	long	result;
// 	int		sign;
// 	int		i;

// 	result = 0;
// 	sign = 1;
// 	i = 0;

// 	if (!str)   /*null check*/
// 		error_exit();

// 	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
// 		i++;

// 	if (str[i] == '+' || str[i] == '-')
// 	{
// 		if (str[i] == '-')
// 			sign = -1;
// 		i++;
// 	}

// 	/*  en az 1 digit olmalı */
// 	if (str[i] < '0' || str[i] > '9')
// 		error_exit();

// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		result = result * 10 + (str[i] - '0');

// 		if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
// 			error_exit();

// 		i++;
// 	}

// 	/* extra karakter varsa hata */
// 	if (str[i] != '\0')
// 		error_exit();

// 	return ((int)(result * sign));
// }


/*stack içinde aynı sayı var mı yok mu kontrol eder varsa ->1 yoksa ->0*/
/*her elemanı diğer tüm elemanlaarla karşılaştırır*/
/*stack 3-2-3 olsun kontolde ilk 3 ile iki v eüçü kıyaslar ve duplicate bulunur*/
int has_duplicate(t_node *a)
{
	t_node *tmp;    /*dış döngü yanii her noded'u tek tek gezer*/
	t_node *check;  /*iç döngü yani diğer nodelarla karşılaştır*/

	if (!a)  /*eğer stack boşsa duplicate olamaz*/
		return (0);

	tmp = a;  /*stack in başından başka meslea stack 3 2 1 şeklindeyse tmp = 3 olacak*/
	while (tmp)
	{
		check = tmp->next; /*kendisiyle karşılaştırma yapmamak için tmp 3 ise check 2 den başlar*/
		while (check)   /*tmpden sonraki tüm nodeları gezer*/
		{
			if (tmp->value == check->value)  /*aynı sayı varsa duplica bulundu fonksiuonu bitir*/
				return (1);
			check = check->next;  /*bir sonraki nodde'a geç*/
		}
		tmp = tmp->next;  /*dış döngü bir sonraki elemana geçer*/
	}
	return (0);  /*hiç aynı sayıyı yoks atack temiizz*/
}


/* * 1. HATA YAKALAYICI (Satır tasarrufu için)
 * Hata durumunda hem stack'i temizler hem programı kapatır.
 */
static void	handle_error(t_node **stack)
{
	free_stack(stack);
	error_exit();
}

/* * 2. SAYI OKUYUCU (Tam 20 satır - Norm OK)
 * Stringin içindeki İLK sayıyı bulur, okur ve string pointer'ını ileri sarar.
 */
static int	get_next_number(char **str, t_node **stack)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	if (**str < '0' || **str > '9')
		handle_error(stack);
	while (**str >= '0' && **str <= '9')
	{
		result = result * 10 + (**str - '0');
		if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
			handle_error(stack);
		(*str)++;
	}
	return ((int)(result * sign));
}

/* * 3. STRING PARÇALAYICI (Tam 14 satır - Norm OK)
 * Sadece boşlukları atlar ve get_next_number'dan aldığı sayıları listeye ekler.
 */
static void	parse_string_to_stack(t_node **stack, char *str)
{
	int		value;
	t_node	*node;

	while (*str)
	{
		while (*str == ' ' || (*str >= 9 && *str <= 13))
			str++;
		if (!*str)
			break ;
		value = get_next_number(&str, stack);
		node = new_node(value);
		if (!node)
			handle_error(stack);
		add_back(stack, node);
	}
}

/* * 4. ANA OLUŞTURUCU (Tam 12 satır - Norm OK)
 */
t_node	*create_stack(int argc, char **argv)
{
	t_node	*stack;
	int		i;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		parse_string_to_stack(&stack, argv[i]);
		i++;
	}
	if (has_duplicate(stack))
		handle_error(&stack);
	return (stack);
}
