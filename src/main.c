#include "../push_swap.h"

void	init_push_swap(t_stka *stka, int argc)
{
	stka->len = argc - 1;
	stka->num_arr = malloc(sizeof(int) * stka->len);
	if (!stka->num_arr)
		err_exit("Failed to allocate array in Stack A!");
}

void	validate_input(t_stka *stka, char **argv)
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
		if (!valid_duplicate(stka, num, i))
			putstr_err("Invalid input: Found duplicate number!");
		if (num > INT_MAX || num < INT_MIN)
			putstr_err("Invalid input: A number is out of integer range!");
		stka->num_arr[i] = num;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stka	stka;

	if (argc < 2)
		putstr_err("Invalid number of arguments!");
	init_push_swap(&stka, argc);
	validate_input(&stka, argv);
	printStackA(stka);
	return (0);
}