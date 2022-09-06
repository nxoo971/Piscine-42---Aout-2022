/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 08:24:28 by jewancti          #+#    #+#             */
/*   Updated: 2022/08/22 22:42:44 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
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
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| !(base[i] >= 32 && base[i] < 127))
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

unsigned int	ft_strlen(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putnbr(int nb, char *base, unsigned int size)
{
	unsigned int	n;

	n = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		n = nb * -1;
	}
	if (n >= size)
		ft_putnbr(n / size, base, size);
	ft_putchar(base[n % size]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (!base_is_valid(base))
		return ;
	ft_putnbr(nbr, base, ft_strlen(base));
}
