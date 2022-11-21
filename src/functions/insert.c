#include "../../push_swap.h"

int insert_limits(t_stacks *stacks, t_stktype type)
{
    int b_num;

    b_num = stacks->stkb_arr[0];
    if (b_num < stacks->stka_arr[0])
    {
        if (type == STK_A)
            pa(stacks, 0);
        else
            pb(stacks, 0);
        return (1);
    }
    else if (b_num > stacks->stka_arr[stacks->stka_len - 1])
    {
        if (type == STK_A)
            pa(stacks, 0);
        else
            pb(stacks, 0);
        if (type == STK_A)
            ra(stacks, 0);
        else
            rb(stacks, 0);
        return (1);
    }
    return (0);
}

void    insert_front(t_stacks *stacks, int i, t_stktype type)
{
    int count;

    count = 0;
    while (count <= i)
    {
        if (type == STK_A)
            ra(stacks, 0);
        else
            rb(stacks, 0);
        count++;
    }
    if (type == STK_A)
        pa(stacks, 0);
    else
        pb(stacks, 0);
    while (count > 0)
    {
        if (type == STK_A)
            rra(stacks, 0);
        else
            rrb(stacks, 0);
        count--;
    }
}

void    insert_back(t_stacks *stacks, int i, t_stktype type)
{
    int count;

    count = 0;
    while (count < stacks->stka_len - (i + 1))
    {
        if (type == STK_A)
            rra(stacks, 0);
        else
            rrb(stacks, 0);
        count++;
    }
    if (type == STK_A)
        pa(stacks, 0);
    else
        pb(stacks, 0);
    while (count >= 0)
    {
        if (type == STK_A)
            ra(stacks, 0);
        else
            rb(stacks, 0);
        count--;
    }
}

void    find_and_insert(t_stacks *stacks, t_stktype type, int insert_num)
{
    int i;
    int *insert_arr;
    int stk_len;
    
    if (insert_limits(stacks, type))
    {
        printf("\n\n==Inserted min/max: %d\n\n", insert_num);
        return ;
    }
    i = 0;
    if (type == STK_A)
        insert_arr = stacks->stka_arr;
    else
        insert_arr = stacks->stkb_arr;
    while (!(insert_num > insert_arr[i] && insert_num < insert_arr[i + 1]))
            i++;
    printf("\n\n==Sweet spot is: %d\n\n", i);
    if (type == STK_A)
        stk_len = stacks->stka_len;
    else
        stk_len = stacks->stkb_len;
    if (i < stk_len / 2)
        insert_front(stacks, i, type);
    else if (i >= stk_len / 2)
        insert_back(stacks, i, type);
}