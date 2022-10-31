#include "../../push_swap.h"

void	find_range(t_stacks *stacks, t_sortvars *svars)
{
	int	i;
	int	min;
	int	max;

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
	svars->min = min;
	svars->max = max;
}

void	init_chunks(t_sortvars *svars)
{
	t_chunk	*chunk_list;
	int		i;
	int		range;

	range = svars->max - svars->min;
	chunk_list = malloc(sizeof(t_chunk) * 5);
	i = 0;
	while (i < 5)
	{
		chunk_list[i].min = svars->min;
		if (i < 4)
			chunk_list[i].max = svars->min + (range / 5);
		else
			chunk_list[i].max = svars->max;
		svars->min += (range / 5 + 1);
		i++;
	}
	svars->chunk_list = chunk_list;
}

void    sort_100(t_stacks *stacks)
{
    t_sortvars	svars;

	 find_range(stacks, &svars);
    printf("\nMax is: %d\n", svars.max);
    printf("Min is: %d\n", svars.min);
	 init_chunks(&svars);
    printChunks(svars.chunk_list);
    // scan stack A (hold_1st & hold_2nd)
    // get num to the top
    // insert to stack B
    // repeat till stack A len == 0
    // find biggest num in stack B and "pa"
}