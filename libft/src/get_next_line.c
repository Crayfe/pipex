/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <cayuso-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:28:45 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/10/09 18:46:47 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

char	*read_buffer(char *buffer, char c)
{
	char	*next_line;
	int		pos;
	int		i;

	pos = gnl_strlen(buffer, c);
	if (c == '\n')
		next_line = gnl_substr(buffer, 0, pos + 1);
	else
		next_line = gnl_substr(buffer, 0, pos);
	i = 0;
	if (gnl_strlen(buffer + pos + 1, 0))
	{
		while (buffer[pos + i + 1])
		{
			buffer[i] = buffer[pos + i + 1];
			i++;
		}
		gnl_memset(buffer + i, 0, BUFFER_SIZE + 1 - i);
	}
	else
		gnl_memset(buffer, 0, BUFFER_SIZE + 1);
	return (next_line);
}

char	*read_endcases(char *buffer, char *next_line, char *to_free)
{
	if (gnl_strlen(buffer, 0))
	{
		if (gnl_strchr(buffer, '\n'))
			to_free = read_buffer(buffer, '\n');
		else
			to_free = read_buffer(buffer, 0);
		next_line = gnl_strjoin(next_line, to_free);
		free(to_free);
	}
	else if (*next_line == 0)
	{
		free(next_line);
		next_line = 0;
	}
	return (next_line);
}

char	*read_line(char *buffer, char *next_line, int fd, int rd_chars)
{
	char	*to_free;

	rd_chars = read(fd, buffer, BUFFER_SIZE);
	while (rd_chars == BUFFER_SIZE && !gnl_strchr(buffer, '\n'))
	{
		next_line = gnl_strjoin(next_line, buffer);
		gnl_memset(buffer, 0, BUFFER_SIZE + 1);
		rd_chars = read(fd, buffer, BUFFER_SIZE);
	}
	if (rd_chars < 0)
	{
		gnl_memset(buffer, 0, BUFFER_SIZE + 1);
		free(next_line);
		next_line = 0;
	}
	else if (rd_chars >= 0 && rd_chars < BUFFER_SIZE)
		next_line = read_endcases(buffer, next_line, 0);
	else
	{
		to_free = read_buffer(buffer, '\n');
		next_line = gnl_strjoin(next_line, to_free);
		free(to_free);
	}
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*next_line;
	char		*to_free;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		gnl_memset(buffer, 0, BUFFER_SIZE + 1);
		return (0);
	}
	next_line = malloc(1);
	*next_line = 0;
	if (gnl_strlen(buffer, 0))
	{
		to_free = next_line;
		if (gnl_strchr(buffer, '\n'))
			next_line = read_buffer(buffer, '\n');
		else
			next_line = read_buffer(buffer, 0);
		free(to_free);
	}
	if (next_line && gnl_strchr(next_line, '\n'))
		return (next_line);
	else
		next_line = read_line(buffer, next_line, fd, 0);
	return (next_line);
}
