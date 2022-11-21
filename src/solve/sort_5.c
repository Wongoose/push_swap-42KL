#include "../../push_swap.h"

void    sort_5(t_stacks *stacks)
{
    int i;

    i = stacks->stka_len - 3;
    while (i--)
        pb(stacks, 0);
    sort_3(stacks, STK_A);
    printf("\n\n==SORTING 5==\n\n");
    while (stacks->stkb_len > 0)
        find_and_insert(stacks, STK_A, stacks->stkb_arr[0]);
}