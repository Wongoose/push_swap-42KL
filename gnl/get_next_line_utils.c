/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:51:59 by zwong             #+#    #+#             */
/*   Updated: 2022/08/24 20:51:59 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*gnl_calloc(size_t size, size_t len)
{
	void			*res;
	unsigned char	*dst;
	size_t			i;

	res = malloc(size * len);
	if (!res)
		return (NULL);
	dst = res;
	i = 0;
	while (i++ < size * len)
		*dst++ = 0;
	return (res);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	total_size;
	size_t	i;
	size_t	j;

	if (!s1)
		s1 = gnl_calloc(sizeof(char), 1);
	if (!s1 || !s2)
		return (NULL);
	total_size = ft_strlen(s1) + ft_strlen(s2);
	new_str = malloc(sizeof(char) * (total_size + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = 0;
	free(s1);
	return (new_str);
}
