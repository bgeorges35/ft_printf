/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:20:21 by bgeorges          #+#    #+#             */
/*   Updated: 2017/12/03 17:29:10 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*sptr;
	unsigned char	*sptr1;

	i = 0;
	sptr = (unsigned char*)s1;
	sptr1 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (i < n - 1 && sptr[i] == sptr1[i])
		i++;
	return (sptr[i] - sptr1[i]);
}
