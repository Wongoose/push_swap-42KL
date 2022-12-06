/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:12:40 by zwong             #+#    #+#             */
/*   Updated: 2022/12/02 14:53:52 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	sort_2(t_sortvars *svars)
{
	if (is_sorted(*svars))
		return (1);
	if (svars->stka_len == 2)
	{
		sa(svars, TRUE);
		return (1);
	}
	return (0);
}

// Sort Stack A when number is less than 3 (hardcoded 5 scenarios)
// 3! - 1 (sorted)
void	sort_3(t_sortvars *svars)
{
	int	num1;
	int	num2;
	int	num3;

	if (sort_2(svars))
		return ;
	num1 = svars->stka_arr[0];
	num2 = svars->stka_arr[1];
	num3 = svars->stka_arr[2];
	if ((num1 > num2 && num2 < num3) && (num3 > num1))
		sa(svars, TRUE);
	else if ((num1 > num2 && num2 > num3) && (num3 < num1))
	{
		sa(svars, TRUE);
		rra(svars, 0, TRUE);
	}
	else if ((num1 > num2 && num2 < num3) && (num3 < num1))
		ra(svars, 0, TRUE);
	else if ((num1 < num2 && num2 > num3) && (num3 > num1))
	{
		sa(svars, TRUE);
		ra(svars, 0, TRUE);
	}
	else if ((num1 < num2 && num2 > num3) && (num3 < num1))
		rra(svars, 0, TRUE);
}
