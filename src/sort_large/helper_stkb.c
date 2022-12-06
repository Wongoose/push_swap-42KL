/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_stkb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:36:05 by zwong             #+#    #+#             */
/*   Updated: 2022/12/02 14:57:07 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	push_above_median(t_sortvars *svars, int median, t_chunk *chunk)
{
	int	i;
	int	count;
	int	rotate_num;

	count = 0;
	rotate_num = 0;
	while (1)
	{
		i = 0;
		while (!(svars->stkb_arr[i] > median) && i < chunk->size)
			i++;
		if (i == chunk->size)
			break ;
		rotate_num += i;
		while (i--)
			rb(svars, chunk, TRUE);
		pa(svars, chunk, TRUE);
		count++;
	}
	while (rotate_num--)
		rrb(svars, chunk, TRUE);
	return (count);
}

// add push above median END (for optimization)
int	push_chunk(t_sortvars *svars, t_chunk *chunk)
{
	int	count;

	count = 0;
	while (chunk->size != 0)
	{
		pa(svars, chunk, TRUE);
		count++;
	}
	return (count);
}
