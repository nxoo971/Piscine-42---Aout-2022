/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 00:09:33 by lkrief            #+#    #+#             */
/*   Updated: 2022/08/31 23:32:46 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#define SIZE		1024
#define MAP_NAME	"map.tmp"

void	print_tab(int **tab, t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->nb_lines)
	{
		j = 0;
		while (j < info->nb_cols)
			ft_putchar('0' + tab[i][j++]);
		ft_putchar('\n');
		i++;
	}
}

int	write_map_in_file(const char *filename, char **map)
{
	int	fd;

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
		return (free_data(*map));
	write(fd, *map, ft_strlen(*map));
	if (close(fd) == -1)
		return (free_data(*map));
	return (1);
}

int	split_func_args(void)
{
	int		ret;
	char	buff[SIZE + 1];
	char	*map;

	ret = 1;
	map = NULL;
	while (ret > 0)
	{
		ret = read(0, buff, SIZE);
		if (ret < 0)
			return (free_data(map));
		if (ret == 0)
			break ;
		buff[ret] = 0;
		if (*buff == '\n' && *(buff + 1) == '\0')
			break ;
		map = ft_strncat(map, buff, ret);
		if (!map)
			return (free_data(map));
	}
	if (write_map_in_file(MAP_NAME, &map) == 0)
		return (free_data(map));
	bsq(MAP_NAME);
	return (free_data(map));
}

int	main(int argc, char **argv)
{
	int		i;

	if (argc == 1)
		return (split_func_args());
	if (argc >= 2)
	{
		i = 1;
		while (i < argc)
		{
			if (!bsq(argv[i++]))
				return (0);
		}
	}
	return (0);
}
