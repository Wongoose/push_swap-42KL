/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:53:19 by zwong             #+#    #+#             */
/*   Updated: 2022/12/06 17:49:32 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "ft_printf/includes/ft_printf.h"

typedef enum e_bool {
	TRUE = 1,
	FALSE = 0,
}	t_bool;

typedef enum e_stktype {
	STK_A = 0,
	STK_B = 1,
}	t_stktype;

typedef enum e_sortorder {
	ASC = 0,
	DES = 1,
}	t_sortorder;

// NEXT: Filter useless variables
typedef struct s_sortvars {
	int		*stka_arr;
	int		stka_len;
	int		*stkb_arr;
	int		stkb_len;
	int		log_fd;
	t_list	*stka_chunks;
	t_list	*stkb_chunks;
}	t_sortvars;

int		count_inputs(char **argv);
void	init_stacks(t_sortvars *svars, int count);
void	init_validation(t_sortvars *svars, char **argv);
int		valid_duplicate(t_sortvars *svars, int num, int i);
int		valid_digits(const char *num);
void	validate_input(t_sortvars *svars, char *num_str, int index);
t_bool	is_empty(char *str);
int		is_sorted(t_sortvars svars);
void	print_stacka(t_sortvars svars);
void	print_stackb(t_sortvars svars);
void	print_chunksb(t_sortvars svars, t_list *bchunks);
void	print_chunksa(t_sortvars svars, t_list *achunks);
void	err_exit(char *err);
void	putstr_err(char *err);
void	sa(t_sortvars *svars, t_bool print);
void	sb(t_sortvars *svars, t_bool print);
void	ss(t_sortvars *svars, t_bool print);
void	ra(t_sortvars *svars, t_chunk *chunk, t_bool print);
void	rb(t_sortvars *svars, t_chunk *chunk, t_bool print);
void	rr(t_sortvars *svars, t_chunk *chunk, t_bool print);
void	rra(t_sortvars *svars, t_chunk *chunk, t_bool print);
void	rrb(t_sortvars *svars, t_chunk *chunk, t_bool print);
void	rrr(t_sortvars *svars, t_chunk *chunk, t_bool print);
void	pa(t_sortvars *svars, t_chunk *chunk, t_bool print);
void	pb(t_sortvars *svars, t_chunk *chunk, t_bool print);
int		insert_limits(t_sortvars *svars, t_stktype type);
void	insert_front(t_sortvars *svars, int i, t_stktype type);
void	insert_back(t_sortvars *svars, int i, t_stktype type);
void	find_and_insert(t_sortvars *svars, t_stktype type, int insert_num);
void	sort_3(t_sortvars *svars);
void	sort_5(t_sortvars *svars);
void	sort_large(t_sortvars *svars);
void	new_chunk(t_list **stk_chunks, int count);
int		find_chunk_median(int *stk_arr, t_chunk *chunk);
int		chunk_sorted(int *stk_arr, t_chunk *chunk, t_sortorder order);
int		push_chunk(t_sortvars *svars, t_chunk *chunk);
int		push_above_median(t_sortvars *svars, int median, t_chunk *chunk);
int		push_below_median(t_sortvars *svars, int median, t_chunk *chunk);
int		push_below_median_end(t_sortvars *svars, int median, t_chunk *chunk);
void	free_svars(t_sortvars *svars);
void	free_splitstr(char **splitstr);

#endif