#include "../push_swap.h"

int	valid_duplicate(t_stka *stka, int num, int i)
{
	i--;
	while(i >= 0)
	{
		if (stka->num_arr[i] == num)
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

void	printStackA(t_stka stka)
{
	int	i;

	i = 0;
	while (i < stka.len)
		printf("%d\n", stka.num_arr[i++]);
}