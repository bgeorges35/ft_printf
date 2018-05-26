/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:14:58 by bgeorges          #+#    #+#             */
/*   Updated: 2017/12/03 17:28:51 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*sptr;

	sptr = (unsigned char*)s;
	i = 0;
	while (n > i)
	{
		if (sptr[i] == (unsigned char)c)
			return (&sptr[i]);
		i++;
	}
	return (NULL);
}
