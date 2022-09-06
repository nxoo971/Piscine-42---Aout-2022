/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:13:52 by jewancti          #+#    #+#             */
/*   Updated: 2022/09/01 00:01:53 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	int		length;
	char	*s;

	length = ft_strlen(src);
	s = malloc(length + 1);
	if (!s)
		return ((char *)0);
	s[length] = 0;
	return (ft_strcpy(s, src));
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*tab;

	tab = malloc((ac + 1) * sizeof(t_stock_str));
	if (!tab)
		return (NULL);
	tab[ac].str = 0;
	while (--ac >= 0)
	{
		tab[ac].size = ft_strlen(av[ac]);
		tab[ac].str = av[ac];
		tab[ac].copy = ft_strdup(av[ac]);
	}
	return (tab);
}
