/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 18:15:07 by bgeorges          #+#    #+#             */
/*   Updated: 2018/03/28 16:07:15 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strleni(int n, int base)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

static char		*ft_print_nbr(int len, char *str, int n, int base)
{
	while (len--)
	{
		str[len] = "0123456789ABCDEF"[n % base];
		n = n / base;
	}
	return (str);
}

char			*ft_itoa_base(int n, int base)
{
	char	*str;
	int		len;
	int		negative;
	int		i;

	i = 0;
	negative = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		if (base == 10)
			negative = 1;
		n = -n;
	}
	len = ft_strleni(n, base) + negative;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	str = ft_print_nbr(len, str, n, base);
	if (negative == 1)
		str[0] = '-';
	return (str);
}
