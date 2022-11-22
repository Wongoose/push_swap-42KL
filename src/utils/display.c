#include "../../push_swap.h"

void	printStackA(t_sortvars svars)
{
	int	i;

	i = 0;
	printf("========================\n");
	printf("Printing stack A... (len: %d)\n", svars.stka_len);
	// printf("Address of pointer A is: (%p)\n", svars.stka_arr);
	while (i < svars.stka_len)
		printf("%d\n", svars.stka_arr[i++]);
}

void	printStackB(t_sortvars svars)
{
	int	i;

	i = 0;
	printf("========================\n");
	printf("Printing stack B... (len: %d)\n", svars.stkb_len);
	// printf("Address of pointer B is: (%p)\n", svars.stkb_arr);
	while (i < svars.stkb_len)
		printf("%d\n", svars.stkb_arr[i++]);
}

void	printChunksA(t_sortvars svars, t_list *achunks)
{
	int	i;
	int	size;

	i = 0;
	printf("========================\n");
	printf("Printing stack A... (len: %d)\n", svars.stka_len);
	// printf("Address of pointer B is: (%p)\n", svars.stkb_arr);
	while (achunks)
	{
		size = achunks->curr_chunk->size;
		size += i;
		while (i < size)
			printf("%d\n", svars.stka_arr[i++]);
		printf("=========== %d <--- CHUNK END\n", i);
		achunks = achunks->next;
	}
}

void	printChunksB(t_sortvars svars, t_list *bchunks)
{
	int	i;
	int	size;

	i = 0;
	printf("========================\n");
	printf("Printing stack B... (len: %d)\n", svars.stkb_len);
	// printf("Address of pointer B is: (%p)\n", svars.stkb_arr);
	while (bchunks)
	{
		size = bchunks->curr_chunk->size;
		size += i;
		while (i < size)
			printf("%d\n", svars.stkb_arr[i++]);
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
