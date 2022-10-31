#include "../../push_swap.h"

void    insert_front(t_stacks *stacks, int i)
{
    int count;

    count = 0;
    while (count <= i)
    {
        ra(stacks);
        count++;
    }
    pa(stacks);
    while (count > 0)
    {
        rra(stacks);
        count--;
    }
}

void    insert_back(t_stacks *stacks, int i)
{
    int count;

    count = 0;
    while (count < stacks->stka_len - (i + 1))
    {
        rra(stacks);
        count++;
    }
    pa(stacks);
    while (count >= 0)
    {
        ra(stacks);
        count--;
    }
}

int insert_limits(t_stacks *stacks)
{
    int b_num;

    b_num = stacks->stkb_arr[0];
    if (b_num < stacks->stka_arr[0])
    {
        pa(stacks);
        return (1);
    }
    else if (b_num > stacks->stka_arr[stacks->stka_len - 1])
    {
        pa(stacks);
        ra(stacks);
        return (1);
    }
    return (0);
}

void    sort_5(t_stacks *stacks)
{
    int i;
    int b_num;

    pb(stacks);
    pb(stacks);
    sort_3(stacks, STK_A);
    printf("\n\n==SORTING 7==\n\n");
    while (stacks->stkb_len > 0)
    {
        if (!insert_limits(stacks))
        {
            i = 0;
            b_num = stacks->stkb_arr[0];
            while (!(b_num > stacks->stka_arr[i] && b_num < stacks->stka_arr[i + 1]))
                i++;
            printf("\n\n==Sweet spot is: %d\n\n", i);
            if (i < stacks->stka_len / 2)
                insert_front(stacks, i);
            else if (i >= stacks->stka_len / 2)
                insert_back(stacks, i);
        }
	    printStackA(*stacks);
	    printStackB(*stacks);
    }
}