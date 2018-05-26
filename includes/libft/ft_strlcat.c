/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 22:38:35 by bgeorges          #+#    #+#             */
/*   Updated: 2017/11/26 06:31:03 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	int		i;
	size_t	dest_size;
	size_t	src_size;
	int		len;

	i = 0;
	dest_size = ft_strlen(dest);
	src_size = ft_strlen((char*)src);
	len = n - dest_size;
	while (len > 1 && src[i] != '\0' && len--)
	{
		dest[dest_size + i] = ((char*)src)[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	if (len > 0)
	{
		return (dest_size + src_size);
	}
	return (n + src_size);
}
