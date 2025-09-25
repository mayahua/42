#include <unistd.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dup;

	len = 0;
	while (src[len] != 0)
		len++;
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (0);
	i = 0;
	while (i < len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	main(int argc, char **argv)
{
	char	*cp;
	int		i;

	if (argc == 2)
	{
		cp = ft_strdup(argv[1]);
		if (cp)
		{
			i = 0;
			while (cp[i])
			{
				write(1, &cp[i], 1);
				i++;
			}
			free(cp);
		}
	}
	return (0);
}
