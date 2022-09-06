/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 01:54:02 by jewancti          #+#    #+#             */
/*   Updated: 2022/08/23 03:02:08 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ftt_sqrt(int nb, int value)
{
	if (value > 46340)
		return (0);
	if (value * value == nb)
		return (value);
	return (ftt_sqrt(nb, value + 1));
}

int	ft_sqrt(int nb)
{
	if (nb <= 0 || nb > 2147395600)
		return (0);
	return (ftt_sqrt(nb, 1));
}
