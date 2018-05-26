/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_specifiers_flags.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 12:42:43 by bgeorges          #+#    #+#             */
/*   Updated: 2018/03/29 16:12:27 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_all_flags		*ft_check_all_flags(char *format, int *i)
{
	t_all_flags		*all_flags;
	t_flags			flags;
	t_length		length;
	t_width			width;

	if (!(all_flags = (t_all_flags*)malloc(sizeof(*all_flags))))
		return (0);
	flags = *ft_find_flags(&flags, format, i);
	width = *ft_find_width(&width, format, i);
	length = *ft_find_length(&length, format, i);
	all_flags->flags = flags;
	all_flags->length = length;
	all_flags->width = width;
	all_flags->c = 0;
	all_flags->negative = 0;
	all_flags->unicode_len = 0;
	return (all_flags);
}

char			*ft_check_specifiers(char *format, int *i,
								va_list ap, t_all_flags *all_flags)
{
	char	*str;

	str = NULL;
	if (((str = ft_find_specifier_str(format, i, ap, all_flags))) != NULL)
		return (str);
	if (((str = ft_find_specifier_base(format, i, ap, all_flags))) != NULL)
		return (str);
	if (((str = ft_find_specifier_dec(format, i, ap, all_flags))) != NULL)
		return (str);
	str = ft_do_not_found_specifier(all_flags, i, format);
	return (str);
}
