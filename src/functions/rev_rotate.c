#include "../../push_swap.h"

void    rra(t_stacks *stacks)
{
    int swap_count;
    
    ft_putstr_fd("rra\n", stacks->log_fd);
    swap_count = stacks->stka_len - 1;
    while (swap_count > 0)
    {
        ft_swap(&stacks->stka_arr[swap_count], &stacks->stka_arr[swap_count - 1]);
        swap_count--;
    }
}

void    rrb(t_stacks *stacks)
{
    int swap_count;

    ft_putstr_fd("rrb\n", stacks->log_fd);
    swap_count = stacks->stkb_len - 1;
    while (swap_count > 0)
    {
        ft_swap(&stacks->stkb_arr[swap_count], &stacks->stkb_arr[swap_count - 1]);
        swap_count--;
    }
}

void    rrr(t_stacks *stacks)
{
    ra(stacks);
    rb(stacks);
}