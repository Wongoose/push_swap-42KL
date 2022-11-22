#include "../../push_swap.h"

int	push_above_median(t_sortvars *svars, int median, t_chunk *chunk) 
{
	int	i;
	int	count;
	int	rotate_num;

	count = 0;
	rotate_num = 0;
	while (1)
	{
		i = 0;
		while (!(svars->stkb_arr[i] > median) && i < chunk->size)
			i++;
		if (i == chunk->size)
			break ;
		rotate_num += i;
		while (i--)
			rb(svars, chunk);
		pa(svars, chunk);
		count++;
	}
	while (rotate_num--)
		rrb(svars, chunk);
	return (count);
}

// add push above median END (for optimization)

int	push_chunk(t_sortvars *svars, t_chunk *chunk)
{
	int	count;

	count = 0;
	while (chunk->size != 0)
	{
		pa(svars, chunk);
		count++;
	}
	return (count);

}
