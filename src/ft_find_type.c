/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 14:56:00 by bgeorges          #+#    #+#             */
/*   Updated: 2018/03/29 17:30:13 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_char(char *str, t_all_flags *all_flags, int len)
{
	int lenc;
	int j;

	lenc = ft_strlen(str);
	j = 0;
	if (all_flags->c == 2)
	{
		if (all_flags->flags.neg && lenc != 0)
		{
			ft_putchar(0);
			j++;
			len += 1;
		}
		ft_putchar(*str);
		str++;
		len += 1;
	}
	while (j < lenc)
	{
		ft_putchar(*str);
		j++;
		str++;
		len += 1;
	}
	return (len);
}

int			ft_find_type(char *format, int *i, va_list ap)
{
	int			len;
	char		*str;
	t_all_flags	*all_flags;

	len = 0;
	if (!format[*i + 1])
		return (len);
	(*i)++;
	if (!(all_flags = ft_check_all_flags(format, i)))
		return (-1);
	str = ft_check_specifiers(format, i, ap, all_flags);
	if (all_flags->c)
		len = ft_print_char(str, all_flags, len);
	else
	{
		ft_putstr(str);
		len += ft_strlen(str);
	}
	ft_strdel(&str);
	free(all_flags);
	return (len);
}
