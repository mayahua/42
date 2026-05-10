#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

int main(void)
{
    int q, r;
    int a, b;

    a = 42;
    b = 0;
    ft_div_mod(a, b, &q, &r);
    printf("%d / %d : div = %d, mod = %d\n", a, b, q, r);

    return 0;
}