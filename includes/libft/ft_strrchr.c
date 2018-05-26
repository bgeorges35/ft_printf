/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 03:58:41 by bgeorges          #+#    #+#             */
/*   Updated: 2017/12/03 17:31:55 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char*)s);
	if (s == NULL)
		return (NULL);
	while (i >= 0)
	{
		if (s[i] == c)
		{
			return ((char*)&s[i]);
		}
		i--;
	}
	return (NULL);
}
