/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:12:10 by bgeorges          #+#    #+#             */
/*   Updated: 2017/12/03 17:32:05 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (to_find[i] == '\0')
	{
		return ((char*)str);
	}
	while (str[i] != '\0')
	{
		while (str[i + j] == to_find[j] || to_find[j] == '\0')
		{
			if (to_find[j] == '\0')
			{
				return ((char*)str + i);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
