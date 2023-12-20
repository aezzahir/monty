/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aezzahir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:29:27 by aezzahir          #+#    #+#             */
/*   Updated: 2023/11/29 19:05:26 by aezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monty.h"

ssize_t	read_buffer(int fd, char *buf, char **saved)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		temp = ft_strjoin(*saved, buf);
		free(*saved);
		*saved = temp;
	}
	return (bytes_read);
}

char	*extract_line(ssize_t bytes_read, char *pos_newline, char **saved)
{
	char	*line;
	char	*temp;

	line = NULL;
	if (pos_newline && bytes_read > 0)
	{
		line = ft_strndup(*saved, pos_newline - *saved + 1);
		temp = ft_strndup(pos_newline + 1, ft_strlen(pos_newline + 1));
		free(*saved);
		*saved = temp;
		return (line);
	}
	else if (bytes_read == 0 && *saved && **saved != '\0')
		line = ft_strndup(*saved, ft_strlen(*saved) + 1);
	free(*saved);
	*saved = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*buf;
	char		*line;
	char		*pos_newline;
	ssize_t		bytes_read;

	bytes_read = 1;
	if (!saved)
		saved = ft_strndup("", 0);
	pos_newline = ft_strchr(saved, '\n');
	while (pos_newline == NULL)
	{
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (NULL);
		bytes_read = read_buffer(fd, buf, &saved);
		free(buf);
		if (bytes_read <= 0)
			break ;
		pos_newline = ft_strchr(saved, '\n');
	}
	line = extract_line(bytes_read, pos_newline, &saved);
	return (line);
}
