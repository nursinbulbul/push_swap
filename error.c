/* bu fonksiyon programda hata olunca 
programı durdurur ve error yazdırır */

#include "push_swap.h"

void error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

/*2 stderr hata ekranı*/
/* exit 1 programı direkt kapatır 
acaba bunu kullanabiliyor muyuz?? */