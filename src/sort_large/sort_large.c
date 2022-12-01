/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:36:42 by zwong             #+#    #+#             */
/*   Updated: 2022/12/01 13:00:54 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// NEXT create sort 3 and 5 for chunks
// USE pointer to chunks for all functions
// ADD chunk size decrement only
void	mediansort_a(t_sortvars *svars)
{
	int		median;
	int		size;
	int		i;
	t_chunk	*chunk;

	while (1)
	{
		i = 0;
		chunk = svars->stka_chunks->curr_chunk;
		if (chunk_sorted(svars->stka_arr, chunk, ASC) || chunk->size == 1)
			return ;
		if (chunk->size == 2)
		{
			if (svars->stkb_arr[0] < svars->stkb_arr[1])
				ss(svars);
			else
				sa(svars, 1);
		}
		else
		{
			median = find_chunk_median(svars->stka_arr, chunk);
			size = push_below_median(svars, median, chunk);
			new_chunk(&svars->stkb_chunks, size);
		}
	}
}

// 
void	mediansort_b(t_sortvars *svars, t_chunk *chunk)
{
	int	median;
	int	size;

	if (chunk_sorted(svars->stkb_arr, chunk, DES) || chunk->size <= 2)
		size = push_chunk(svars, chunk);
	else
	{
		median = find_chunk_median(svars->stkb_arr, chunk);
		size = push_above_median(svars, median, chunk);
	}
	new_chunk(&svars->stka_chunks, size);
}

// initializes the first set of chunks in B
// result will have all numbers in descending order in chunks
// Convert numbers from Stack A to chunks in B until 3 numbers are left
void	init_bchunks(t_sortvars *svars)
{
	int		median;
	int		size;
	t_chunk	*chunk;

	svars->stkb_chunks = 0;
	svars->stka_chunks = 0;
	new_chunk(&svars->stka_chunks, svars->stka_len);
	chunk = svars->stka_chunks->curr_chunk;
	while (svars->stka_len > 3)
	{
		median = find_chunk_median(svars->stka_arr, chunk);
		size = push_below_median_end(svars, median, chunk);
		new_chunk(&svars->stkb_chunks, size);
	}
}

// Sort large numbers using median sorting method
// This algorithm will first create a few chunk of numbers in Stack B
// The chunks are from largest to smallest
// The goal is to loop through each chunk in B and transfer it in Stack A
void	sort_large(t_sortvars *svars)
{
	t_chunk		*chunk;

	init_bchunks(svars);
	sort_3(svars);
	while (svars->stkb_chunks)
	{
		chunk = svars->stkb_chunks->curr_chunk;
		mediansort_b(svars, chunk);
		mediansort_a(svars);
		if (svars->stkb_chunks->curr_chunk->size == 0)
		{
			free(chunk);
			free(svars->stkb_chunks);
			svars->stkb_chunks = svars->stkb_chunks->next;
		}
	}
}
