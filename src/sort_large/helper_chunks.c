#include "../../push_swap.h"

t_list	*new_chunk(t_list **stk_chunks, int size)
{
	t_chunk	*chunk;

	chunk = malloc(sizeof(t_chunk));
	chunk->size = size;
	printf("Chunk size: %d\n", chunk->size);
	ft_lstadd_front(stk_chunks, ft_lstnew(chunk));
	return (*stk_chunks);
}

int	chunk_sorted(int *stk_arr, t_chunk *chunk, t_sortorder order)
{
	int	i;

	if (chunk->size <= 1)
		return (1);
	i = 0;
	if (order == ASC)
	{
		while (i < chunk->size)
		{
			if (stk_arr[i] > stk_arr[i + 1])
				return (0);
			i++;
		}
	}
	else if (order == DES)
	{
		while (i < chunk->size)
		{
			if (stk_arr[i] < stk_arr[i + 1])
				return (0);
			i++;
		}
	}
	return (1);
}

int	push_chunk(t_stacks *stacks, t_chunk *chunk)
{
	int	count;

	count = 0;
	while (chunk->size != 0)
	{
		pa(stacks, chunk);
		count++;
	}
	return (count);

}

// SECURE BIG NUMBERS IN SUM
int find_chunk_median(int *stk_arr, t_chunk *chunk)
{
    int     i;
	int		med_i;
	float	median;
	float	diff;
    double	sum;
	// beware of big numbers sum
	i = 0;
	sum = 0;
    while (i < chunk->size)
	{
        sum += stk_arr[i];
		i++;
	}
	median = sum / chunk->size;
	i = 0;
	diff = ft_topositive(stk_arr[i] - median);
	while (i < chunk->size)
	{
		if (ft_topositive(stk_arr[i] - median) <= diff)
		{
			diff = ft_topositive(stk_arr[i] - median);
			med_i = i;
		}
		i++;
	}
	return (stk_arr[med_i]);	
}