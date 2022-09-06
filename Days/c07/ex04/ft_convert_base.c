/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:19:30 by jewancti          #+#    #+#             */
/*   Updated: 2022/08/28 09:17:29 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str);
int	ft_check_base(char *str);
int	ft_atoi_base(char *str, char *base);

int	ft_nbrlen(unsigned int n, unsigned int base_size)
{
	if (n < base_size)
		return (1);
	return (1 + ft_nbrlen(n / base_size, base_size));
}

unsigned int	ft_check_negative(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_supp_size(int n)
{
	return (n < 0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char			*dest;
	unsigned int	nb;
	int				i;
	int				n;

	if (!(ft_check_base(base_from) && ft_check_base(base_to)))
		return (NULL);
	n = ft_atoi_base(nbr, base_from);
	nb = ft_check_negative(n);
	i = ft_nbrlen(nb, ft_strlen(base_to)) + ft_supp_size(n);
	dest = malloc((i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[i] = '\0';
	while (i--)
	{
		dest[i] = base_to[nb % ft_strlen(base_to)];
		nb /= ft_strlen(base_to);
	}
	if (n < 0)
		dest[0] = '-';
	return (dest);
}
