/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:50:03 by zwong             #+#    #+#             */
/*   Updated: 2022/08/24 20:50:03 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*remove_line_from_buff(char *content_buff)
{
	int		src_i;
	int		dst_i;
	char	*extra_str;

	src_i = 0;
	while (content_buff[src_i] && content_buff[src_i] != '\n')
		src_i++;
	if (!content_buff[src_i])
	{
		free(content_buff);
		return (NULL);
	}
	extra_str = malloc(sizeof(char) * (ft_strlen(content_buff) - src_i + 1));
	if (!extra_str)
		return (NULL);
	src_i++;
	dst_i = 0;
	while (content_buff[src_i])
		extra_str[dst_i++] = content_buff[src_i++];
	extra_str[dst_i] = 0;
	free(content_buff);
	return (extra_str);
}

char	*read_line(char *content_buff)
{
	int		i;
	char	*line;

	i = 0;
	if (!content_buff[i])
		return (NULL);
	while (content_buff[i] && content_buff[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (content_buff[i])
	{
		line[i] = content_buff[i];
		i++;
		if (content_buff[i - 1] == '\n')
			break ;
	}
	line[i] = 0;
	return (line);
}

char	*read_file(int fd, char *content_buff)
{
	char	*read_buff;
	int		read_size;

	read_buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buff)
		return (NULL);
	read_size = 1;
	while (read_size != 0)
	{
		read_size = read(fd, read_buff, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(read_buff);
			return (NULL);
		}
		read_buff[read_size] = 0;
		content_buff = gnl_strjoin(content_buff, read_buff);
		if (ft_strchr(read_buff, '\n'))
			break ;
	}
	free(read_buff);
	return (content_buff);
}

char	*get_next_line(int fd)
{
	static char	*content_buff;
	char		*current_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	content_buff = read_file(fd, content_buff);
	if (!content_buff)
		return (NULL);
	current_line = read_line(content_buff);
	content_buff = remove_line_from_buff(content_buff);
	return (current_line);
}
