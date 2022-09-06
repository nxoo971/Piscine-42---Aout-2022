/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:31:42 by jewancti          #+#    #+#             */
/*   Updated: 2022/08/31 21:41:27 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"

int	ft_strlen(char *str)
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

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *s1, char *s2, int size)
{
	unsigned int	length;
	char			*s;

	length = ft_strlen(s1) + size;
	s = malloc(length + 1);
	if (!s)
		return ((char *)0);
	ft_strcpy(s, s1);
	return (ft_strcat(s, s2));
}

char	*ft_strncat(char *dst, char *src, int size)
{
	char	*str;

	if (dst)
	{
		str = ft_strdup(dst, src, size);
		free(dst);
		return (str);
	}
	dst = malloc(size + 1);
	return (ft_strcpy(dst, src));
}
