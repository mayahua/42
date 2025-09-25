#include "bsq.h"

void	update_solution(t_sol *s, int n, int ncol, int nrow)
{
	if (n > s->len)
	{
		s->len = n;
		s->ncol = ncol - 1;
		s->nrow = nrow;
	}
}

void	solve_bsq_row(t_map *m, t_sol *s, int *rowdata, int nrow)
{
	int	ncol;
	int	left;
	int	leftabove;
	int	above;
	int	n;

	ncol = 1;
	left = 0;
	leftabove = 0;
	while (ncol < m->cols + 1)
	{
		above = rowdata[ncol];
		if (m->status[nrow * (m->cols + 1) + ncol - 1] == m->obst)
			n = 0;
		else
			n = get_min(left, above, leftabove) + 1;
		rowdata[ncol] = n;
		update_solution(s, n, ncol, nrow);
		left = n;
		leftabove = above;
		ncol++;
	}
}

int	solve_bsq(t_map *m, t_sol *s)
{
	int	nrow;
	int	ncol;
	int	*rowdata;

	nrow = 0;
	if (m->rows < 1 || m->cols < 1)
		return (0);
	rowdata = (int *)malloc(sizeof(int) * (m->cols + 1));
	if (!rowdata)
		return (0);
	ncol = 0;
	while (ncol < m->cols + 1)
		rowdata[ncol++] = 0;
	s->nrow = 0;
	s->ncol = 0;
	s->len = 0;
	while (nrow < m->rows)
	{
		solve_bsq_row(m, s, rowdata, nrow);
		nrow++;
	}
	free(rowdata);
	return (1);
}

void	print_solution(t_map *m, t_sol *s)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < m->rows)
	{
		col = 0;
		while (col < m->cols)
		{
			c = m->status[row * (m->cols + 1) + col];
			if (c == m->obst)
				ft_putchar(m->obst);
			else if (row >= s->nrow - (s->len - 1) && row <= s->nrow
				&& col >= s->ncol - (s->len - 1) && col <= s->ncol)
				ft_putchar(m->full);
			else
				ft_putchar(m->emp);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
