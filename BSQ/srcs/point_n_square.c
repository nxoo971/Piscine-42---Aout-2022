/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_n_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 02:48:00 by lkrief            #+#    #+#             */
/*   Updated: 2022/08/31 21:17:28 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../includes/map2.h"

t_point	*init_point(t_point *point, int i, int j)
{
	point->i = i;
	point->j = j;
	return (point);
}

t_square	*i_s(t_square *square, int a, int b, int c)
{
	square->size = a;
	square->x = b;
	square->y = c;
	return (square);
}
