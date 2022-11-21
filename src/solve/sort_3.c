#include "../../push_swap.h"

void sort_3a(t_stacks *stacks)
{
    int num1;
    int num2;
    int num3;

    num1 = stacks->stka_arr[0];
    num2 = stacks->stka_arr[1];
    num3 = stacks->stka_arr[2];

    if (num1 > num2 && num2 < num3 && num3 > num1)
        sa(stacks);
    else if ((num1 > num2 && num2 > num3) && num3 < num1)
    {
        sa(stacks);
        rra(stacks, 0);
    }
    else if (num1 > num2 && num2 < num3 && num3 < num1)
        ra(stacks, 0);
    else if (num1 < num2 && num2 > num3 && num3 > num1)
    {
        sa(stacks);
        ra(stacks, 0);
    }
    else if (num1 < num2 && num2 > num3 && num3 < num1)
        rra(stacks, 0);
}

void sort_3b(t_stacks *stacks)
{
    int num1;
    int num2;
    int num3;

    num1 = stacks->stkb_arr[0];
    num2 = stacks->stkb_arr[1];
    num3 = stacks->stkb_arr[2];

    if (num1 > num2 && num2 < num3 && num3 > num1)
        sb(stacks);
    else if ((num1 > num2 && num2 > num3) && num3 < num1)
    {
        sb(stacks);
        rrb(stacks, 0);
    }
    else if (num1 > num2 && num2 < num3 && num3 < num1)
        rb(stacks, 0);
    else if (num1 < num2 && num2 > num3 && num3 > num1)
    {
        sb(stacks);
        rb(stacks, 0);
    }
    else if (num1 < num2 && num2 > num3 && num3 < num1)
        rrb(stacks, 0);
}

// For now, technically don't need sort_3b. Only sort_3a is used.
void sort_3(t_stacks *stacks, t_stktype type)
{
    printf("\n\n==SORTING 3==\n\n");
    if (type == STK_A && stacks->stka_len == 3)
        sort_3a(stacks);
    else if (type == STK_B && stacks->stkb_len == 3)
        sort_3b(stacks);
    else
        return ;
}