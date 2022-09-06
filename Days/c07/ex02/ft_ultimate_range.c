/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:36:01 by jewancti          #+#    #+#             */
/*   Updated: 2022/08/18 21:01:33 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	tab = malloc(sizeof(int) * (max - min));
	if (!tab)
		return (-1);
	i = 0;
	while (min + i < max)
	{
		tab[i] = min + i;
		i++;
	}
	*range = tab;
	return (max - min);
}
