/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:17:01 by zwong             #+#    #+#             */
/*   Updated: 2022/12/06 18:42:56 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// Sort 5 numbers in Stack A
// First, push numbers to Stack B until Stack A has 3 numbers left
// From Stack B, insert to correct position
void	sort_5(t_sortvars *svars)
{
	int	transfer;
	int	i;

	transfer = svars->stka_len - 3;
	i = transfer;
	while (i--)
		pb(svars, 0, TRUE);
	sort_3(svars);
	while (svars->stkb_len != 0)
		find_and_insert(svars, svars->stkb_arr[0]);
}
