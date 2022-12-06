/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:21:15 by zwong             #+#    #+#             */
/*   Updated: 2022/12/06 17:42:20 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	check_format(const char flag, va_list args, int *char_count)
{
	if (flag == 'c')
		*char_count += ft_putchar(va_arg(args, int));
	else if (flag == 's')
		ft_putstr(va_arg(args, char *), char_count);
	else if (flag == 'd' || flag == 'i')
		ft_putnbr(va_arg(args, int), char_count, flag);
	else if (flag == 'u')
		ft_putunsigned(va_arg(args, unsigned int), char_count);
	else if (flag == 'x' || flag == 'X')
		ft_puthex(va_arg(args, unsigned int), char_count, flag);
	else if (flag == 'p')
		ft_putptr(va_arg(args, uintptr_t), char_count);
	else if (flag == '%')
		*char_count += ft_putchar('%');
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		char_count;
	va_list	args;

	i = 0;
	char_count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			check_format(str[++i], args, &char_count);
		}
		else
		{
			char_count += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (char_count);
}
