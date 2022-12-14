/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:39:23 by zwong             #+#    #+#             */
/*   Updated: 2022/12/07 22:19:08 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// initialize values of sortvars (svars)
// Allocate space of Stack A and B array based on input length (count)
// line 29: "svars->stkb_arr += (count - 1)" - Moves stack B ptr to the end
// svars->log_fd = open("log", O_RDWR);
void	init_stacks(t_sortvars *svars, int count)
{
	svars->stka_len = count;
	svars->stka_arr = malloc(sizeof(int) * svars->stka_len);
	if (!svars->stka_arr)
		err_exit(FALSE);
	svars->stkb_len = 0;
	svars->stkb_arr = malloc(sizeof(int) * svars->stka_len);
	if (!svars->stkb_arr)
		err_exit(FALSE);
	svars->stkb_arr += (count - 1);
	svars->log_fd = 1;
}

// ft_strchr(argv[i], ' ') != 0 -> Checks whether argv has multiple int
// ft_split and then validate
// line 59: Else if it is just single int input, validate directly
void	init_validation(t_sortvars *svars, char **argv)
{
	char	**temp_split;
	int		insert_count;
	int		i;
	int		j;

	i = 0;
	j = 0;
	insert_count = 0;
	while (argv[i])
	{
		if (ft_strchr(argv[i], ' ') != 0)
		{
			j = 0;
			temp_split = ft_split(argv[i], ' ');
			while (temp_split[j])
				validate_input(svars, temp_split[j++], insert_count++);
			free_splitstr(temp_split);
		}
		else
			validate_input(svars, argv[i], insert_count++);
		i++;
	}
}

// Counting potential number of int inputs
// ft_strchr(argv[i], ' ') != 0 -> Checks whether argv has multiple int
// ft_split and then increment num_count (++)
int	count_inputs(char **argv)
{
	char	**temp_split;
	int		num_count;
	int		i;
	int		j;

	num_count = 0;
	i = 0;
	j = 0;
	while (argv[i])
	{
		if (!ft_strlen(argv[i]) || is_empty(argv[i]))
			err_exit(i != 0);
		if (ft_strchr(argv[i], ' ') != 0)
		{
			j = 0;
			temp_split = ft_split(argv[i], ' ');
			while (temp_split[j++])
				num_count++;
			free_splitstr(temp_split);
		}
		else
			num_count++;
		i++;
	}
	return (num_count);
}
