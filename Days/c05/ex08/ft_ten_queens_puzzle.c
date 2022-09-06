/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 03:28:48 by jewancti          #+#    #+#             */
/*   Updated: 2022/08/25 01:46:18 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char const c)
{
	write(1, &c, 1);
}

void	print_tab(int const tab[10])
{
	int	x;

	x = 0;
	while (x < 10)
	{
		ft_putchar(tab[x] + '0');
		x++;
	}
	ft_putchar('\n');
}

int	check_pos(int const tab[10], int const n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (tab[i] == tab[n]
			|| tab[i] - tab[n] == n - i || tab[n] - tab[i] == n - i)
			return (0);
		i++;
	}
	return (1);
}

void	place(int tab[10], int pos, int *solution)
{
	int	index;

	index = 0;
	if (pos == 10)
	{
		print_tab(tab);
		*solution += 1;
		return ;
	}
	while (index < 10)
	{
		tab[pos] = index;
		if (check_pos(tab, pos))
			place(tab, pos + 1, solution);
		index++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	tab[10];
	int	solution;

	solution = 0;
	place(tab, 0, &solution);
	return (solution);
}
