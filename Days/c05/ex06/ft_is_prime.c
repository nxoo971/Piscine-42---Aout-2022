/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:20:04 by jewancti          #+#    #+#             */
/*   Updated: 2022/08/25 13:52:52 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = nb / 2;
	if (nb <= 1)
		return (0);
	while (i != 1)
	{
		if (nb % i == 0)
			return (0);
		i--;
	}
	return (1);
}