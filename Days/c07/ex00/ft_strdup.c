/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:25:45 by jewancti          #+#    #+#             */
/*   Updated: 2022/08/28 22:52:20 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(char *str)
{
	char	*start;

	start = str;
	while (*str)
		str++;
	return (str - start);
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
	unsigned int	length;
	char			*s;

	length = ft_strlen(src);
	s = malloc(length + 1);
	if (!s)
		return ((char *)0);
	s[length] = 0;
	return (ft_strcpy(s, src));
}
