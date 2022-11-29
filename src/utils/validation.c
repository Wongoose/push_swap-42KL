/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:04:47 by zwong             #+#    #+#             */
/*   Updated: 2022/11/29 16:06:26 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// int i is the latest position of number being validated
// i-- to start checking from previous position in Stack A array
int	valid_duplicate(t_sortvars *svars, int num, int i)
{
	i--;
	while (i >= 0)
	{
		if (svars->stka_arr[i] == num)
			return (0);
		i--;
	}
	return (1);
}

// Check whether character is within 0-9 digit range
// using ft_isdigit()
int	valid_digits(const char *num)
{
	if (*num == '-' && ft_strlen(num) > 1)
		num++;
	while (*num)
	{
		if (!ft_isdigit(*num))
			return (0);
		num++;
	}
	return (1);
}

int	is_sorted(t_sortvars svars)
{
	int	i;

	i = 0;
	while (i < svars.stka_len - 1)
	{
		if (svars.stka_arr[i] > svars.stka_arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
