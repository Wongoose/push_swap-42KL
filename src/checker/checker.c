/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:39:23 by zwong             #+#    #+#             */
/*   Updated: 2022/12/07 21:55:59 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include "../../gnl/get_next_line.h"

// Give yourself 30s, if you cannot understand this, I have no comment
void	run_command(char *cmd, t_sortvars *svars)
{
	if (!ft_strncmp(cmd, "sa\n", 3))
		sa(svars, FALSE);
	else if (!ft_strncmp(cmd, "sb\n", 4))
		sb(svars, FALSE);
	else if (!ft_strncmp(cmd, "ss\n", 4))
		ss(svars, FALSE);
	else if (!ft_strncmp(cmd, "pa\n", 4))
		pa(svars, 0, FALSE);
	else if (!ft_strncmp(cmd, "pb\n", 4))
		pb(svars, 0, FALSE);
	else if (!ft_strncmp(cmd, "ra\n", 4))
		ra(svars, 0, FALSE);
	else if (!ft_strncmp(cmd, "rb\n", 4))
		rb(svars, 0, FALSE);
	else if (!ft_strncmp(cmd, "rr\n", 4))
		rr(svars, 0, FALSE);
	else if (!ft_strncmp(cmd, "rra\n", 5))
		rra(svars, 0, FALSE);
	else if (!ft_strncmp(cmd, "rrb\n", 5))
		rrb(svars, 0, FALSE);
	else if (!ft_strncmp(cmd, "rrr\n", 5))
		rrr(svars, 0, FALSE);
	else
		err_exit(TRUE);
}

// run get_next_line() on standard input which is "0"
// this function reads all the sa, ra, pa etc..
// it will replicate the commands and check if the result is sorted
void	handle_inputs(t_sortvars *svars)
{
	char		*line;

	line = get_next_line(0);
	while (line)
	{
		run_command(line, svars);
		free(line);
		line = get_next_line(0);
	}
	if (!svars->stkb_len && svars->stka_arr && is_sorted(*svars))
		ft_putstr_fd("\033[1;32mO.K\n", 1);
	else
		ft_putstr_fd("\033[1;31mK.O\n", 1);
}

int	main(int argc, char **argv)
{
	t_sortvars	svars;

	if (argc == 1)
		return (0);
	argv++;
	init_stacks(&svars, count_inputs(argv));
	init_validation(&svars, argv);
	handle_inputs(&svars);
}
