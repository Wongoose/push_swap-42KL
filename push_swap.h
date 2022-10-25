#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct  s_stka {
    int *num_arr;
    int len;

}   t_stka;

int	    valid_duplicate(t_stka *stka, int num, int i);
int	    valid_digits(char *num);
void	printStackA(t_stka stka);
void    err_exit(char *err);
void    putstr_err(char *err);

#endif