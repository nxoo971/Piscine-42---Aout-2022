/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:37:53 by lkrief            #+#    #+#             */
/*   Updated: 2022/08/31 22:10:01 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../includes/map2.h"

int	belongs(char c, t_info *info)
{
	if (c == info->ch[0] || c == info->ch[1] || c == info->ch[2])
		return (1);
	return (0);
}

//Renvoie un pointeur sur la map de dimension (n, l) si la map est valide
//Si on appelle cette fonction, on aura deja check que la premiere ligne soit OK
//et que la 1ere ligne fasse au moins 1 de long, t_info est completement init
//param i = 0 !! juste la pour gagner 2 lignes
int	**init_map(char *file, t_info *info, int i)
{
	char		*buf;
	int			**tab;

	buf = malloc(sizeof(*buf) * (info->nb_cols + 2));
	tab = malloc(sizeof(*tab) * info->nb_lines);
	if (!tab || !buf)
		return (free_tab_buf(tab, buf, 0));
	while (i < info->nb_lines)
	{
		tab[i] = malloc(sizeof(**tab) * info->nb_cols);
		if (!(tab[i]))
			return (free_tab_buf(tab, buf, i));
		i++;
	}
	return (check_map(file, info, tab, buf));
}

int	split_func(int fd, t_info *info, int ***tab, char **buf)
{
	int	ret;
	int	i;
	int	j;
	int	total;

	ret = 1;
	i = -1;
	while (ret > 0 && ++i < info->nb_lines)
	{
		ret = read(fd, *buf, info->nb_cols + 1);
		if (ret == 0 && total != info->nb_lines)
			return (free_tab_buf_int(*tab, *buf, info->nb_lines));
		total += ret;
		j = 0;
		while ((*buf)[j] && j < info->nb_cols)
		{
			if (!belongs((*buf)[j], info))
				return (free_tab_buf_int(*tab, *buf, info->nb_lines));
			(*tab)[i][j] = 0 + ((*buf)[j] == info->ch[1]);
			j++;
		}
		if ((*buf)[j] != '\n')
			return (free_tab_buf_int(*tab, *buf, info->nb_lines));
	}
	return (1);
}

int	**check_map(char *file, t_info *info, int **tab, char *buf)
{
	int	fd;
	int	ret;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (free_tab_buf(tab, buf, info->nb_lines));
	while (read(fd, buf, 1) && buf[0] != '\n')
		;
	ret = split_func(fd, info, &tab, &buf);
	if (!ret)
		return (NULL);
	if (read(fd, buf, 1))
		return (free_tab_buf(tab, buf, info->nb_lines));
	free(buf);
	if (!close(fd))
		return (tab);
	return (free_tab_buf(tab, buf, info->nb_lines));
}
