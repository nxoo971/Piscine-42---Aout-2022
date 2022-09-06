/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 03:34:47 by jewancti          #+#    #+#             */
/*   Updated: 2022/08/18 11:21:46 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	char	*start;

	start = str;
	while (*str)
		str++;
	return (str - start);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*start;

	start = dest;
	while (*dest)
		dest++;
	while (*src && nb-- > 0)
		*dest++ = *src++;
	*dest = 0;
	return (start);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_dst;
	unsigned int	len_src;
	unsigned int	n;
	unsigned int	i;

	i = 0;
	n = size;
	len_dst = ft_strlen(dest);
	len_src = ft_strlen(src);
	while (dest[i] && size > 0)
	{
		i++;
		size--;
	}
	if (size == 0)
		return (n + len_src);
	ft_strncat(dest, src, size - 1);
	return (len_src + len_dst);
}
