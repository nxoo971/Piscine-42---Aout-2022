/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:06:52 by lkrief            #+#    #+#             */
/*   Updated: 2022/08/31 21:21:16 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP2_H
# define MAP2_H

# include "map.h"

//point_square.c
t_square	*i_s(t_square *square, int a, int b, int c);

//algo.c
t_square	*big_square(int **tab, t_info *info);
t_square	*calc(int **tab, t_point *point, t_info *info, t_square *square);

#endif
