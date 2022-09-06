/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 07:16:14 by jewancti          #+#    #+#             */
/*   Updated: 2022/08/18 20:12:23 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\v'
		|| c == '\n' || c == '\r' || c == '\f');
}

int	ft_atoi(char *str)
{
	int		neg;
	int		res;

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
	while (*str && *str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * neg);
}
