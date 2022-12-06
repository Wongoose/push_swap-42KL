/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:18:54 by zwong             #+#    #+#             */
/*   Updated: 2022/12/06 18:45:42 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	insert_limits(t_sortvars *svars)
{
	int	b_num;

	b_num = svars->stkb_arr[0];
	if (b_num < svars->stka_arr[0])
	{
		pa(svars, 0, TRUE);
		return (1);
	}
	else if (b_num > svars->stka_arr[svars->stka_len - 1])
	{
		pa(svars, 0, TRUE);
		ra(svars, 0, TRUE);
		return (1);
	}
	return (0);
}

void	insert_front(t_sortvars *svars, int i)
{
	int	count;

	count = 0;
	while (count <= i)
	{
		ra(svars, 0, TRUE);
		count++;
	}
	pa(svars, 0, TRUE);
	while (count > 0)
	{
		rra(svars, 0, TRUE);
		count--;
	}
}

void	insert_back(t_sortvars *svars, int i)
{
	int	count;

	count = 0;
	while (count < svars->stka_len - (i + 1))
	{
		rra(svars, 0, TRUE);
		count++;
	}
	pa(svars, 0, TRUE);
	if (svars->stkb_len == 1)
	{
		if ((svars->stkb_arr[0] < svars->stka_arr[0])
			&& (svars->stkb_arr[0] > svars->stka_arr[svars->stka_len - 1]))
		{
			pa(svars, 0, TRUE);
			count++;
		}
	}
	while (count >= 0)
	{
		ra(svars, 0, TRUE);
		count--;
	}
}

// Find correct spot, rotate stack, push. SIMPLE (but code is not)
void	find_and_insert(t_sortvars *svars, int num)
{
	int	i;

	if (insert_limits(svars))
		return ;
	i = 0;
	while (!(num > svars->stka_arr[i] && num < svars->stka_arr[i + 1]))
		i++;
	if (i < svars->stka_len / 2)
		insert_front(svars, i);
	else if (i >= svars->stka_len / 2)
		insert_back(svars, i);
}
