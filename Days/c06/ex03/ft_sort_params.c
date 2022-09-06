/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:26:14 by jewancti          #+#    #+#             */
/*   Updated: 2022/08/18 19:01:51 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlen(char *s)
{
	char	*start;

	start = s;
	while (*s)
		s++;
	return (s - start);
}

void	ft_swap(char **s, char **s2)
{
	char	*tmp;

	tmp = *s;
	*s = *s2;
	*s2 = tmp;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

void	ft_sort(char **tab, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
				ft_swap(&(tab[i]), &(tab[j]));
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	ft_sort(av, ac);
	while (i < ac)
	{
		write(1, av[i], ft_strlen(av[i]));
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
