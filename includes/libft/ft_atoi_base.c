/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 16:17:10 by bgeorges          #+#    #+#             */
/*   Updated: 2018/03/19 15:52:28 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_check_base(char c, int base)
{
	int				j;
	static char		tab[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
	'9', 'A', 'B', 'C', 'D', 'E', 'F'};

	j = -1;
	if (c >= 'a' && c <= 'f')
		c -= 32;
	while (++j <= base && c != tab[j])
		;
	if (c == tab[j])
		return (j);
	return (-1);
}

static int			ft_atoi_loop(const char *str, int base)
{
	int		result;
	int		base_val;
	int		i;

	result = 0;
	i = 0;
	while (ft_isdigit(str[i]) || (str[i] >= 'A' && str[i] <= 'F') ||
			(str[i] >= 'a' && str[i] <= 'f'))
	{
		base_val = ft_check_base(str[i], base);
		if (base_val == -1)
			return (result);
		result *= base;
		result += base_val;
		i++;
	}
	return (result);
}

unsigned int		ft_atoi_base(const char *str, int base)
{
	int		i;
	int		n;

	i = 0;
	n = 1;
	if (base > 16)
		return (0);
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\t' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		n = -1;
		i++;
	}
	return (n == -1 ? -ft_atoi_loop(&str[i], base) :
	ft_atoi_loop(&str[i], base));
}
