/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucao <lucao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:39:49 by lucao             #+#    #+#             */
/*   Updated: 2025/09/24 19:34:56 by lucao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>

typedef struct s_map
{
	int		cols;
	int		rows;
	char	obst;
	char	emp;
	char	full;
	char	*status;
}	t_map;

typedef struct s_sol
{
	int	nrow;
	int	ncol;
	int	len;
}	t_sol;

char	*realloc_buf(char *line, int len, int *size);
char	*line_result(int len, char *line);
char	*get_line(int fd);
int		process_file(int fd);

int		check_valid_line(char *line, t_map *m);
int		get_map(int fd, t_map *m);
int		get_rem_rows(int fd, t_map *m);
int		get_header(char *line, t_map *m);

void	update_solution(t_sol *s, int n, int ncol, int nrow);
void	solve_bsq_row(t_map *m, t_sol *s, int *rowdata, int nrow);
int		solve_bsq(t_map *m, t_sol *s);
void	print_solution(t_map *m, t_sol *s);

int		get_min(int a, int b, int c);
int		ft_strlen(char *str);
void	ft_putchar(char c);
int		ft_printable(char c);
int		get_number(char *line, int *nb);

#endif
