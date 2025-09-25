#include <stdio.h>

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

int main(void)
{
    int value;

    value = 0;
    printf("Before: %d\n", value);

    ft_ft(&value);

    printf("After: %d\n", value);

    return 0;
}
