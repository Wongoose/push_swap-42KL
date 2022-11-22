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

typedef enum e_sortorder {
    ASC = 0,
    DES = 1,
}   t_sortorder;

// NEXT: Filter useless variables
typedef struct  s_sortvars {
    int *stka_arr;
    int stka_len;
    int *stkb_arr;
    int stkb_len;
    int log_fd;
    int min;
    int max;
    int range;
    struct s_chunk *chunk_list;
    int hold_first;
    int hold_second;
    int total_chunks;
    int median;
    t_list *stka_chunks;
    t_list *stkb_chunks;

}   t_sortvars;

int	    valid_duplicate(t_sortvars *svars, int num, int i);
int	    valid_digits(char *num);
int	    is_sorted(t_sortvars svars);
void	printStackA(t_sortvars svars);
void	printStackB(t_sortvars svars);
void	printChunks(t_chunk *chunks);
void	printChunksB(t_sortvars svars, t_list *bchunks);
void	printChunksA(t_sortvars svars, t_list *achunks);
void    err_exit(char *err);
void    putstr_err(char *err);
void    sa(t_sortvars *svars);
void    sb(t_sortvars *svars);
void    ss(t_sortvars *svars);
void    ra(t_sortvars *svars, t_chunk *chunk);
void    rb(t_sortvars *svars, t_chunk *chunk);
void    rr(t_sortvars *svars, t_chunk *chunk);
void    rra(t_sortvars *svars, t_chunk *chunk);
void    rrb(t_sortvars *svars, t_chunk *chunk);
void    rrr(t_sortvars *svars, t_chunk *chunk);
void    pa(t_sortvars *svars, t_chunk *chunk);
void    pb(t_sortvars *svars, t_chunk *chunk);
int     insert_limits(t_sortvars *svars, t_stktype type);
void    insert_front(t_sortvars *svars, int i, t_stktype type);
void    insert_back(t_sortvars *svars, int i, t_stktype type);
void    find_and_insert(t_sortvars *svars, t_stktype type, int insert_num);
void    sort_3(t_sortvars *svars);
void    sort_5(t_sortvars *svars);
void    sort_100(t_sortvars *svars);
void    sort_large(t_sortvars *svars);
t_list  *new_chunk(t_list **stk_chunks, int count);
int     find_chunk_median(int *stk_arr, t_chunk *chunk);
int	    chunk_sorted(int *stk_arr, t_chunk *chunk, t_sortorder order);
int 	push_chunk(t_sortvars *svars, t_chunk *chunk);
int 	push_above_median(t_sortvars *svars, int median, t_chunk *chunk);
int	    push_below_median(t_sortvars *svars, int median, t_chunk *chunk);
int	    push_below_median_end(t_sortvars *svars, int median, t_chunk *chunk);
int	    find_startnum(t_sortvars *svars, int startnum, t_stktype stack);


#endif