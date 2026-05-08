#include "push_swap.h"
#include <unistd.h>

static int ft_strcmp(const char *s1, const char *s2)
{
    int i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int main(int argc, char **argv)
{
    t_node  *a;
    t_node  *b;
    int     flag_mode = 0; /* 0: adaptive, 1: simple, 2: medium, 3: complex */
    int     start_idx = 1;

    t_bench bench;
    init_bench(&bench);

    a = NULL;
    b = NULL;

    if (argc < 2)
        return (0);

    /* 1. Çoklu Flag Kontrolü (İstediğin kadar flag'i arka arkaya girebilirsin) */
    while (start_idx < argc && argv[start_idx][0] == '-' && argv[start_idx][1] == '-')
    {
        if (!ft_strcmp(argv[start_idx], "--simple"))
            flag_mode = 1;
        else if (!ft_strcmp(argv[start_idx], "--medium"))
            flag_mode = 2;
        else if (!ft_strcmp(argv[start_idx], "--complex"))
            flag_mode = 3;
        else if (!ft_strcmp(argv[start_idx], "--bench"))
            flag_mode = 3; /* Bench default olarak radix'e gitsin diyorsan 3, adaptive diyorsan 0 yap */
        else if (!ft_strcmp(argv[start_idx], "--adaptive"))
            flag_mode = 0; /* İşte aradığın adaptive flag'i! */
        else
        {
            /* Tanınmayan bir flag girilirse hata versin */
            write(2, "Error\n", 6);
            return (1);
        }
        start_idx++;
    }

    /* Sadece flag girilmiş ama sayı girilmemişse patlamaması için kontrol */
    if (start_idx == argc)
        return (1);

    /* 2. Yığın Oluşturma: Pointer hilesiyle flagleri atlayıp sayıları gönderiyoruz */
    a = create_stack(argc - start_idx + 1, &argv[start_idx - 1]);

    if (!a)
        return (1);

    assign_index(a);

    /* Zaten sıralıysa çık */
    if (is_sorted(a))
    {
        free_stack(&a);
        return (0);
    }

    /* 3. Flag moduna göre sıralamayı çalıştır */
    if (flag_mode == 1)
        insertion_sort(&a, &b, &bench);
    else if (flag_mode == 2)
        chunk_sort(&a, &b, find_root(stack_size(a)), &bench);
    else if (flag_mode == 3)
        radix_sort(&a, &b, &bench);
    else
        adaptive_sort_process(&a, &b, &bench); /* flag_mode = 0 ise burası çalışacak */
    
        
    if (!ft_strcmp(argv[1], "--bench"))
    print_bench(&bench);
    
    free_stack(&a);
    free_stack(&b);

    return (0);
}
