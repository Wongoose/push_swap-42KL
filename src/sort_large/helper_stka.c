#include "../../push_swap.h"

int	push_below_median(t_sortvars *svars, int median, t_chunk *chunk) 
{
	int	i;
	int	count;
	int	rotate_num;

	count = 0;
	rotate_num = 0;
	while (1)
	{
		i = 0;
		while (!(svars->stka_arr[i] < median) && i < chunk->size)
			i++;
		if (i == chunk->size)
			break ;
		rotate_num += i;
		while (i--)
			ra(svars, chunk);
		pb(svars, chunk);
		count++;
	}
	while (rotate_num--)
		rra(svars, chunk);
	return (count);
}

static void	rotate_and_push(t_sortvars *svars, void (*rotate)(t_sortvars *svars, t_chunk *chunk), int i, t_chunk *chunk)
{
	while (i--)
		rotate(svars, 0);
	pb(svars, chunk);
}

int	push_below_median_end(t_sortvars *svars, int median, t_chunk *chunk)
{
	int	start;
	int	end;
	int	count;

	count = 0;
	while (1)
	{
		start = 0;
		end = svars->stka_len - 1;
		while (!(svars->stka_arr[start] < median) && start < svars->stka_len / 2)
			start++;
		if (start >= svars->stka_len / 2)
			start = -1;
		while (!(svars->stka_arr[end] < median) && end >= svars->stka_len / 2 )
			end--;
		if (end < svars->stka_len / 2)
			end = -1;
		if (start == -1 && end == -1)
				break ;
		if (start == -1 || end == -1)
		{
			if (start != -1)
				rotate_and_push(svars, ra, start, chunk);
			else
				rotate_and_push(svars, rra, svars->stka_len - end, chunk);
		}
		else if (start < (svars->stka_len - 1) - end)
			rotate_and_push(svars, ra, start, chunk);
		else
			rotate_and_push(svars, rra, svars->stka_len - end, chunk);
		count++;
	}
	return (count);
}