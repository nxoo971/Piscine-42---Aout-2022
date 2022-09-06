/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:24:40 by jewancti          #+#    #+#             */
/*   Updated: 2022/08/18 16:25:15 by jewancti         ###   ########.fr       */
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

void	ft_putstr_endl(char *s)
{
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	while (ac > 1)
		ft_putstr_endl(av[--ac]);
	return (0);
}
