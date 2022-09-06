/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:16:50 by jewancti          #+#    #+#             */
/*   Updated: 2022/08/18 16:19:40 by jewancti         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		write(1, av[0], ft_strlen(av[0]));
		write(1, "\n", 1);
	}
	return (0);
}
