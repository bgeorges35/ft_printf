/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 21:57:36 by bgeorges          #+#    #+#             */
/*   Updated: 2018/03/28 15:49:41 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_width		*ft_init_width(t_width *width)
{
	width->point = 0;
	width->nb = 0;
	width->prec = 0;
	return (width);
}

t_width		*ft_find_width(t_width *width, char *format, int *len)
{
	char *tmp;

	width = ft_init_width(width);
	tmp = ft_strsub(format, *len, ft_strlen(format) - *len);
	width->prec = ft_atoi(tmp);
	ft_strdel(&tmp);
	while (format[*len] >= '0' && format[*len] <= '9')
		(*len)++;
	if (format[*len] == '.')
	{
		width->point = 1;
		(*len)++;
		tmp = ft_strsub(format, *len, ft_strlen(format) - *len);
		width->nb = ft_atoi(tmp);
		ft_strdel(&tmp);
	}
	while (format[*len] >= '0' && format[*len] <= '9')
		(*len)++;
	return (width);
}
