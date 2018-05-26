/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:09:13 by bgeorges          #+#    #+#             */
/*   Updated: 2017/12/03 17:29:03 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int i;

	i = 0;
	if (n <= 0)
		return (NULL);
	while (n > i)
	{
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		if ((((unsigned char*)src)[i]) == ((unsigned char)c))
		{
			i++;
			return ((unsigned char*)&dest[i]);
		}
		i++;
	}
	return (NULL);
}
