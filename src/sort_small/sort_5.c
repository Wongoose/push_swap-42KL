/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:17:01 by zwong             #+#    #+#             */
/*   Updated: 2022/12/02 14:54:39 by zwong            ###   ########.fr       */
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
	while (transfer--)
		find_and_insert(svars, STK_A, svars->stkb_arr[0]);
}
