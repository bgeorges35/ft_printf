/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:49:26 by bgeorges          #+#    #+#             */
/*   Updated: 2017/12/03 17:31:50 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (str[i] != '\0' && n > i)
	{
		while ((str[i + j] == to_find[j] || to_find[j] == '\0') && i + j <= n)
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
