#include "bsq.h"

char	*realloc_buf(char *line, int len, int *size)
{
	int		newsize;
	char	*buf;
	int		i;

	newsize = *size * 2;
	buf = (char *)malloc(sizeof(char) * newsize);
	if (!buf)
		return (free(line), NULL);
	i = 0;
	while (i < len)
	{
		buf[i] = line[i];
		i++;
	}
	free(line);
	*size = newsize;
	return (buf);
}

char	*line_result(int len, char *line)
{
	if (len == 0)
		return (free(line), NULL);
	line[len] = '\0';
	return (line);
}

char	*get_line(int fd)
{
	char	*line;
	int		len;
	char	c;
	int		size;

	size = 128;
	line = (char *)malloc(sizeof(char) * size);
	if (!line)
		return (NULL);
	len = 0;
	while (read(fd, &c, 1) == 1)
	{
		if (c == '\n')
			break ;
		if (len + 1 >= size)
		{
			line = realloc_buf(line, len, &size);
			if (!line)
				return (NULL);
		}
		line[len++] = c;
	}
	return (line_result(len, line));
}

int	process_file(int fd)
{
	char	*header;
	t_map	m;
	t_sol	s;

	header = get_line(fd);
	if (!header)
		return (0);
	if (!get_header(header, &m))
		return (free(header), 0);
	free(header);
	m.status = NULL;
	m.cols = 0;
	if (!get_map(fd, &m))
		return (free(m.status), 0);
	if (!solve_bsq(&m, &s))
		return (free(m.status), 0);
	print_solution(&m, &s);
	free(m.status);
	return (1);
}
