/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:19:39 by bgeorges          #+#    #+#             */
/*   Updated: 2018/03/09 14:41:22 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strleni(unsigned long long n)
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

static char		*ft_print_nbr(int len, char *str, unsigned long long n)
{
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

char			*ft_ulltoa(unsigned long long n)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == ULLONG_MAX)
		return (ft_strdup("18446744073709551615"));
	len = ft_strleni(n);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	str = ft_print_nbr(len, str, n);
	return (str);
}
