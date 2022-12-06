/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:20:38 by zwong             #+#    #+#             */
/*   Updated: 2022/12/02 15:04:56 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rra(t_sortvars *svars, t_chunk *chunk, t_bool print)
{
	int	swap_count;

	if (print)
		ft_putstr_fd("rra\n", svars->log_fd);
	swap_count = svars->stka_len - 1;
	while (swap_count > 0)
	{
		ft_swap(&svars->stka_arr[swap_count], &svars->stka_arr[swap_count - 1]);
		swap_count--;
	}
	if (chunk)
		chunk->size++;
}

void	rrb(t_sortvars *svars, t_chunk *chunk, t_bool print)
{
	int	swap_count;

	if (print)
		ft_putstr_fd("rrb\n", svars->log_fd);
	swap_count = svars->stkb_len - 1;
	while (swap_count > 0)
	{
		ft_swap(&svars->stkb_arr[swap_count], &svars->stkb_arr[swap_count - 1]);
		swap_count--;
	}
	if (chunk)
		chunk->size++;
}

void	rrr(t_sortvars *svars, t_chunk *chunk, t_bool print)
{
	if (print)
		ft_putstr_fd("rrr\n", svars->log_fd);
	rra(svars, chunk, 0);
	rrb(svars, chunk, 0);
}
