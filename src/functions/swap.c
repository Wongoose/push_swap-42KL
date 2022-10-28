#include "../../push_swap.h"

void    sa(t_stacks *stacks)
{
    ft_putstr_fd("sa\n", stacks->log_fd);
    if (stacks->stka_len <= 1)
        return ;
    ft_swap(&stacks->stka_arr[0], &stacks->stka_arr[1]);
}

void    sb(t_stacks *stacks)
{
    ft_putstr_fd("sb\n", stacks->log_fd);
    if (stacks->stkb_len <= 1)
        return ;
    ft_swap(&stacks->stkb_arr[0], &stacks->stkb_arr[1]);
}

void    ss(t_stacks *stacks)
{
    sa(stacks);
    sb(stacks);
}