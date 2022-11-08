#include "../../push_swap.h"

static float	ft_topositive(float num)
{
	if (num < 0)
		num = num * -1;
	return (num);
}

static int find_median(t_stacks *stacks)
{
    int     i;
    double	sum;
	float	median;
	int		med_i;
	float	diff;
	// beware of big numbers sum

    i = 0;
	sum = 0;
    while (i < stacks->stka_len)
    {
        sum += stacks->stka_arr[i];
        i++;
    }
	median = sum / stacks->stka_len;
	i = 0;
	diff = ft_topositive(stacks->stka_arr[i] - median);
	while (i < stacks->stka_len)
	{
		if (ft_topositive(stacks->stka_arr[i] - median) < diff)
		{
			diff = ft_topositive(stacks->stka_arr[i] - median);
			med_i = i;
		}
		i++;
	}
	return (stacks->stka_arr[med_i]);	
}

static void	rotate_and_push(t_stacks *stacks, void (*rotate)(t_stacks *stacks), int i)
{
	while (i--)
		rotate(stacks);
	pb(stacks);
	// printStackB(*stacks);
}

static int	push_below_median(t_stacks *stacks, int median)
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
				rotate_and_push(stacks, ra, start);
			else
				rotate_and_push(stacks, rra, stacks->stka_len - end);
		}
		else if (start < (stacks->stka_len - 1) - end)
			rotate_and_push(stacks, ra, start);
		else
			rotate_and_push(stacks, rra, stacks->stka_len - end);
		count++;
	}
	return (count);
}

void	new_bchunk(t_stacks *stacks, t_sortvars *svars, int count)
{
	t_chunk	chunk;
	chunk.startnum = stacks->stkb_arr[0];
	chunk.endnum = stacks->stkb_arr[count - 1];
	chunk.len = count;
	printf("\n====\n");
	printf("Chunk startnum: %d\n", chunk.startnum);
	printf("Chunk endnum: %d\n", chunk.endnum);
	ft_lstadd_front(&svars->stkb_chunks, ft_lstnew(&chunk));
}

void    sort_large(t_stacks *stacks)
{
	t_sortvars svars;
	int			count;

	while (stacks->stka_len > 3)
	{
		// find median
		svars.median = find_median(stacks);
		// push anything less than median to stack B
		count = push_below_median(stacks, svars.median);
		new_bchunk(stacks, &svars, count);
		// how to define a chunk? (by index, svars)
		// question remains: big chunk from B push to A how to sort?
	}
	// Chunks defined in B
	// Now start solving
	sort_3(stacks, STK_A);
	// 1. Check if curr chunk B is sorted
	// 2. quicksort B (find median and push larger than) - gen new chunk in A
	// 3. Check if need quicksort A (check by length, median) - gen new chunk in B
	// 4. If chunk in A len <= 5 (sort_3, sort_5)
	// 5. Chunk A settled, loop to STEP 1
	// 6. Until curr chunk len == 0 (cannot find startnum/endnum)
	// 7. Move to next chunk LOOP
}