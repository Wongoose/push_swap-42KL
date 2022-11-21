#include "../../push_swap.h"

void	printStackA(t_stacks stacks)
{
	int	i;

	i = 0;
	printf("========================\n");
	printf("Printing stack A... (len: %d)\n", stacks.stka_len);
	// printf("Address of pointer A is: (%p)\n", stacks.stka_arr);
	while (i < stacks.stka_len)
		printf("%d\n", stacks.stka_arr[i++]);
}

void	printStackB(t_stacks stacks)
{
	int	i;

	i = 0;
	printf("========================\n");
	printf("Printing stack B... (len: %d)\n", stacks.stkb_len);
	// printf("Address of pointer B is: (%p)\n", stacks.stkb_arr);
	while (i < stacks.stkb_len)
		printf("%d\n", stacks.stkb_arr[i++]);
}

void	printChunksA(t_stacks stacks, t_list *achunks)
{
	int	i;
	int	size;

	i = 0;
	printf("========================\n");
	printf("Printing stack A... (len: %d)\n", stacks.stka_len);
	// printf("Address of pointer B is: (%p)\n", stacks.stkb_arr);
	while (achunks)
	{
		size = achunks->curr_chunk->size;
		size += i;
		while (i < size)
			printf("%d\n", stacks.stka_arr[i++]);
		printf("=========== %d <--- CHUNK END\n", i);
		achunks = achunks->next;
	}
}

void	printChunksB(t_stacks stacks, t_list *bchunks)
{
	int	i;
	int	size;

	i = 0;
	printf("========================\n");
	printf("Printing stack B... (len: %d)\n", stacks.stkb_len);
	// printf("Address of pointer B is: (%p)\n", stacks.stkb_arr);
	while (bchunks)
	{
		size = bchunks->curr_chunk->size;
		size += i;
		while (i < size)
			printf("%d\n", stacks.stkb_arr[i++]);
		printf("=========== %d <--- CHUNK END\n", i);
		bchunks = bchunks->next;
	}
}

void	printChunks(t_chunk *chunks)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		printf("\n==\n\n");
		printf("Chunk%d min is: %d\n", i + 1, chunks[i].min);
		printf("Chunk%d max is: %d\n", i + 1, chunks[i].max);
		i++;
	}
}
