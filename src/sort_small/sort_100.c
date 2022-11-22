#include "../../push_swap.h"

void	find_range(t_sortvars *svars)
{
	int	i;
	int	min;
	int	max;

	i = 0;
 	max = svars->stka_arr[i];
	min = svars->stka_arr[i];
	while (i < svars->stka_len)
	{
		if (svars->stka_arr[i] > max)
			max = svars->stka_arr[i];
		if (svars->stka_arr[i] < min)
			min = svars->stka_arr[i];
		i++;
	}
	svars->min = min;
	svars->max = max;
}

void	init_chunks(t_sortvars *svars, int chunks)
{
	t_chunk	*chunk_list;
	int		i;
	int		range;

	range = svars->max - svars->min;
	chunk_list = malloc(sizeof(t_chunk) * chunks);
	i = 0;
	while (i < chunks)
	{
		chunk_list[i].min = svars->min;
		if (svars->min + (range / chunks) >= svars->max)
		{
			chunk_list[i].max = svars->max;
			break ;
		}
		chunk_list[i].max = svars->min + (range / chunks);
		svars->min += (range / chunks + 1);
		i++;
	}
	svars->chunk_list = chunk_list;
}

int	within_bounds(int num, int min, int max)
{
	if (num >= min && num <= max)
		return (1);
	return (0);
}

void	rotate_and_pb(t_sortvars *svars, void (*rotate)(t_sortvars *svars, t_chunk *chunk), int i)
{
	while (i--)
		rotate(svars, 0);
	pb(svars, 0);
	// printStackB(*svars);
}

void	rotate_and_pa(t_sortvars *svars, void (*rotate)(t_sortvars *svars, t_chunk *chunk), int i)
{
	while (i--)
		rotate(svars, 0);
	pa(svars, 0);
}

void	scan_stack(t_sortvars *svars)
{
	int	i;
	int	start;
	int	end;
	t_chunk	chunk;

	i = 0;
	// Change chunk list to link list
	while (i < svars->total_chunks)
	{
		chunk = svars->chunk_list[i];
		printf("\n====SCANNING CHUNK %d====\n", i + 1);
		while (1)
		{
			start = 0; //
			end = svars->stka_len - 1; // length of stack A
			while (!within_bounds(svars->stka_arr[start], chunk.min, chunk.max) && start < svars->stka_len / 2)
				start++;
			if (start >= svars->stka_len / 2)
				start = -1;
			while (!within_bounds(svars->stka_arr[end], chunk.min, chunk.max) && end >= svars->stka_len / 2)
			{
				end--;
			}
			if (end < svars->stka_len / 2)
				end = -1;
			svars->hold_first = start;
			svars->hold_second = end;
			printf("\n\nFOUND FIRST: %d (i = %d)\n", svars->stka_arr[start], start);
			printf("FOUND SECOND: %d (i = %d)\n\n", svars->stka_arr[end], end);
			if (svars->hold_first == -1 && svars->hold_second == -1)
				break ;
			if (svars->hold_first == -1 || svars->hold_second == -1)
			{
				if (svars->hold_first != -1)
				{
					printf("\nPUSH: %d\n", svars->stka_arr[start]);
					rotate_and_pb(svars, ra, start);
				}
				else
				{
					printf("\nPUSH: %d\n", svars->stka_arr[end]);
					rotate_and_pb(svars, rra, svars->stka_len - end);
				}
			}
			// Prioritize one to push only (calculate shortest move)
			else if (svars->hold_first < (svars->stka_len - 1) - svars->hold_second)
			{
				printf("\nPUSH: %d\n", svars->stka_arr[start]);
				rotate_and_pb(svars, ra, start);
			}
			else
			{
				printf("\nPUSH: %d\n", svars->stka_arr[end]);
				rotate_and_pb(svars, rra, svars->stka_len - end);
			}
		}
		i++;
	}
}

void    sort_100(t_sortvars *svars)
{
	int			i;
	int			max_i;

	find_range(svars);
	if (svars->stka_len <= 100)
		svars->total_chunks = 5;
	else if (svars->stka_len <= 500)
		svars->total_chunks = 13;
	init_chunks(svars, svars->total_chunks);
    printChunks(svars->chunk_list);
	scan_stack(svars);
	printStackA(*svars);
	printStackB(*svars);
	while (svars->stkb_len > 0)
    {
		i = 0;
		max_i = 0;
		while (i < svars->stkb_len)
		{
			if (svars->stkb_arr[i] > svars->stkb_arr[max_i])
				max_i = i;
			i++;
		}
		if (max_i < svars->stka_len / 2)
		{
			rotate_and_pa(svars, rb, max_i);
		}
		else
		{
			rotate_and_pa(svars, rrb, svars->stkb_len - max_i);
		}
    }
    // scan stack A (hold_1st & hold_2nd)
    // get num to the top
    // insert to stack B
    // repeat till stack A len == 0
    // find biggest num in stack B and "pa"
}