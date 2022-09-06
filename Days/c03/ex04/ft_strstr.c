/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 05:42:04 by jewancti          #+#    #+#             */
/*   Updated: 2022/08/17 20:09:22 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	k;

	if (!*to_find)
		return (str);
	i = 0;
	while (str[i])
	{
		k = 0;
		while (to_find[k] && str[i + k] == to_find[k])
			k++;
		if (!to_find[k])
			return (str + i);
		i++;
	}
	return ((char *)0);
}
