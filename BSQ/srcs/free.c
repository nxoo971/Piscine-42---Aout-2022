/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 01:11:46 by lkrief            #+#    #+#             */
/*   Updated: 2022/08/31 22:02:26 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../includes/map2.h"

void	free_info(t_info *info)
{
	if (info)
		free(info);
}

void	*free_tab_buf(int **tab, char *buf, int n)
{
	if (buf)
		free(buf);
	if (tab)
	{
		while (n-- > 0)
			free(tab[n]);
		free(tab);
	}
	return (NULL);
}

void	*free_square_point(t_square *square, t_point *point)
{
	if (square)
		free(square);
	if (point)
		free(point);
	return (NULL);
}

void	*free_points(t_point *point1, t_point *point2)
{
	if (point1)
		free(point1);
	if (point2)
		free(point2);
	return (NULL);
}

void	*free_all(t_info *info, t_square *square, int **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (i < info->nb_lines)
			free(tab[i++]);
		free(tab);
	}
	if (square)
		free(square);
	if (info)
		free(info);
	return (NULL);
}
