/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 04:59:33 by jewancti          #+#    #+#             */
/*   Updated: 2022/08/11 06:13:55 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	combin(int tableau[], int index, int size, int first)
{
	int	value;
	int	i;

	if (index < size)
	{
		value = first;
		while (value <= 9)
		{
			tableau[index] = value;
			combin(tableau, index + 1, size, value + 1);
			value++;
		}
	}
	else
	{
		i = 0;
		while (i < size)
		{
			ft_putchar(tableau[i] + '0');
			i++;
		}
		if (tableau[0] < 10 - size)
			write(1, ", ", 2);
	}
}

void	ft_print_combn(int n)
{
	int	tab[10];

	combin(tab, 0, n, 0);
}
