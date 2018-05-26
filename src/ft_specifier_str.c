/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:08:24 by bgeorges          #+#    #+#             */
/*   Updated: 2018/03/29 17:34:44 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_specifier_s(va_list ap, t_all_flags *all_flags)
{
	char	*str;
	int		i;

	i = 9;
	str = va_arg(ap, char*);
	if (str == NULL || str == 0)
	{
		str = ft_strdup("(null)");
		str = ft_get_flags(str, all_flags, i);
		return (str);
	}
	str = ft_strdup(str);
	str = ft_get_flags(str, all_flags, i);
	return (str);
}

char			*ft_specifier_c(va_list ap, t_all_flags *all_flags)
{
	int		i;
	char	*str;
	char	c;

	i = 10;
	c = va_arg(ap, int);
	str = ft_strnew(1);
	if (c == 0)
	{
		if (all_flags->width.prec > 0)
			all_flags->width.prec--;
		all_flags->c = 2;
	}
	else
		all_flags->c = 1;
	*str = c;
	str = ft_get_flags(str, all_flags, i);
	return (str);
}

char			*ft_specifier_bs(va_list ap, t_all_flags *all_flags)
{
	char	*str;
	int		i;
	wchar_t	*tmp;

	i = 11;
	tmp = va_arg(ap, wchar_t*);
	str = ft_transform_wchar_in_char(tmp);
	if (str == NULL || str == 0)
	{
		str = ft_strdup("(null)");
		i = 9;
		str = ft_get_flags(str, all_flags, i);
		return (str);
	}
	while (*tmp)
	{
		if ((ft_wcharlen(*tmp) + all_flags->unicode_len) <= all_flags->width.nb)
			all_flags->unicode_len += ft_wcharlen(*tmp);
		else
			break ;
		tmp++;
	}
	str = ft_get_flags(str, all_flags, i);
	return (str);
}

char			*ft_specifier_bc(va_list ap, t_all_flags *all_flags)
{
	char	*str;
	int		i;
	wchar_t	tmp;

	i = 9;
	tmp = va_arg(ap, wchar_t);
	if (tmp == 0)
	{
		if (all_flags->width.prec > 0)
			all_flags->width.prec--;
		all_flags->c = 2;
		str = ft_strnew(1);
	}
	else
		str = ft_transform_wchar_in_charc(tmp);
	str = ft_get_flags(str, all_flags, i);
	return (str);
}
