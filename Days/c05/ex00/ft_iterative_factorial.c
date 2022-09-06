/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:06:00 by jewancti          #+#    #+#             */
/*   Updated: 2022/08/25 02:06:11 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	res;

	res = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	if (nb <= 2)
		return (nb);
	i = 1;
	while (i <= nb)
	{
		res *= i;
		i++;
	}
	return (res);
}
