/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:04:30 by zwong             #+#    #+#             */
/*   Updated: 2022/12/07 19:32:31 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// If is_sorted, nothing to do.
// Either one of these functions:
// 1. Sort smaller than 3
// 2. Sort smaller than 5
// 3. Sort larger than 5 with mediansort
int	main(int argc, char **argv)
{
	t_sortvars	svars;

	if (argc == 1)
		return (0);
	argv++;
	init_stacks(&svars, count_inputs(argv));
	init_validation(&svars, argv);
	if (is_sorted(svars))
		return (0);
	if (svars.stka_len <= 3)
		sort_3(&svars);
	else if (svars.stka_len <= 5)
		sort_5(&svars);
	else if (svars.stka_len > 5)
		sort_large(&svars);
	free_svars(&svars);
	return (0);
}
