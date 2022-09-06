/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 05:00:30 by jewancti          #+#    #+#             */
/*   Updated: 2022/08/14 08:04:14 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

void	ft_putchar_to_hexa(unsigned char c)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	ft_putchar('\\');
	ft_putchar(hexa[c / 16]);
	ft_putchar(hexa[c % 16]);
}

unsigned int	ft_char_is_printable(char c)
{
	return (c >= 32 && c < 127);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (!ft_char_is_printable(*str))
			ft_putchar_to_hexa(*str);
		else
			ft_putchar(*str);
		str++;
	}
}
