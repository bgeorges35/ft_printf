/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 21:10:06 by bgeorges          #+#    #+#             */
/*   Updated: 2017/11/27 13:48:21 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_endblank(char const *s)
{
	size_t len;

	len = ft_strlen((char*)s) - 1;
	if (len <= 0)
		return (0);
	while ((s[len] == ' ' || s[len] == '\t' ||
			s[len] == '\n') && s[len] != '\0')
		len--;
	return (len);
}

static size_t	ft_startblank(char const *s)
{
	size_t	start;

	start = 0;
	while ((s[start] == ' ' || s[start] == '\t' ||
			s[start] == '\n') && s[start] != '\0')
		start++;
	return (start);
}

static	char	*ft_allblank(char *s)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char*)malloc(sizeof(char) * ft_strlen((char*)s) + 1);
	if (dest == NULL)
		return (NULL);
	dest[i] = '\0';
	return (dest);
}

char			*ft_strtrim(char const *s)
{
	char	*dest;
	size_t	start;
	size_t	len;
	int		i;
	size_t	new_len;

	if (s == NULL)
		return (NULL);
	i = 0;
	start = ft_startblank(s);
	if (start == ft_strlen((char*)s))
		return (ft_allblank((char*)s));
	len = ft_endblank(s);
	new_len = len - start + 1;
	dest = (char*)malloc(sizeof(char) * new_len + 1);
	if (dest == NULL)
		return (NULL);
	while (new_len--)
	{
		dest[i] = s[start];
		start++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
