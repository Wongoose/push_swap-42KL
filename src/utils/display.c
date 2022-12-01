/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:08:27 by zwong             #+#    #+#             */
/*   Updated: 2022/12/01 21:31:25 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// CLEAR ft_printf
void	print_stacka(t_sortvars svars)
{
	int	i;

	i = 0;
	ft_printf("========================\n");
	ft_printf("Printing stack A... (len: %d)\n", svars.stka_len);
	while (i < svars.stka_len)
		ft_printf("%d\n", svars.stka_arr[i++]);
}

void	print_stackb(t_sortvars svars)
{
	int	i;

	i = 0;
	ft_printf("========================\n");
	ft_printf("Printing stack B... (len: %d)\n", svars.stkb_len);
	while (i < svars.stkb_len)
		ft_printf("%d\n", svars.stkb_arr[i++]);
}

void	print_chunksa(t_sortvars svars, t_list *achunks)
{
	int	i;
	int	size;

	i = 0;
	ft_printf("========================\n");
	ft_printf("Printing stack A... (len: %d)\n", svars.stka_len);
	while (achunks)
	{
		size = achunks->curr_chunk->size;
		size += i;
		while (i < size)
			ft_printf("%d\n", svars.stka_arr[i++]);
		ft_printf("=========== %d <--- CHUNK END\n", i);
		achunks = achunks->next;
	}
}

void	print_chunksb(t_sortvars svars, t_list *bchunks)
{
	int	i;
	int	size;

	i = 0;
	ft_printf("========================\n");
	ft_printf("Printing stack B... (len: %d)\n", svars.stkb_len);
	while (bchunks)
	{
		size = bchunks->curr_chunk->size;
		size += i;
		while (i < size)
			ft_printf("%d\n", svars.stkb_arr[i++]);
		ft_printf("=========== %d <--- CHUNK END\n", i);
		bchunks = bchunks->next;
	}
}
