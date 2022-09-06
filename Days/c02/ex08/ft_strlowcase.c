/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 01:27:01 by jewancti          #+#    #+#             */
/*   Updated: 2022/08/12 01:30:14 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	char	*save;

	save = str;
	while (*save)
	{
		if (*save >= 'A' && *save <= 'Z')
			*save += 32;
		save++;
	}
	return (str);
}
