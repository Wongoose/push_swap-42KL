/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:21:49 by zwong             #+#    #+#             */
/*   Updated: 2022/12/02 15:04:56 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sa(t_sortvars *svars, t_bool print)
{
	if (print)
		ft_putstr_fd("sa\n", svars->log_fd);
	if (svars->stka_len <= 1)
		return ;
	ft_swap(&svars->stka_arr[0], &svars->stka_arr[1]);
}

void	sb(t_sortvars *svars, t_bool print)
{
	if (print)
		ft_putstr_fd("sb\n", svars->log_fd);
	if (svars->stkb_len <= 1)
		return ;
	ft_swap(&svars->stkb_arr[0], &svars->stkb_arr[1]);
}

void	ss(t_sortvars *svars, t_bool print)
{
	if (print)
		ft_putstr_fd("ss\n", svars->log_fd);
	sa(svars, 0);
	sb(svars, 0);
}
