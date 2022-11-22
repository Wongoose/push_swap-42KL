#include "../../push_swap.h"

// NEXT create sort 3 and 5 for chunks
// USE pointer to chunks for all functions
// ADD chunk size decrement only
void	mediansort_a(t_stacks *stacks, t_chunk *chunk, t_sortvars *svars)
{
	int		median;
	int		size;
	int i;

	while (1)
	{
		i = 0;
		chunk = svars->stka_chunks->curr_chunk;
		while (i < chunk->size)
		{
			printf("%d, ", stacks->stka_arr[i]);
			i++;
		}
		if (chunk_sorted(stacks->stka_arr, chunk, ASC) || chunk->size == 1)
			return ;
		if (chunk->size == 2)
			sa(stacks);
		else
		{
			median = find_chunk_median(stacks->stka_arr, svars->stka_chunks->curr_chunk);
			size = push_below_median(stacks, median, chunk);
			svars->stkb_chunks = new_chunk(&svars->stkb_chunks, size);
		}
	}
}

void	mediansort_b(t_stacks *stacks, t_chunk *chunk, t_sortvars *svars)
{
	int	median;
	int	size;

	if (chunk_sorted(stacks->stkb_arr, chunk, DES) || chunk->size <= 2)
		size = push_chunk(stacks, chunk);
	else
	{
		median = find_chunk_median(stacks->stkb_arr, chunk);
		size = push_above_median(stacks, median, chunk);
	}
	svars->stka_chunks = new_chunk(&svars->stka_chunks, size);
}

// initializes the first set of chunks in B
// result will have all numbers in descending order in chunks
void	init_bchunks(t_stacks *stacks, t_sortvars *svars)
{
	int	median;
	int	size;

	svars->stkb_chunks = 0;
	svars->stka_chunks = 0;
	new_chunk(&svars->stka_chunks, stacks->stka_len);
	printf("\n----\n");
	while (stacks->stka_len > 3)
	{
		median = find_chunk_median(stacks->stka_arr, svars->stka_chunks->curr_chunk);
		size = push_below_median_end(stacks, median, svars->stka_chunks->curr_chunk);
		new_chunk(&svars->stkb_chunks, size);
	}
}

// 1. Check if curr chunk B is sorted
// 2. mediansort B (find median and push larger than) - gen new chunk in A
// 3. Check if need mediansort A (check by length, median) - gen new chunk in B
// 4. If chunk in A len <= 5 (sort_3, sort_5)
// 5. Chunk A settled, loop to STEP 1
// 6. Until curr chunk len == 0 (cannot find startnum/endnum)
// 7. Move to next chunk LOOP
void    sort_large(t_stacks *stacks)
{
	t_sortvars svars;
	t_chunk		*chunk;

	init_bchunks(stacks, &svars);
	sort_3(stacks, STK_A);
	printChunksA(*stacks, svars.stka_chunks);
	printChunksB(*stacks, svars.stkb_chunks);
	while (svars.stkb_chunks)
	{
		chunk = svars.stkb_chunks->curr_chunk;
		mediansort_b(stacks, chunk, &svars);
		printChunksA(*stacks, svars.stka_chunks);
		printChunksB(*stacks, svars.stkb_chunks);
		mediansort_a(stacks, chunk, &svars);
		printChunksA(*stacks, svars.stka_chunks);
		printChunksB(*stacks, svars.stkb_chunks);
		if (svars.stkb_chunks->curr_chunk->size == 0)
			svars.stkb_chunks = svars.stkb_chunks->next;
	}
}