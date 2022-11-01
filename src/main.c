#include "../push_swap.h"

void	init_push_swap(t_stacks *stacks, int argc)
{
	stacks->stka_len = argc - 1;
	stacks->stka_arr = malloc(sizeof(int) * stacks->stka_len);
	if (!stacks->stka_arr)
		err_exit("Failed to allocate array in Stack A!");
	stacks->stkb_len = 0;
	stacks->stkb_arr = malloc(sizeof(int) * stacks->stka_len);
	if (!stacks->stkb_arr)
		err_exit("Failed to allocate array in Stack B!");
	printf("Start of pointer B is: (%p)\n", stacks->stkb_arr);
	stacks->stkb_arr += (argc - 2); // argc - 1 is the number of integers, then -1 again for offset
	printf("End of pointer B is: (%p)\n", stacks->stkb_arr);
	stacks->log_fd = open("log", O_RDWR);
}

void	validate_input(t_stacks *stacks, char **argv)
{
	int		i;
	long	num;

	argv++;
	i = 0;
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		if (!valid_digits(argv[i]))
			putstr_err("Invalid input: Found invalid character!");
		if (!valid_duplicate(stacks, num, i))
			putstr_err("Invalid input: Found duplicate number!");
		if (num > INT_MAX || num < INT_MIN)
			putstr_err("Invalid input: A number is out of integer range!");
		stacks->stka_arr[i] = num;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc < 2)
		putstr_err("Invalid number of arguments!");
	init_push_swap(&stacks, argc);
	validate_input(&stacks, argv);
	printStackA(stacks);
	printStackB(stacks);
	// solve less than 3 and 5
	if (stacks.stka_len == 3)
		sort_3(&stacks, STK_A);
	else if (stacks.stka_len >= 5)
		sort_100(&stacks);
	// else if (stacks.stka_len == 100)
	// 	sort_100(&stacks);
	return (0);
}