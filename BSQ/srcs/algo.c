/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:48:59 by lkrief            #+#    #+#             */
/*   Updated: 2022/08/31 23:25:55 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../includes/map2.h"

void	preparation(int **tab, t_info *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++i < info->nb_lines)
		tab[i][0] += tab[i - 1][0];
	while (++j < info->nb_cols)
		tab[0][j] += tab[0][j - 1];
	i = 0;
	j = 0;
	while (++i < info->nb_lines)
	{
		j = 0;
		while (++j < info->nb_cols)
			tab[i][j] += tab[i][j - 1] + tab[i - 1][j] - tab[i - 1][j - 1];
	}
}

//On suppose que tab est correctement initialise, on renvoie un t_square sur
//le biggest square
t_square	*big_square(int **tab, t_info *info)
{
	t_point		*point;
	t_square	*square;

	square = malloc(sizeof(*square));
	point = malloc(sizeof(*point));
	if (!square || !point)
		return (free_square_point(square, point));
	square = i_s(square, 0, 0, 0);
	point = init_point(point, 0, 0);
	while (point->i < info->nb_lines - square->size)
	{
		point->j = 0;
		while (point->j < info->nb_cols - square->size)
		{
			square = calc(tab, point, info, square);
			(point->j)++;
		}
		(point->i)++;
	}
	free(point);
	return (square);
}

int	ft_value(int **tab, t_point *origin, t_point *courant)
{
	int	z;

	if (origin->i == -1 && origin->j == -1)
		z = tab[courant->i][courant->j];
	else if (origin->i == -1)
		z = tab[courant->i][courant->j] - tab[courant->i][origin->j];
	else if (origin->j == -1)
		z = tab[courant->i][courant->j] - tab[origin->i][courant->j];
	else
	{
		z = tab[courant->i][courant->j] + tab[origin->i][origin->j];
		z = z - tab[courant->i][origin->j] - tab[origin->i][courant->j];
	}
	return (z);
}

//Pour le point en argument on test la taille du plus grand carre partant de
//celui-ci. Si cette taille est > que la size de square, on met a jour square.
t_square	*calc(int **tab, t_point *point, t_info *info, t_square *square)
{
	t_point	*origin;
	t_point	*courant;
	int		z;
	int		n;

	origin = malloc(sizeof(*origin));
	courant = malloc(sizeof(*courant));
	if (!origin || !courant)
		return (free_points(origin, courant));
	n = 0;
	z = 0;
	*courant = *point;
	origin = init_point(origin, courant->i - 1, courant->j - 1);
	while (z == 0 && courant->i < info->nb_lines && courant->j < info->nb_cols)
	{
		z = ft_value(tab, origin, courant);
		n = n + (z == 0);
		(courant->i)++;
		(courant->j)++;
	}
	free_points(origin, courant);
	if (n > square->size)
		return (i_s(square, n, point->i, point->j));
	return (square);
}

int	bsq(char *file)
{
	t_info			*info;
	int				**tab;
	t_square		*square;

	info = check_first_line(file);
	if (info != NULL && len_line(file, info) > 0)
	{
		tab = init_map(file, info, 0);
		if (tab)
		{
			preparation(tab, info);
			square = big_square(tab, info);
			if (square)
				print_solve(tab, info, square);
			free_all(info, square, tab);
		}
		else
		{
			free_all(info, NULL, NULL);
			return (print_error());
		}
	}
	else
		return (print_error());
	return (1);
}
