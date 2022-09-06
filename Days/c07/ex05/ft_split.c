/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:24:34 by jewancti          #+#    #+#             */
/*   Updated: 2022/08/25 19:59:51 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char const *charset, char const c)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && is_charset(charset, str[i]))
			i++;
		if (str[i] == '\0')
			break ;
		count++;
		while (str[i] != '\0' && !is_charset(charset, str[i]))
			i++;
		i++;
	}
	return (count);
}

char	*ft_strsub(char *str, int start, int end)
{
	char		*res;
	int			i;

	res = malloc((end - start) + 1);
	if (!res)
		return (NULL);
	res[end - start] = 0;
	i = 0;
	while (str[start] != '\0' && start < end)
		res[i++] = str[start++];
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	char		**res;
	int			size;
	int			start;
	int			index;
	int			i;

	size = count_word(str, charset);
	res = malloc((size + 1) * sizeof(char **));
	res[size] = NULL;
	if (!res)
		return (NULL);
	i = 0;
	index = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && is_charset(charset, str[i]))
			i++;
		if (str[i] == '\0')
			break ;
		start = i;
		while (str[i] != '\0' && !is_charset(charset, str[i]))
			i++;
		res[index++] = ft_strsub(str, start, i++);
	}
	return (res);
}
