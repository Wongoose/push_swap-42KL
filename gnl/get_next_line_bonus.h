/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:43:22 by zwong             #+#    #+#             */
/*   Updated: 2022/08/25 10:43:22 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2000
# endif

char	*get_next_line(int fd);
char	*ft_strchr(char *str, char c);
char	*gnl_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
void	*gnl_calloc(size_t size, size_t len);

#endif