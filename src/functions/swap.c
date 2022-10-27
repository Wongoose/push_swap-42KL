#include "../../push_swap.h"

void    sa(t_stacks *stacks)
{
    if (stacks->stka_len <= 1)
        return ;
    ft_swap(&stacks->stka_arr[0], &stacks->stka_arr[1]);
}

void    sb(t_stacks *stacks)
{
    if (stacks->stkb_len <= 1)
        return ;
    ft_swap(&stacks->stkb_arr[0], &stacks->stkb_arr[1]);
}

void    ss(t_stacks *stacks)
{
    sa(stacks);
    sb(stacks);
}