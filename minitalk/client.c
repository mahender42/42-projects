#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include "libft/libft.h"

void    handler(int signum)
{
    if (signum == SIGKILL);
    ft_putstr_fd("Kill", 1);
}

int main (int argc, char **argv)
{
    struct sigaction sa;
    sa.sa_handler = handler;

    int     i;
    int     pid;
    char    *str;

    i = 0;
    if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
        str = ft_calloc(ft_strlen(str), sizeof(char));
        while (argv[2][i] != '\0')
        {
            str[i] = argv[2][i];
            i++;
        }
        //ft_putstr_fd(str, 1);
        //ft_putnbr_fd(pid, 1);
        //kill (pid, SIGKILL);
    }
}