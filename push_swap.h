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

typedef struct  s_stacks {
    int *stka_arr;
    int stka_len;
    int *stkb_arr;
    int stkb_len;
    int log_fd;

}   t_stacks;

// typedef struct  s_chunk {
//     int min;
//     int max;
//     int startnum;
//     int endnum;
//     int len;
// } t_chunk;

typedef struct  s_sortvars {
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

int	    valid_duplicate(t_stacks *stacks, int num, int i);
int	    valid_digits(char *num);
int	    is_sorted(t_stacks stacks);
void	printStackA(t_stacks stacks);
void	printStackB(t_stacks stacks);
void	printChunks(t_chunk *chunks);
void	printChunksB(t_stacks stacks, t_list *bchunks);
void	printChunksA(t_stacks stacks, t_list *achunks);
void    err_exit(char *err);
void    putstr_err(char *err);
void    sa(t_stacks *stacks);
void    sb(t_stacks *stacks);
void    ss(t_stacks *stacks);
void    ra(t_stacks *stacks, t_chunk *chunk);
void    rb(t_stacks *stacks, t_chunk *chunk);
void    rr(t_stacks *stacks, t_chunk *chunk);
void    rra(t_stacks *stacks, t_chunk *chunk);
void    rrb(t_stacks *stacks, t_chunk *chunk);
void    rrr(t_stacks *stacks, t_chunk *chunk);
void    pa(t_stacks *stacks, t_chunk *chunk);
void    pb(t_stacks *stacks, t_chunk *chunk);
int     insert_limits(t_stacks *stacks, t_stktype type);
void    insert_front(t_stacks *stacks, int i, t_stktype type);
void    insert_back(t_stacks *stacks, int i, t_stktype type);
void    find_and_insert(t_stacks *stacks, t_stktype type, int insert_num);
void    sort_3(t_stacks *stacks, t_stktype type);
void    sort_5(t_stacks *stacks);
void    sort_100(t_stacks *stacks);
void    sort_large(t_stacks *stacks);
t_list  *new_chunk(t_list **stk_chunks, int count);
int     find_chunk_median(int *stk_arr, t_chunk *chunk);
int	    chunk_sorted(int *stk_arr, t_chunk *chunk, t_sortorder order);
int 	push_chunk(t_stacks *stacks, t_chunk *chunk);
int 	push_above_median(t_stacks *stacks, int median, t_chunk *chunk);
int	    push_below_median(t_stacks *stacks, int median, t_chunk *chunk);
int	    push_below_median_end(t_stacks *stacks, int median, t_chunk *chunk);
int	    find_startnum(t_stacks *stacks, int startnum, t_stktype stack);


#endif