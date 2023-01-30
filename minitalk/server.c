/*
1 - abrirse
2 -  mostrar PID
3 - esperar comunicación.. while true??
*/
#include <sys/types.h>
#include <unistd.h>
#include "libft/libft.h"

int main(void)
{
   ft_putstr_fd("PID: ", 1);
   ft_putnbr_fd(getpid(), 1);
   write (1, "\n", 1);
   while (1)
    pause();
   return(0);
}