/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_specifiers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 17:57:02 by bgeorges          #+#    #+#             */
/*   Updated: 2018/03/29 17:37:54 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_do_not_found_specifier(t_all_flags *all_flags, int *i,
										char *format)
{
	char		*str;
	int			j;

	j = 8;
	str = ft_strnew(2);
	*str = format[*i];
	if (all_flags->width.nb || all_flags->width.prec)
		str = ft_get_flags(str, all_flags, j);
	return (str);
}

char		*ft_find_specifier_base(char *format, int *i, va_list ap,
										t_all_flags *all_flags)
{
	if (format[*i] == 'x' || format[*i] == 'X')
	{
		if (format[*i] == 'x')
			return (ft_str_tolower(ft_specifier_x(ap, all_flags)));
		return (ft_specifier_x(ap, all_flags));
	}
	if (format[*i] == 'o')
		return ((ft_specifier_o(ap, all_flags)));
	if (format[*i] == 'O')
		return ((ft_specifier_bo(ap, all_flags)));
	if (format[*i] == 'p')
		return ((ft_specifier_p(ap, all_flags)));
	return (NULL);
}

char		*ft_find_specifier_str(char *format, int *i, va_list ap,
										t_all_flags *all_flags)
{
	if (format[*i] == 's' && !all_flags->length.l)
		return ((ft_specifier_s(ap, all_flags)));
	if (format[*i] == 'c' && !all_flags->length.l)
		return ((ft_specifier_c(ap, all_flags)));
	if (format[*i] == 'S' || (format[*i] == 's' && all_flags->length.l))
		return ((ft_specifier_bs(ap, all_flags)));
	if (format[*i] == 'C' || (format[*i] == 'c' && all_flags->length.l))
		return ((ft_specifier_bc(ap, all_flags)));
	return (NULL);
}

char		*ft_find_specifier_dec(char *format, int *i, va_list ap,
										t_all_flags *all_flags)
{
	if (format[*i] == 'd' || format[*i] == 'i')
		return ((ft_specifier_d_i(ap, all_flags)));
	if (format[*i] == 'D')
		return ((ft_specifier_bd(ap, all_flags)));
	if (format[*i] == 'u')
		return ((ft_specifier_u(ap, all_flags)));
	if (format[*i] == 'U')
		return ((ft_specifier_bu(ap, all_flags)));
	return (NULL);
}
