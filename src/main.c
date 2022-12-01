/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:04:30 by zwong             #+#    #+#             */
/*   Updated: 2022/12/01 13:04:00 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// initialize values of sortvars (svars)
// Allocate space of Stack A and B array based on input length (argc)
// line 16: "svars->stkb_arr += (argc - 2)" - Moves stack B ptr to the end
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
	svars->stkb_arr += (argc - 2);
	svars->log_fd = open("log", O_RDWR);
}

// use "long" for num to accept large input but will be validated
// argv++ to neglect program name (convenient)
// Loops through argv strings for validation
// if all 3 validaiton passed below, then add num to malloced Stack A
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

// Fix leaks
// SHow operations in terminal
// Clean printf
int	main(int argc, char **argv)
{
	t_sortvars	svars;

	if (argc < 2)
		putstr_err("Invalid number of arguments!");
	init_push_swap(&svars, argc);
	validate_input(&svars, argv);
	if (is_sorted(svars))
		return (0);
	if (svars.stka_len <= 3)
		sort_3(&svars);
	else if (svars.stka_len <= 5)
		sort_5(&svars);
	else if (svars.stka_len > 5)
		sort_large(&svars);
	free_svars(&svars);
	system("leaks push_swap");
	return (0);
}
