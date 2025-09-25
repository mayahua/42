/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucao <lucao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:48:03 by lucao             #+#    #+#             */
/*   Updated: 2025/09/24 19:34:36 by lucao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	check_valid_line(char *line, t_map *m)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != m->emp && line[i] != m->obst)
			return (0);
		i++;
	}
	return (1);
}

int	get_map(int fd, t_map *m)
{
	char	*line;
	int		i;

	line = get_line(fd);
	if (!line)
		return (0);
	if (!check_valid_line(line, m))
		return (free(line), 0);
	m->cols = ft_strlen(line);
	if (m->cols < 1)
		return (free(line), 0);
	m->status = (char *)malloc((m->cols + 1) * m->rows);
	if (!m->status)
		return (free(line), 0);
	i = 0;
	while (i < m->cols)
	{
		m->status[i] = line[i];
		i++;
	}
	m->status[i] = '\n';
	free(line);
	if (!get_rem_rows(fd, m))
		return (0);
	return (1);
}

int	get_rem_rows(int fd, t_map *m)
{
	int		nrow;
	char	*line;
	int		n;
	int		i;

	nrow = 1;
	while (nrow < m->rows)
	{
		line = get_line(fd);
		if (!line)
			return (0);
		n = ft_strlen(line);
		if (n != m->cols || !check_valid_line(line, m))
			return (free(line), 0);
		i = 0;
		while (i < m->cols)
		{
			m->status[nrow * (m->cols + 1) + i] = line[i];
			i++;
		}
		m->status[nrow * (m->cols + 1) + i] = '\n';
		free(line);
		nrow++;
	}
	return (1);
}

int	get_header(char *line, t_map *m)
{
	int	i;

	i = get_number(line, &m->rows);
	if (i == 0 || !ft_printable(line[i]) || !ft_printable(line[i + 1])
		|| !ft_printable(line[i + 2]))
		return (0);
	m->emp = line[i];
	m->obst = line[i + 1];
	m->full = line[i + 2];
	if (line[i + 3] || m->emp == m->obst || m->emp == m->full
		|| m->obst == m->full || m->rows <= 0)
		return (0);
	return (1);
}
