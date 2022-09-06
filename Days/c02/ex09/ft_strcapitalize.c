/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 04:01:18 by jewancti          #+#    #+#             */
/*   Updated: 2022/08/15 23:51:50 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_char_is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	ft_char_is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isalnum(char c)
{
	return (ft_char_is_alpha(c) || ft_char_is_numeric(c));
}

char	*ft_strcapitalize(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	if (ft_char_is_lower(str[0]))
		str[0] -= 32;
	i = 0;
	while (str[i] != '\0')
	{
		if (i > 0 && ft_char_is_lower(str[i]) && !ft_isalnum(str[i - 1]))
			str[i] -= 32;
		i++;
	}
	return (str);
}
