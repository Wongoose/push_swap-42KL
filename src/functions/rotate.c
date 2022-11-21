#include "../../push_swap.h"

void    ra(t_stacks *stacks, t_chunk *chunk)
{
    int swap_count;

    ft_putstr_fd("ra\n", stacks->log_fd);
    swap_count = 0;
    while (swap_count < stacks->stka_len - 1)
    {
        ft_swap(&stacks->stka_arr[swap_count], &stacks->stka_arr[swap_count + 1]);
        swap_count++;
    }
    if (chunk)
        chunk->size--;
}

void    rb(t_stacks *stacks, t_chunk *chunk)
{
    int swap_count;

    ft_putstr_fd("rb\n", stacks->log_fd);
    swap_count = 0;
    while (swap_count < stacks->stkb_len - 1)
    {
        ft_swap(&stacks->stkb_arr[swap_count], &stacks->stkb_arr[swap_count + 1]);
        swap_count++;
    }
    if (chunk)
        chunk->size--;
}

void    rr(t_stacks *stacks, t_chunk *chunk)
{
    ra(stacks, chunk);
    rb(stacks, chunk);
}