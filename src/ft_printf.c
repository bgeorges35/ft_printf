/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 11:16:47 by bgeorges          #+#    #+#             */
/*   Updated: 2018/03/29 16:29:22 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			j;
	int			len;

	va_start(ap, format);
	len = 0;
	i = -1;
	j = 0;
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			if ((j = ft_find_type((char*)format, &i, ap)) == -1)
				return (-1);
			len += j;
		}
		else
		{
			ft_putchar(format[i]);
			len += 1;
		}
	}
	va_end(ap);
	return (len);
}
