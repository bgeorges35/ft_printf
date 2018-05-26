/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:25:03 by bgeorges          #+#    #+#             */
/*   Updated: 2018/03/29 19:50:42 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_str(t_all_flags *all_flags, char **str)
{
	*str = ft_strsub_free(*str, 0, all_flags->width.nb);
	all_flags->width.nb = 0;
	all_flags->width.point = 0;
}

void	ft_change_width_prec(char **str, t_all_flags *all_flags)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen(*str);
	while (len != all_flags->width.prec && all_flags->width.prec != 0)
	{
		if (len < all_flags->width.prec)
		{
			*str = ft_strjoin_free_2(" ", *str);
			all_flags->width.prec--;
		}
		if (len > all_flags->width.prec)
			all_flags->width.prec++;
	}
	while ((*str)[i] == ' ' && (*str)[i + 1] == ' ')
		i++;
	if ((!all_flags->flags.pos && !all_flags->flags.zero)
		&& all_flags->negative && i)
	{
		(*str)[i] = '-';
		all_flags->negative = 0;
	}
	all_flags->width.prec = 0;
}

void	ft_change_width_nb(char **str, t_all_flags *all_flags, int i)
{
	int len;

	len = ft_strlen(*str);
	if (all_flags->c)
		len = 0;
	if (all_flags->width.point == -1 && len > all_flags->width.nb && i >= 9)
		ft_width_str(all_flags, str);
	while (len != all_flags->width.nb && all_flags->width.nb != 0)
	{
		if (len < all_flags->width.nb)
		{
			if (i < 8)
				*str = ft_strjoin_free_2("0", *str);
			all_flags->width.nb--;
		}
		if (len > all_flags->width.nb)
		{
			if (i == 11)
				*str = ft_strsub_free(*str, 0, all_flags->unicode_len);
			else if (i >= 8)
				*str = ft_strsub_free(*str, 0, all_flags->width.nb);
			break ;
		}
	}
	all_flags->width.nb = 0;
}

void	ft_change_width_prec_neg(char **str, t_all_flags *all_flags)
{
	int	len;

	len = ft_strlen(*str);
	while (len != all_flags->width.prec && all_flags->width.prec != 0)
	{
		if (len < all_flags->width.prec)
		{
			*str = ft_strjoin_free(*str, " ");
			all_flags->width.prec--;
		}
		if (len > all_flags->width.prec)
			all_flags->width.prec++;
	}
	all_flags->width.prec = 0;
}
