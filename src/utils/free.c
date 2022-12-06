/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:05:13 by zwong             #+#    #+#             */
/*   Updated: 2022/12/06 17:49:56 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	del_chunk(void *chunk)
{
	free(chunk);
}

void	free_svars(t_sortvars *svars)
{
	free(svars->stka_arr);
	svars->stkb_arr -= (svars->stka_len - 1);
	free(svars->stkb_arr);
	ft_lstclear(&svars->stka_chunks, del_chunk);
	ft_lstclear(&svars->stkb_chunks, del_chunk);
}

void	free_splitstr(char **splitstr)
{
	int	i;

	i = 0;
	while (splitstr[i])
	{
		free(splitstr[i]);
		i++;
	}
	free(splitstr);
}
