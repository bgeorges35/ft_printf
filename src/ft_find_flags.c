/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 12:09:29 by bgeorges          #+#    #+#             */
/*   Updated: 2018/03/29 16:12:29 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		*ft_init_flags(t_flags *flags)
{
	flags->hashtag = 0;
	flags->neg = 0;
	flags->pos = 0;
	flags->zero = 0;
	flags->sp = 0;
	return (flags);
}

t_flags		*ft_find_flags(t_flags *flags, char *format, int *len)
{
	flags = ft_init_flags(flags);
	while (format[*len] == ' ' || format[*len] == '#' || format[*len] == '-'
			|| format[*len] == '+' || format[*len] == '0')
	{
		if (format[*len] == '#')
			flags->hashtag = 1;
		if (format[*len] == '-')
			flags->neg = 1;
		if (format[*len] == '+')
			flags->pos = 1;
		if (format[*len] == '0')
			flags->zero = 1;
		if (format[*len] == ' ')
			flags->sp = 1;
		(*len)++;
	}
	return (flags);
}
