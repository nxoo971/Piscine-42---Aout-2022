/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 04:28:24 by jewancti          #+#    #+#             */
/*   Updated: 2022/08/15 05:15:19 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(unsigned char *str, unsigned int start, unsigned int end)
{
	unsigned int	i;

	i = 0;
	while (start + i < end)
	{
		if (!(str[start + i] >= 32 && str[start + i] < 127))
			write(1, ".", 1);
		else
			write(1, &str[start + i], 1);
		i++;
	}
}

void	ft_putaddr(void *addr)
{
	char			*hexa;
	unsigned long	copy;

	hexa = "0123456789abcdef";
	copy = *((unsigned long *)&addr);
	if (copy >= 16)
		ft_putaddr((void *)(copy / 16));
	write(1, &hexa[copy % 16], 1);
}

void	ft_putchar_hexa(unsigned char c)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	write(1, &hexa[c / 16], 1);
	write(1, &hexa[c % 16], 1);
}

void	ft_puthexa(char *str, unsigned int size,
		unsigned int *k, unsigned int *j)
{
	while (*k < 16 && *k < size)
	{
		if (*k != 0 && *j % 2 == 0)
			write(1, " ", 1);
		ft_putchar_hexa((unsigned char)str[*j]);
		(*j)++;
		(*k)++;
	}
	while (*k < 16)
	{
		if (*k != 0 && *k % 2 == 0)
			write(1, " ", 1);
		write(1, "  ", 2);
		(*k)++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	unsigned int	start;
	unsigned char	*address;

	address = (unsigned char *)addr;
	i = 0;
	j = 0;
	start = 0;
	while (i < size)
	{
		write(1, "0000", 4);
		ft_putaddr(&address[i]);
		write(1, ": ", 2);
		k = 0;
		ft_puthexa((char *)address, size - i, &k, &j);
		write(1, " ", 1);
		ft_putstr(address, start, j);
		write(1, "\n", 1);
		start = j;
		i += 16;
	}
	write(1, "\n", 1);
	return (addr);
}
