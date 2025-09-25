#include <unistd.h>

void	ft_is_negative(int n)
{
	char	x;

	if (n < 0)
		x = 'N';
	else
		x = 'P';
	write(1, &x, 1);
}
