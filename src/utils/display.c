#include "../../push_swap.h"

void	printStackA(t_stacks stacks)
{
	int	i;

	i = 0;
	printf("========================\n");
	printf("Printing stack A... (len: %d)\n", stacks.stka_len);
	printf("Address of pointer A is: (%p)\n", stacks.stka_arr);
	while (i < stacks.stka_len)
		printf("%d\n", stacks.stka_arr[i++]);
}

void	printStackB(t_stacks stacks)
{
	int	i;

	i = 0;
	printf("========================\n");
	printf("Printing stack B... (len: %d)\n", stacks.stkb_len);
	printf("Address of pointer B is: (%p)\n", stacks.stkb_arr);
	while (i < stacks.stkb_len)
		printf("%d\n", stacks.stkb_arr[i++]);
}