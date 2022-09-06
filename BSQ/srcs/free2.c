/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:48:06 by jewancti          #+#    #+#             */
/*   Updated: 2022/08/31 22:07:36 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../includes/map2.h"

int	free_tab_buf_int(int **tab, char *buf, int n)
{
	if (buf)
		free(buf);
	if (tab)
	{
		while (n-- > 0)
			free(tab[n]);
		free(tab);
	}
	return (0);
}

int	free_data(void *data)
{
	if (data)
		free(data);
	return (0);
}
