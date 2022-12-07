/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:06:46 by zwong             #+#    #+#             */
/*   Updated: 2022/12/07 17:58:06 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	err_exit(char *err)
{
	(void)err;
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	putstr_err(char *err)
{
	(void)err;
	ft_putstr_fd("Error\n", 2);
	// ft_putstr_fd(err, 2);
	exit(1);
}
