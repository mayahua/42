#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	x;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	x = nb % 10 + '0';
	write(1, &x, 1);
}
