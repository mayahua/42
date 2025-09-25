#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

void	ft_putchar(char c) 
{ 
	write(1, &c, 1); 
}

void	ft_putstr(char *s)
{ 
	while (*s) 
		write(1, s++, 1); 
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_putstr(ft_strlowcase(argv[1]));
		ft_putchar('\n');
	}
	return (0);
}
