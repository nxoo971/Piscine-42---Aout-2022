/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_info.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 00:13:19 by lkrief            #+#    #+#             */
/*   Updated: 2022/08/31 21:17:45 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../includes/map2.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ui_putnbr(int n)
{
	if (n < 10)
		ft_putchar('0' + n);
	else
	{
		ui_putnbr(n / 10);
		ft_putchar('0' + n % 10);
	}
}
