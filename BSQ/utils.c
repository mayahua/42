#include "bsq.h"

int	get_min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= a && b <= c)
		return (b);
	else if (c <= a && c <= b)
		return (c);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	get_number(char *line, int *nb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (line[0] == '0')
		return (0);
	while (line[i] >= '0' && line[i] <= '9')
	{
		j = j * 10 + (line[i] - '0');
		i++;
	}
	*nb = j;
	return (i);
}

int	ft_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
