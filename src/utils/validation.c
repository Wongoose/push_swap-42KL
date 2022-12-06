/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:04:47 by zwong             #+#    #+#             */
/*   Updated: 2022/12/06 17:50:43 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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

// Loops through the input string
// if all of it is empty spaces ' ' then return TRUE
t_bool	is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			break ;
		i++;
	}
	if (str[i] == '\0')
		return (TRUE);
	else
		return (FALSE);
}

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

// use "long" for num to accept large input but will be validated
// Validate number by number
// if all 3 validaiton passed below, then add num to malloced Stack A
void	validate_input(t_sortvars *svars, char *num_str, int index)
{
	long	num;

	if (ft_strlen(num_str) == 0)
		putstr_err("Invalid input: No value provided!");
	num = ft_atoi(num_str);
	if (!valid_digits(num_str))
		putstr_err("Invalid input: Found invalid character!");
	if (!valid_duplicate(svars, num, index))
		putstr_err("Invalid input: Found duplicate number!");
	if (num > INT_MAX || num < INT_MIN)
		putstr_err("Invalid input: A number is out of integer range!");
	svars->stka_arr[index] = (int)num;
}
