/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_chunks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:22:24 by zwong             #+#    #+#             */
/*   Updated: 2022/12/01 13:04:41 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// Creates a new chunk in link list with given size
void	new_chunk(t_list **stk_chunks, int size)
{
	t_chunk	*chunk;

	chunk = malloc(sizeof(t_chunk));
	chunk->size = size;
	ft_lstadd_front(stk_chunks, ft_lstnew(chunk));
}

// Loops through chunk to see if it's sorted take input (ASCENDING, DESCENDING)
int	chunk_sorted(int *stk_arr, t_chunk *chunk, t_sortorder order)
{
	int	i;

	if (chunk->size <= 1)
		return (1);
	i = 0;
	if (order == ASC)
	{
		while (i < chunk->size)
		{
			if (stk_arr[i] > stk_arr[i + 1])
				return (0);
			i++;
		}
	}
	else if (order == DES)
	{
		while (i < chunk->size)
		{
			if (stk_arr[i] < stk_arr[i + 1])
				return (0);
			i++;
		}
	}
	return (1);
}

// SECURE BIG NUMBERS IN SUM (new algorithm)
// 1. Sum all numbers in chunk
// 2. Divide by chunk size to find exact median
// Then,
// Loop again, find smallest difference to determine median num in chunk
int	find_chunk_median(int *stk_arr, t_chunk *chunk)
{
	int		i;
	int		med_i;
	double	median;
	double	diff;
	double	sum;

	i = 0;
	sum = 0;
	while (i < chunk->size)
		sum += ((double)stk_arr[i++] / INT_MAX);
	median = sum / chunk->size;
	median *= INT_MAX;
	i = 0;
	diff = ft_topositive(stk_arr[i] - median);
	while (i < chunk->size)
	{
		if (ft_topositive(stk_arr[i] - median) <= diff)
		{
			diff = ft_topositive(stk_arr[i] - median);
			med_i = i;
		}
		i++;
	}
	return (stk_arr[med_i]);
}
