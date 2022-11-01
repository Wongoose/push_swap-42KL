#include "../../push_swap.h"

// create function to pb loop
void    sort_5(t_stacks *stacks)
{
    pb(stacks);
    pb(stacks);
    sort_3(stacks, STK_A);
    printf("\n\n==SORTING 7==\n\n");
    while (stacks->stkb_len > 0)
    {
        find_and_insert(stacks, STK_A, stacks->stkb_arr[0]);
	    printStackA(*stacks);
	    printStackB(*stacks);
    }
}

// void    sort_5(t_stacks *stacks)
// {
//     int i;
//     int b_num;

//     pb(stacks);
//     pb(stacks);
//     sort_3(stacks, STK_A);
//     printf("\n\n==SORTING 7==\n\n");
//     // insert sweet spot (make external function for sort 100 usage)
//     while (stacks->stkb_len > 0)
//     {
//         if (!insert_limits(stacks, STK_A))
//         {
//             i = 0;
//             b_num = stacks->stkb_arr[0];
//             while (!(b_num > stacks->stka_arr[i] && b_num < stacks->stka_arr[i + 1]))
//                 i++;
//             printf("\n\n==Sweet spot is: %d\n\n", i);
//             if (i < stacks->stka_len / 2)
//                 insert_front(stacks, i, STK_A);
//             else if (i >= stacks->stka_len / 2)
//                 insert_back(stacks, i, STK_A);
//         }
// 	    printStackA(*stacks);
// 	    printStackB(*stacks);
//     }
// }