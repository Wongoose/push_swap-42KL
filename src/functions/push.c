#include "../../push_swap.h"

void    pa(t_stacks *stacks)
{
    if (stacks->stkb_len == 0)
        return ;
    if (stacks->stka_len != 0)
        stacks->stka_arr -= 1;
    stacks->stka_arr[0] = stacks->stkb_arr[0];
    stacks->stkb_arr[0] = 0;
    stacks->stka_len++;
    stacks->stkb_len--;
    if (stacks->stkb_len != 0)
        stacks->stkb_arr += 1;
}

void    pb(t_stacks *stacks)
{
    if (stacks->stka_len == 0)
        return ;
    if (stacks->stkb_len != 0)
        stacks->stkb_arr -= 1;
    stacks->stkb_arr[0] = stacks->stka_arr[0];
    stacks->stka_arr[0] = 0;
    stacks->stkb_len++;
    stacks->stka_len--;
    if (stacks->stka_len != 0)
        stacks->stka_arr += 1;
}