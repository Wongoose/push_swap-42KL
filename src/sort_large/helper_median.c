#include "../../push_swap.h"

static void	rotate_and_push(t_stacks *stacks, void (*rotate)(t_stacks *stacks, t_chunk *chunk), int i, t_chunk *chunk)
{
	while (i--)
		rotate(stacks, 0);
	pb(stacks, chunk);
}

int	push_above_median(t_stacks *stacks, int median, t_chunk *chunk) 
{
	int	i;
	int	count;
	int	rotate_num;

	count = 0;
	rotate_num = 0;
	while (1)
	{
		i = 0;
		while (!(stacks->stkb_arr[i] > median) && i < chunk->size)
			i++;
		if (i == chunk->size)
			break ;
		rotate_num += i;
		while (i--)
			rb(stacks, chunk);
		pa(stacks, chunk);
		count++;
	}
	while (rotate_num--)
		rrb(stacks, chunk);
	return (count);
}

int	push_below_median(t_stacks *stacks, int median, t_chunk *chunk) 
{
	int	i;
	int	count;
	int	rotate_num;

	count = 0;
	rotate_num = 0;
	while (1)
	{
		i = 0;
		while (!(stacks->stka_arr[i] < median) && i < chunk->size)
			i++;
		if (i == chunk->size)
			break ;
		rotate_num += i;
		while (i--)
			ra(stacks, chunk);
		pb(stacks, chunk);
		count++;
	}
	while (rotate_num--)
		rra(stacks, chunk);
	return (count);
}

int	push_below_median_end(t_stacks *stacks, int median, t_chunk *chunk)
{
	int	start;
	int	end;
	int	count;

	count = 0;
	while (1)
	{
		start = 0;
		end = stacks->stka_len - 1;
		while (!(stacks->stka_arr[start] < median) && start < stacks->stka_len / 2)
			start++;
		if (start >= stacks->stka_len / 2)
			start = -1;
		while (!(stacks->stka_arr[end] < median) && end >= stacks->stka_len / 2 )
			end--;
		if (end < stacks->stka_len / 2)
			end = -1;
		if (start == -1 && end == -1)
				break ;
		if (start == -1 || end == -1)
		{
			if (start != -1)
				rotate_and_push(stacks, ra, start, chunk);
			else
				rotate_and_push(stacks, rra, stacks->stka_len - end, chunk);
		}
		else if (start < (stacks->stka_len - 1) - end)
			rotate_and_push(stacks, ra, start, chunk);
		else
			rotate_and_push(stacks, rra, stacks->stka_len - end, chunk);
		count++;
	}
	return (count);
}