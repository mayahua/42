/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhua <mhua@student.42london.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-23 16:27:27 by mhua              #+#    #+#             */
/*   Updated: 2026-01-23 16:27:27 by mhua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*remainder[MAX_FD];
	char		*buffer;
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(remainder[fd], '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		remainder[fd] = strjoin_free(remainder[fd], buffer);
	}
	line = get_line(remainder[fd]);
	remainder[fd] = remainder_update(remainder[fd]);
	free(buffer);
	return (line);
}
