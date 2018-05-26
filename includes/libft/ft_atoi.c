/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:58:15 by bgeorges          #+#    #+#             */
/*   Updated: 2017/11/20 14:52:25 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int negative;
	int res;

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
