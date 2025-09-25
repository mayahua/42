#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	issafe(int board[10], int col, int row)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if ((board[i] == row)
			|| (col - i == row - board[i])
			|| (col - i == board[i] - row))
			return (0);
		i++;
	}
	return (1);
}

void	solve(int board[10], int col, int *count)
{
	int	row;
	int	i;

	if (col == 10)
	{
		i = 0;
		while (i < 10)
		{
			ft_putchar(board[i] + '0');
			i++;
		}
		ft_putchar('\n');
		(*count)++;
		return ;
	}
	row = 0;
	while (row < 10)
	{
		if (issafe(board, col, row))
		{
			board[col] = row;
			solve(board, col + 1, count);
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	count;
	int	col;

	count = 0;
	col = 0;
	solve(board, col, &count);
	return (count);
}

int	main(void)
{
	printf("%d", ft_ten_queens_puzzle());
	return (0);
}
