/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 23:20:43 by jewancti          #+#    #+#             */
/*   Updated: 2022/08/12 01:26:39 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strupcase(char *str)
{
	char	*save;

	save = str;
	while (*save)
	{
		if (*save >= 'a' && *save <= 'z')
			*save -= 32;
		save++;
	}
	return (str);
}
