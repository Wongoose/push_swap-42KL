#include "../../push_swap.h"

void    sort_100(t_stacks *stacks)
{
    // split chunk bounds
    t_chunk *chunk_list;
    int     i;
    int     max;
    int     min;
    int     range;

    i = 0;
    max = stacks->stka_arr[i];
    min = stacks->stka_arr[i];
    while (i < stacks->stka_len)
    {
        if (stacks->stka_arr[i] > max)
            max = stacks->stka_arr[i];
        if (stacks->stka_arr[i] < min)
            min = stacks->stka_arr[i];
        i++;
    }
    printf("\nMax is: %d", max);
    printf("\nMin is: %d", min);
    range = max - min;
    chunk_list = malloc(sizeof(t_chunk) * 5);
    i = 0;
    while (i < 5)
    {
        chunk_list[i].min = min;
        if (i < 4)
            chunk_list[i].max = min + (range / 5);
        else
            chunk_list[i].max = max;
        min += (range / 5 + 1);
        i++;
    }
    i = 0;
    while (i < 5)
    {
        printf("\nChunk%d min is: %d", i + 1, chunk_list[i].min);
        printf("\nChunk%d max is: %d", i + 1, chunk_list[i].max);
        printf("\n==\n");
        i++;
    }
    
    // scan stack A (hold_1st & hold_2nd)
    // get num to the top
    // insert to stack B
    // repeat till stack A len == 0
    // find biggest num in stack B and "pa"
}