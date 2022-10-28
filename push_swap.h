#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef enum e_stktype {
    STK_A = 0,
    STK_B = 1,
}   t_stktype;

typedef struct  s_stacks {
    int *stka_arr;
    int stka_len;
    int *stkb_arr;
    int stkb_len;
    int log_fd;

}   t_stacks;

int	    valid_duplicate(t_stacks *stacks, int num, int i);
int	    valid_digits(char *num);
void	printStackA(t_stacks stacks);
void	printStackB(t_stacks stacks);
void    err_exit(char *err);
void    putstr_err(char *err);
void    sa(t_stacks *stacks);
void    sb(t_stacks *stacks);
void    ss(t_stacks *stacks);
void    ra(t_stacks *stacks);
void    rb(t_stacks *stacks);
void    rr(t_stacks *stacks);
void    rra(t_stacks *stacks);
void    rrb(t_stacks *stacks);
void    rrr(t_stacks *stacks);
void    pa(t_stacks *stacks);
void    pb(t_stacks *stacks);
void    sort_3(t_stacks *stacks, t_stktype type);
void    sort_5(t_stacks *stacks);

#endif