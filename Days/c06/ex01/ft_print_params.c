/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:20:17 by jewancti          #+#    #+#             */
/*   Updated: 2022/08/18 16:22:52 by jewancti         ###   ########.fr       */
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
	int	i;

	i = 1;
	while (i < ac)
		ft_putstr_endl(av[i++]);
	return (0);
}
