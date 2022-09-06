/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:37:53 by lkrief            #+#    #+#             */
/*   Updated: 2022/08/31 21:16:41 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../includes/map2.h"

//Cette fonction prend une chaine qui commence par un chiffre en entree et
//converti les chiffres en unsigned int.
int	ui_atoi(char *s, int n)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (s[i] >= '0' && s[i] <= '9' && i < n)
	{
		res = 10 * res + s[i] - '0';
		i++;
	}
	return (res);
}

int	ft_newline(char *str)
{
	int	n;

	n = 0;
	while (str[n] && str[n] != '\n')
		n++;
	if (str[n] == '\0')
		return (0);
	return (n);
}

//On initialise info en checkant la 1ere ligne du fichier et en returnant NULL 
//+ free si erreur
t_info	*check_first_line(char *file)
{
	int		fd;
	char	line[16];
	t_info	*info;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	info = malloc (sizeof(*info));
	if (!info)
		return (NULL);
	line[15] = '\0';
	if (read(fd, line, 14) && ft_newline(line) >= 4)
		info = check_consign(line, info, ft_newline(line) - 1);
	if (info && !close(fd))
	{
		if ((info->ch[0] != info->ch[1]) && (info->ch[1] != info->ch[2])
			&& (info->ch[1] != info->ch[2]))
			return (info);
	}
	free_info(info);
	return (NULL);
}

//Initialisation de info + check de end
t_info	*check_consign(const char *s, t_info *info, int end)
{
	int	i;
	int	res;

	if (s[end] >= 32 && s[end] <= 126 && s[end - 1] >= 32 && s[end - 1] <= 126
		&& s[end - 2] >= 32 && s[end - 2] <= 126)
	{
		info->ch[2] = s[end--];
		info->ch[1] = s[end--];
		info->ch[0] = s[end--];
	}
	else
		return (NULL);
	i = 0;
	res = 0;
	while (s[i] && s[i] >= '0' && s[i] <= '9' && i < end + 1)
		res = res * 10 + s[i++] - '0';
	if (i - 1 == end && res > 0)
	{
		info->nb_lines = res;
		return (info);
	}
	return (NULL);
}

//Renvoie la longueur de la 1ere ligne composee de chars (2e ligne de la map)
//et la stock dans info
int	len_line(char *file, t_info *info)
{
	int		fd;
	int		l;
	char	buf[2];
	int		r;

	l = 0;
	buf[1] = '\0';
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	r = read(fd, buf, 1);
	while (r && buf[0] != '\n')
		r = read(fd, buf, 1);
	r = read(fd, buf, 1);
	while (r && buf[0] != '\n')
	{
		l++;
		r = read(fd, buf, 1);
	}
	if (!close(fd))
	{
		info->nb_cols = l;
		return (l);
	}
	return (0);
}
