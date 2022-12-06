/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_stka.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:27:10 by zwong             #+#    #+#             */
/*   Updated: 2022/12/02 14:57:14 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	push_below_median(t_sortvars *svars, int median, t_chunk *chunk)
{
	int	i;
	int	count;
	int	rotate_num;

	count = 0;
	rotate_num = 0;
	while (1)
	{
		i = 0;
		while (!(svars->stka_arr[i] < median) && i < chunk->size)
			i++;
		if (i == chunk->size)
			break ;
		rotate_num += i;
		while (i--)
			ra(svars, chunk, TRUE);
		pb(svars, chunk, TRUE);
		count++;
	}
	while (rotate_num--)
		rra(svars, chunk, TRUE);
	return (count);
}

static void	ra_and_pb(t_sortvars *svars, int i, t_chunk *chunk)
{
	while (i--)
		ra(svars, 0, TRUE);
	pb(svars, chunk, TRUE);
}

static void	rra_and_pb(t_sortvars *svars, int i, t_chunk *chunk)
{
	while (i--)
		rra(svars, 0, TRUE);
	pb(svars, chunk, TRUE);
}

int	push_below_median_end(t_sortvars *svars, int median, t_chunk *chunk)
{
	int	start;
	int	end;
	int	count;

	count = 0;
	while (1)
	{
		start = 0;
		end = svars->stka_len - 1;
		while (!(svars->stka_arr[start] < median)
			&& start < svars->stka_len / 2)
			start++;
		while (!(svars->stka_arr[end] < median) && end >= svars->stka_len / 2)
			end--;
		if (start >= svars->stka_len / 2 && end < svars->stka_len / 2)
			break ;
		else if (start < (svars->stka_len - 1) - end
			&& start < svars->stka_len / 2)
			ra_and_pb(svars, start, chunk);
		else
			rra_and_pb(svars, svars->stka_len - end, chunk);
		count++;
	}
	return (count);
}
