/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:22:26 by jewancti          #+#    #+#             */
/*   Updated: 2022/08/16 19:31:07 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	res;
	int	i;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	i = 1;
	res = 1;
	while (i <= power)
	{
		res *= nb;
		i++;
	}
	return (res);
}
