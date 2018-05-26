/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:19:39 by bgeorges          #+#    #+#             */
/*   Updated: 2018/03/13 12:00:21 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strleni(short n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char		*ft_print_nbr(int len, char *str, short n)
{
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

char			*ft_stoa(short n)
{
	char	*str;
	int		len;
	int		negative;
	int		i;

	i = 0;
	negative = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -32768)
		return (ft_strdup("–32768"));
	if (n < 0)
	{
		negative = 1;
		n = -n;
	}
	len = ft_strleni(n) + negative;
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	str = ft_print_nbr(len, str, n);
	if (negative == 1)
		str[0] = '-';
	return (str);
}
