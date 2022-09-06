/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:02:44 by jewancti          #+#    #+#             */
/*   Updated: 2022/08/18 21:37:52 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	char	*start;

	start = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (start);
}

unsigned int	ft_strlen(char *str)
{
	char	*start;

	start = str;
	while (*str)
		str++;
	return (str - start);
}

int	ft_getlength(int size, char **s, char *sep)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (i < size)
	{
		res += ft_strlen(s[i]);
		if (i + 1 < size)
			res += ft_strlen(sep);
		i++;
	}
	return (res);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;

	str = malloc(ft_getlength(size, strs, sep) + 1);
	if (!str)
		return ((char *)0);
	i = 0;
	*str = 0;
	while (i < size)
	{
		ft_strcat(str, strs[i]);
		if (i + 1 < size)
			ft_strcat(str, sep);
		i++;
	}
	return (str);
}
