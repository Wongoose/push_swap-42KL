#include "../../push_swap.h"

void    sort_3(t_stacks *stacks, t_stktype type)
{
    int num1;
    int num2;
    int num3;

    printf("\n\n==SORTING==\n\n");
    if (type == STK_A && stacks->stka_len == 3)
    {
        num1 = stacks->stka_arr[0];
        num2 = stacks->stka_arr[1];
        num3 = stacks->stka_arr[2];
    }
    else if (type == STK_B && stacks->stkb_len == 3)
    {   
        num1 = stacks->stkb_arr[0];
        num2 = stacks->stkb_arr[1];
        num3 = stacks->stkb_arr[2];
    }
    else
        return ;
    if (num1 > num2 && num2 < num3 && num3 > num1)
    {
        if (type == STK_A)
            sa(stacks);
        if (type == STK_B)
            sb(stacks);
    }   
    else if ((num1 > num2 && num2 > num3) && num3 < num1)
    {
        if (type == STK_A)
        {
            sa(stacks);
            rra(stacks);
        }
        if (type == STK_B)
        {
            sb(stacks);
            rrb(stacks);
        }
    }
    else if (num1 > num2 && num2 < num3 && num3 < num1)
    {
        if (type == STK_A)
            ra(stacks);
        if (type == STK_B)
            rb(stacks);
    }
    else if (num1 < num2 && num2 > num3 && num3 > num1)
    {
        if (type == STK_A)
        {
            sa(stacks);
            ra(stacks);
        }
        if (type == STK_B)
        {
            sb(stacks);
            rb(stacks);
        }
    }
    else if (num1 < num2 && num2 > num3 && num3 < num1)
    {
        if (type == STK_A)
            rra(stacks);
        if (type == STK_B)
            rrb(stacks);
    }
}