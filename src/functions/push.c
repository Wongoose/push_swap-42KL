/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:20:25 by zwong             #+#    #+#             */
/*   Updated: 2022/12/02 15:04:59 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	pa(t_sortvars *svars, t_chunk *chunk, t_bool print)
{
	if (print)
		ft_putstr_fd("pa\n", svars->log_fd);
	if (svars->stkb_len == 0)
		return ;
	if (svars->stka_len != 0)
		svars->stka_arr -= 1;
	svars->stka_arr[0] = svars->stkb_arr[0];
	svars->stkb_arr[0] = 0;
	svars->stka_len++;
	svars->stkb_len--;
	if (svars->stkb_len != 0)
		svars->stkb_arr += 1;
	if (chunk)
		chunk->size--;
}

void	pb(t_sortvars *svars, t_chunk *chunk, t_bool print)
{
	if (print)
		ft_putstr_fd("pb\n", svars->log_fd);
	if (svars->stka_len == 0)
		return ;
	if (svars->stkb_len != 0)
		svars->stkb_arr -= 1;
	svars->stkb_arr[0] = svars->stka_arr[0];
	svars->stka_arr[0] = 0;
	svars->stkb_len++;
	svars->stka_len--;
	if (svars->stka_len != 0)
		svars->stka_arr += 1;
	if (chunk)
		chunk->size--;
}
