/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 15:53:28 by bgeorges          #+#    #+#             */
/*   Updated: 2018/03/13 15:23:31 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(const char *str)
{
	int			i;
	int			negative;
	long long	res;

	i = 0;
	res = 0;
	negative = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] == '\f' || str[i] == '\t' ||
				str[i] == '\v' || str[i] == '\n' || str[i] == '\r')
			i++;
		if (str[i] == '-')
			negative = 1;
		if (str[i] == '-' || str[i] == '+')
			i++;
		while (str[i] <= '9' && str[i] >= '0')
		{
			res *= 10;
			res += str[i] - '0';
			i++;
		}
		return (negative == 1 ? -res : res);
	}
	return (0);
}
