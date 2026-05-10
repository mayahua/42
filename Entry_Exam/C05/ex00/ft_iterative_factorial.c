#include <stdio.h>
#include <stdlib.h>

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	j;

	if (nb < 0)
		return (0);
	i = 1;
	j = 1;
	while (i <= nb)
	{
		j *= i;
		i++;
	}
	return (j);
}

int	main(int argc, char **argv)
{
	(void)argc;
	printf("%d", ft_iterative_factorial(atoi(argv[1])));
	return (0);
}
