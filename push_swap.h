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

typedef struct  s_chunk {
    int min;
    int max;
} t_chunk;

typedef struct  s_sortvars {
    int min;
    int max;
    int range;
    struct s_chunk *chunk_list;

}   t_sortvars;

int	    valid_duplicate(t_stacks *stacks, int num, int i);
int	    valid_digits(char *num);
void	printStackA(t_stacks stacks);
void	printStackB(t_stacks stacks);
void	printChunks(t_chunk *chunks);
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
int     insert_limits(t_stacks *stacks, t_stktype type);
void    insert_front(t_stacks *stacks, int i, t_stktype type);
void    insert_back(t_stacks *stacks, int i, t_stktype type);
void    find_and_insert(t_stacks *stacks, t_stktype type, int insert_num);
void    sort_3(t_stacks *stacks, t_stktype type);
void    sort_5(t_stacks *stacks);
void    sort_100(t_stacks *stacks);

#endif