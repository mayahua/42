#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

int main(void)
{
    printf("Length of \"abcde\" = %d\n", ft_strlen("abcde"));
    printf("Length of \"42\" = %d\n", ft_strlen("42"));
    printf("Length of \"\" = %d\n", ft_strlen(""));
    
    return 0;
}
