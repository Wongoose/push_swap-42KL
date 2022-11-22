#include "../../push_swap.h"

void    rra(t_sortvars *svars, t_chunk *chunk)
{
    int swap_count;
    
    ft_putstr_fd("rra\n", svars->log_fd);
    swap_count = svars->stka_len - 1;
    while (swap_count > 0)
    {
        ft_swap(&svars->stka_arr[swap_count], &svars->stka_arr[swap_count - 1]);
        swap_count--;
    }
    if (chunk)
        chunk->size++;
}

void    rrb(t_sortvars *svars, t_chunk *chunk)
{
    int swap_count;

    ft_putstr_fd("rrb\n", svars->log_fd);
    swap_count = svars->stkb_len - 1;
    while (swap_count > 0)
    {
        ft_swap(&svars->stkb_arr[swap_count], &svars->stkb_arr[swap_count - 1]);
        swap_count--;
    }
    if (chunk)
        chunk->size++;
}

void    rrr(t_sortvars *svars, t_chunk *chunk)
{
    rra(svars, chunk);
    rrb(svars, chunk);
}