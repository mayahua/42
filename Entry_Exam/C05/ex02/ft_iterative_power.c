#include <stdio.h>
#include <stdlib.h>

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	j;

	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	i = 0;
	j = 1;
	while (i < power)
	{
		j *= nb;
		i++;
	}
	return (j);
}

int	main(int argc, char **argv)
{
	(void)argc;
	printf("%d", ft_iterative_power(atoi(argv[1]), atoi(argv[2])));
	return (0);
}
