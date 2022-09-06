/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 22:17:19 by lkrief            #+#    #+#             */
/*   Updated: 2022/08/31 21:16:00 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../includes/map2.h"

void	print_info(t_info *info)
{
	if (info)
	{
		write(1, "Number of lines:   ", 19);
		ui_putnbr(info->nb_lines);
		write(1, "\nNumber of columns: ", 20);
		ui_putnbr(info->nb_cols);
		write(1, "\nEmpty char:        '", 21);
		ft_putchar(info->ch[0]);
		write(1, "'\nObstacle char:     '", 22);
		ft_putchar(info->ch[1]);
		write(1, "'\nFull char:         '", 22);
		ft_putchar(info->ch[2]);
		write(1, "'\n\n", 3);
	}
}

void	print_square(t_square *square)
{
	write(1, "i = ", 4);
	ui_putnbr(square->x);
	write(1, ", j = ", 6);
	ui_putnbr(square->y);
	write(1, ", size = ", 9);
	ui_putnbr(square->size);
	write(1, "\n", 1);
}

int	is_obstacle(int **tab, int i, int j)
{
	int	z;

	if (i == 0 && j == 0)
		z = tab[0][0];
	else if (i == 0)
		z = tab[0][j] - tab[0][j - 1];
	else if (j == 0)
		z = tab[i][0] - tab[i - 1][0];
	else
		z = tab[i][j] + tab[i - 1][j - 1] - tab[i - 1][j] - tab[i][j - 1];
	return (z);
}

void	print_first_line(t_info *info)
{
	if (info)
	{
		ui_putnbr(info->nb_lines);
		ft_putchar(info->ch[0]);
		ft_putchar(info->ch[1]);
		ft_putchar(info->ch[2]);
		write(1, "\n", 1);
	}
}

void	print_solve(int **tab, t_info *info, t_square *square)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	print_first_line(info);
	while (i < info->nb_lines)
	{
		j = 0;
		while (j < info->nb_cols)
		{
			if (is_obstacle(tab, i, j))
				ft_putchar(info->ch[1]);
			else if (i >= square->x && i < square->x + square->size
				&& j >= square->y && j < square->y + square->size)
				ft_putchar(info->ch[2]);
			else
				ft_putchar(info->ch[0]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
