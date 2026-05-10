#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	while (*str != '\0')
	{
		if (!(*str >= 32 && *str <= 126))
			return (0);
		str++;
	}
	return (1);
}

void	ft_putchar(char c) 
{ 
	write(1, &c, 1); 
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_putnbr(ft_str_is_printable(argv[1]));
		ft_putchar('\n');
	}
}
