#include "../push_swap.h"

void	init_push_swap(t_sortvars *svars, int argc)
{
	svars->stka_len = argc - 1;
	svars->stka_arr = malloc(sizeof(int) * svars->stka_len);
	if (!svars->stka_arr)
		err_exit("Failed to allocate array in Stack A!");
	svars->stkb_len = 0;
	svars->stkb_arr = malloc(sizeof(int) * svars->stka_len);
	if (!svars->stkb_arr)
		err_exit("Failed to allocate array in Stack B!");
	printf("Start of pointer B is: (%p)\n", svars->stkb_arr);
	svars->stkb_arr += (argc - 2); // argc - 1 is the number of integers, then -1 again for offset
	printf("End of pointer B is: (%p)\n", svars->stkb_arr);
	svars->log_fd = open("log", O_RDWR);
}

void	validate_input(t_sortvars *svars, char **argv)
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
		if (!valid_duplicate(svars, num, i))
			putstr_err("Invalid input: Found duplicate number!");
		if (num > INT_MAX || num < INT_MIN)
			putstr_err("Invalid input: A number is out of integer range!");
		svars->stka_arr[i] = num;
		i++;
	}
}

// NEXT: Fix edge cases of finding median
// Clear printfs
// SHow operations in terminal
// Double confirm validation
// Fix leaks
// Add comments for explanation
int	main(int argc, char **argv)
{
	t_sortvars	svars;

	if (argc < 2)
		putstr_err("Invalid number of arguments!");
	init_push_swap(&svars, argc);
	validate_input(&svars, argv);
	printf("Validated input");
	printStackA(svars);
	printStackB(svars);
	printf("Printed 1st stacks");
	if (is_sorted(svars))
		return (0);
	if (svars.stka_len == 2)
		sa(&svars);
	else if (svars.stka_len == 3)
		sort_3(&svars);
	else if (svars.stka_len <= 5)
		sort_5(&svars);
	else if (svars.stka_len > 5)
		sort_large(&svars);
	printStackA(svars);
	printStackB(svars);
	// REMEMBER to free when end
	return (0);
}