#include "../../push_swap.h"

void sort_3(t_sortvars *svars)
{
    int num1;
    int num2;
    int num3;

    num1 = svars->stka_arr[0];
    num2 = svars->stka_arr[1];
    num3 = svars->stka_arr[2];

    if (num1 > num2 && num2 < num3 && num3 > num1)
        sa(svars);
    else if (num1 > num2 && num2 > num3 && num3 < num1)
    {
        sa(svars);
        rra(svars, 0);
    }
    else if (num1 > num2 && num2 < num3 && num3 < num1)
        ra(svars, 0);
    else if (num1 < num2 && num2 > num3 && num3 > num1)
    {
        sa(svars);
        ra(svars, 0);
    }
    else if (num1 < num2 && num2 > num3 && num3 < num1)
        rra(svars, 0);
}
