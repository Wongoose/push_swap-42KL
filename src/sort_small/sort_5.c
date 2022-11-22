#include "../../push_swap.h"

void    sort_5(t_sortvars *svars)
{
    int transfer;
    int i;

    transfer = svars->stka_len - 3;
    i = transfer;
    while (i--)
        pb(svars, 0);
    sort_3(svars);
    printf("\n\n==SORTING 5==\n\n");
    while (transfer--)
        find_and_insert(svars, STK_A, svars->stkb_arr[0]);
}