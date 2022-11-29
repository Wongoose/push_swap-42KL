/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:21:16 by zwong             #+#    #+#             */
/*   Updated: 2022/11/29 16:21:44 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ra(t_sortvars *svars, t_chunk *chunk)
{
	int	swap_count;

	ft_putstr_fd("ra\n", svars->log_fd);
	swap_count = 0;
	while (swap_count < svars->stka_len - 1)
	{
		ft_swap(&svars->stka_arr[swap_count], &svars->stka_arr[swap_count + 1]);
		swap_count++;
	}
	if (chunk)
		chunk->size--;
}

void	rb(t_sortvars *svars, t_chunk *chunk)
{
	int	swap_count;

	ft_putstr_fd("rb\n", svars->log_fd);
	swap_count = 0;
	while (swap_count < svars->stkb_len - 1)
	{
		ft_swap(&svars->stkb_arr[swap_count], &svars->stkb_arr[swap_count + 1]);
		swap_count++;
	}
	if (chunk)
		chunk->size--;
}

void	rr(t_sortvars *svars, t_chunk *chunk)
{
	ra(svars, chunk);
	rb(svars, chunk);
}
