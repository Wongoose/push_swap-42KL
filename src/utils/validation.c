#include "../../push_swap.h"

int	valid_duplicate(t_stacks *stacks, int num, int i)
{
	i--;
	while(i >= 0)
	{
		if (stacks->stka_arr[i] == num)
			return (0);
		i--;
	}
	return (1);
}

int	valid_digits(char *num)
{
	if (*num == '-')
		num++;
	while (*num)
	{
		if (!ft_isdigit(*num))
			return (0);
		num++;
	}
	return (1);
}
