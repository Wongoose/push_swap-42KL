/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:18:54 by zwong             #+#    #+#             */
/*   Updated: 2022/11/29 16:19:52 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	insert_limits(t_sortvars *svars, t_stktype type)
{
	int	b_num;

	b_num = svars->stkb_arr[0];
	if (b_num < svars->stka_arr[0])
	{
		if (type == STK_A)
			pa(svars, 0);
		else
			pb(svars, 0);
		return (1);
	}
	else if (b_num > svars->stka_arr[svars->stka_len - 1])
	{
		if (type == STK_A)
			pa(svars, 0);
		else
			pb(svars, 0);
		if (type == STK_A)
			ra(svars, 0);
		else
			rb(svars, 0);
		return (1);
	}
	return (0);
}

void	insert_front(t_sortvars *svars, int i, t_stktype type)
{
	int	count;

	count = 0;
	while (count <= i)
	{
		if (type == STK_A)
			ra(svars, 0);
		else
			rb(svars, 0);
		count++;
	}
	if (type == STK_A)
		pa(svars, 0);
	else
		pb(svars, 0);
	while (count > 0)
	{
		if (type == STK_A)
			rra(svars, 0);
		else
			rrb(svars, 0);
		count--;
	}
}

void	insert_back(t_sortvars *svars, int i, t_stktype type)
{
	int	count;

	count = 0;
	while (count < svars->stka_len - (i + 1))
	{
		if (type == STK_A)
			rra(svars, 0);
		else
			rrb(svars, 0);
		count++;
	}
	if (type == STK_A)
		pa(svars, 0);
	else
		pb(svars, 0);
	while (count >= 0)
	{
		if (type == STK_A)
			ra(svars, 0);
		else
			rb(svars, 0);
		count--;
	}
}

// Find correct spot, rotate stack, push. SIMPLE (but code is not)
void	find_and_insert(t_sortvars *svars, t_stktype type, int insert_num)
{
	int	i;
	int	*insert_arr;
	int	stk_len;

	if (insert_limits(svars, type))
		return ;
	i = 0;
	if (type == STK_A)
		insert_arr = svars->stka_arr;
	else
		insert_arr = svars->stkb_arr;
	while (!(insert_num > insert_arr[i] && insert_num < insert_arr[i + 1]))
			i++;
	if (type == STK_A)
		stk_len = svars->stka_len;
	else
		stk_len = svars->stkb_len;
	if (i < stk_len / 2)
		insert_front(svars, i, type);
	else if (i >= stk_len / 2)
		insert_back(svars, i, type);
}
