#include "bsq.h"

void	put_err(void)
{
	write(1, "map error\n", 10);
}

int	main(int argc, char **argv)
{
	int	i;
	int	fd;

	if (argc == 1)
	{
		if (!process_file(0))
			return (put_err(), 1);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd < 0 || !process_file(fd))
				put_err();
			if (fd >= 0)
				close(fd);
			if (i + 1 < argc)
				write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
