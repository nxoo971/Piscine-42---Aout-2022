/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 08:58:12 by jewancti          #+#    #+#             */
/*   Updated: 2022/08/22 01:34:05 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\v'
		|| c == '\n' || c == '\r' || c == '\f');
}

int	base_is_valid(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!base || !*base || !base[1])
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-'
			|| base[i] <= 32)
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	get_pos(char *base, char c)
{
	unsigned int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi(char *str, char *base, unsigned int size)
{
	int		neg;
	int		res;
	int		pos;

	res = 0;
	neg = 1;
	while (ft_isspace(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (*str)
	{
		pos = get_pos(base, *str);
		if (pos == -1)
			break ;
		res = res * size + pos;
		str++;
	}
	return (res * neg);
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	i;

	if (!base_is_valid(base))
		return (0);
	i = 0;
	while (base[i] != '\0')
		i++;
	return (ft_atoi(str, base, i));
}
