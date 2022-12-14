/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:06:46 by zwong             #+#    #+#             */
/*   Updated: 2022/12/07 22:13:59 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	err_exit(t_bool display)
{
	if (display)
		ft_putstr_fd("Error\n", 2);
	exit(0);
}
