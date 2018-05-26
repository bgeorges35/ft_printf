/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:46:38 by bgeorges          #+#    #+#             */
/*   Updated: 2018/03/29 20:03:50 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_specifier_x(va_list ap, t_all_flags *all_flags)
{
	char		*str;
	int			i;
	long long	tmp;

	i = 0;
	if (all_flags->length.h)
		str = ft_ustoa_base(((unsigned short)va_arg(ap, unsigned int)), 16);
	else if (all_flags->length.hh)
		str = ft_uitoa_base(((unsigned char)va_arg(ap,
												unsigned long long)), 16);
	else if (all_flags->length.l)
		str = ft_ultoa_base((va_arg(ap, unsigned long int)), 16);
	else if (all_flags->length.ll)
		str = ft_ulltoa_base((va_arg(ap, unsigned long long)), 16);
	else if (all_flags->length.j)
		str = ft_uimtoa_base((va_arg(ap, uintmax_t)), 16);
	else if (all_flags->length.z)
		str = ft_ulltoa_base((ssize_t)(va_arg(ap, ssize_t)), 16);
	else
		str = ft_ulltoa_base(((unsigned int)va_arg(ap, int)), 16);
	tmp = ft_atoi_base(str, 16);
	if (tmp == 0 && all_flags->width.point)
		str = ft_strnew(0);
	str = ft_get_flags(str, all_flags, i);
	return (str);
}

char		*ft_specifier_bo(va_list ap, t_all_flags *all_flags)
{
	char			*str;
	int				i;
	long long		tmp;

	i = 1;
	str = ft_ulltoa_base(va_arg(ap, unsigned long int), 8);
	tmp = ft_atoll(str);
	if (tmp == 0 && all_flags->width.point && !all_flags->flags.hashtag)
		str = ft_strnew(0);
	str = ft_get_flags(str, all_flags, i);
	return (str);
}

char		*ft_specifier_o(va_list ap, t_all_flags *all_flags)
{
	char			*str;
	int				i;
	long long		tmp;

	i = 2;
	if (all_flags->length.h)
		str = ft_ustoa_base((unsigned short)(va_arg(ap, unsigned int)), 8);
	else if (all_flags->length.hh)
		str = ft_ulltoa_base((unsigned char)(va_arg(ap, unsigned int)), 8);
	else if (all_flags->length.l)
		str = ft_ultoa_base((va_arg(ap, unsigned long int)), 8);
	else if (all_flags->length.ll)
		str = ft_ulltoa_base((va_arg(ap, unsigned long long)), 8);
	else if (all_flags->length.j)
		str = ft_uimtoa_base((va_arg(ap, uintmax_t)), 8);
	else if (all_flags->length.z)
		str = ft_ulltoa_base((ssize_t)(va_arg(ap, ssize_t)), 8);
	else
		str = ft_uitoa_base((va_arg(ap, unsigned int)), 8);
	tmp = ft_atoll(str);
	if (tmp == 0 && all_flags->width.point && !all_flags->flags.hashtag)
		str = ft_strnew(0);
	str = ft_get_flags(str, all_flags, i);
	return (str);
}

char		*ft_specifier_p(va_list ap, t_all_flags *all_flags)
{
	char	*str;
	int		i;

	i = 3;
	str = ft_ultoa_base_lower(va_arg(ap, unsigned long int), 16);
	if (all_flags->width.point && !ft_strcmp(str, "0"))
		str = ft_strdup("0x");
	else
		str = ft_strjoin_free_2("0x", str);
	str = ft_get_flags(str, all_flags, i);
	return (str);
}
