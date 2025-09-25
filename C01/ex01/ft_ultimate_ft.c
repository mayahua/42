#include <stdio.h>

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

int main(void)
{
    int value;                     
    int *p1 = &value;
    int **p2 = &p1;
    int ***p3 = &p2;
    int ****p4 = &p3;
    int *****p5 = &p4;
    int ******p6 = &p5;
    int *******p7 = &p6;
    int ********p8 = &p7;
    int *********p9 = &p8;

    value = 0;
    printf("Before: %d\n", value);

    ft_ultimate_ft(p9);

    printf("After: %d\n", value);

    return 0;
}
