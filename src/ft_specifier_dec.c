/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_dec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 15:42:02 by bgeorges          #+#    #+#             */
/*   Updated: 2018/03/29 11:07:47 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_check_mark(t_all_flags *all_flags, char **str, int i)
{
	long long	tmp;

	tmp = ft_atoll(*str);
	if (tmp == 0 && (all_flags->width.point || (all_flags->flags.zero &&
		!all_flags->flags.neg)))
	{
		ft_strdel(str);
		*str = ft_strnew(0);
	}
	if (tmp == LLONG_MIN && i == 4)
	{
		ft_strdel(str);
		*str = ft_strdup("9223372036854775808");
		all_flags->negative = 1;
	}
	else if (tmp < 0 && i == 4)
	{
		tmp *= -1;
		all_flags->negative = 1;
		ft_strdel(str);
		*str = ft_lltoa(tmp);
	}
}

char		*ft_specifier_d_i(va_list ap, t_all_flags *all_flags)
{
	char	*str;
	int		i;

	i = 4;
	if (all_flags->length.h)
		str = ft_lltoa((short)va_arg(ap, int));
	else if (all_flags->length.hh)
		str = ft_itoa((char)va_arg(ap, int));
	else if (all_flags->length.l)
		str = ft_ltoa(va_arg(ap, long int));
	else if (all_flags->length.ll)
		str = ft_lltoa(va_arg(ap, long long));
	else if (all_flags->length.j)
		str = ft_lltoa(va_arg(ap, intmax_t));
	else if (all_flags->length.z)
		str = ft_lltoa(va_arg(ap, size_t));
	else
		str = ft_itoa((va_arg(ap, int)));
	ft_check_mark(all_flags, &str, i);
	str = ft_get_flags(str, all_flags, i);
	return (str);
}

char		*ft_specifier_bd(va_list ap, t_all_flags *all_flags)
{
	char	*str;
	int		i;

	i = 4;
	str = ft_ltoa(va_arg(ap, long int));
	ft_check_mark(all_flags, &str, i);
	str = ft_get_flags(str, all_flags, i);
	return (str);
}

char		*ft_specifier_bu(va_list ap, t_all_flags *all_flags)
{
	char	*str;
	int		i;

	i = 6;
	if (all_flags->length.h)
		str = ft_ulltoa(va_arg(ap, unsigned long long));
	else if (all_flags->length.hh)
		str = ft_itoa(va_arg(ap, unsigned int));
	else if (all_flags->length.l)
		str = ft_ulltoa(va_arg(ap, unsigned long int));
	else if (all_flags->length.ll)
		str = ft_ulltoa(va_arg(ap, unsigned long long));
	else if (all_flags->length.j)
		str = ft_ulltoa(va_arg(ap, uintmax_t));
	else if (all_flags->length.z)
		str = ft_itoa(va_arg(ap, ssize_t));
	else
		str = ft_ulltoa((va_arg(ap, unsigned long long)));
	ft_check_mark(all_flags, &str, i);
	str = ft_get_flags(str, all_flags, i);
	return (str);
}

char		*ft_specifier_u(va_list ap, t_all_flags *all_flags)
{
	char	*str;
	int		i;

	i = 7;
	if (all_flags->length.h)
		str = ft_ulltoa((unsigned short)va_arg(ap, unsigned long long));
	else if (all_flags->length.hh)
		str = ft_itoa((unsigned char)va_arg(ap, unsigned int));
	else if (all_flags->length.l)
		str = ft_ulltoa(va_arg(ap, unsigned long int));
	else if (all_flags->length.ll)
		str = ft_ulltoa(va_arg(ap, unsigned long long));
	else if (all_flags->length.j)
		str = ft_ulltoa(va_arg(ap, uintmax_t));
	else if (all_flags->length.z)
		str = ft_ulltoa(va_arg(ap, ssize_t));
	else
		str = ft_uitoa_base_lower(va_arg(ap, unsigned int), 10);
	ft_check_mark(all_flags, &str, i);
	str = ft_get_flags(str, all_flags, i);
	return (str);
}
