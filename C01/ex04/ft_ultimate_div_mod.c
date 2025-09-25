#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp_a;
	int	temp_b;

	temp_a = *a;
	temp_b = *b;
	*a = temp_a / temp_b;
	*b = temp_a % temp_b;
}

int main(void)
{
    int x, y;

    x = 42;
    y = 0;
    printf("Before: a=%d, a=%d\n", x, y);
    ft_ultimate_div_mod(&x, &y);
    printf("After: a=%d, b=%d\n", x, y);

    return 0;
}