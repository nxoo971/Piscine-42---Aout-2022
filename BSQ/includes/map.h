/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:06:52 by lkrief            #+#    #+#             */
/*   Updated: 2022/08/31 23:26:28 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct t_info
{
	int		nb_lines;
	int		nb_cols;
	char	ch[4];
}t_info;

typedef struct t_square
{
	int	size;
	int	x;
	int	y;
}t_square;

typedef struct t_point
{
	int	i;
	int	j;
}t_point;

//t_info.c
void	ft_putchar(char c);
void	ui_putnbr(int n);
void	print_info(t_info *info);

//affichage.c
int		is_obstacle(int **tab, int i, int j);
void	print_solve(int **tab, t_info *info, t_square *square);
void	print_square(t_square *square);

//free.c
int		free_data(void *data);
void	free_info(t_info *info);
void	*free_tab_buf(int **tab, char *buf, int n);
void	*free_square_point(t_square *square, t_point *point);
void	*free_points(t_point *point1, t_point *point2);
void	*free_all(t_info *info, t_square *square, int **tab);

//free2.c
int		free_tab_buf_int(int **tab, char *buf, int n);

//check.c
int		ui_atoi(char *s, int n);
int		ft_newline(char *str);
t_info	*check_first_line(char *file);
t_info	*check_consign(const char *s, t_info *info, int end);
int		len_line(char *file, t_info *info);
int		belongs(char c, t_info *info);
int		**init_map(char *file, t_info *info, int i);
int		**check_map(char *file, t_info *info, int **tab, char *buf);

//point_square.c
t_point	*init_point(t_point *point, int i, int j);

//algo.c
void	preparation(int **tab, t_info *info);
int		ft_value(int **tab, t_point *origin, t_point *courant);
int		bsq(char *file);

//utils.c
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);
char	*ft_strdup(char *s1, char *s2, int size);
char	*ft_strncat(char *dst, char *src, int size);

//utils2.c
int		print_error(void);
#endif
