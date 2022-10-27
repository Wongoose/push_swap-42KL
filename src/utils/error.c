#include "../../push_swap.h"

void    err_exit(char *err)
{
    ft_putstr_fd("Error\n", 2);
    perror(err);
    exit(1);
}

void    putstr_err(char *err)
{
    ft_putstr_fd("Error\n", 2);
    ft_putstr_fd(err, 2);
    exit(1);
}