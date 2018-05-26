/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags_neg_pos_sp.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:17:55 by bgeorges          #+#    #+#             */
/*   Updated: 2018/03/29 11:12:19 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_change_neg(char *str, t_all_flags *all_flags, int i)
{
	int		tmp;

	tmp = ft_atoi(str);
	if (i == 0 && tmp && all_flags->flags.hashtag)
		all_flags->width.prec -= 2;
	if (((i == 2 || i == 1) && tmp && all_flags->flags.hashtag) || (i == 4 &&
	(all_flags->negative || (!all_flags->negative && all_flags->flags.pos))))
		all_flags->width.prec--;
	ft_change_width_nb(&str, all_flags, i);
	ft_change_width_prec_neg(&str, all_flags);
	return (str);
}

char	*ft_change_pos(char *str, t_all_flags *all_flags, int i)
{
	int j;

	j = 0;
	ft_change_width_nb(&str, all_flags, i);
	ft_change_width_prec(&str, all_flags);
	while (str[j] == ' ')
		j++;
	if (i == 4 && !all_flags->negative)
	{
		if (all_flags->flags.zero && str[j] == '0' && j == 0)
			str[j] = '+';
		else if (j != 0)
			str[j - 1] = '+';
		else if (j == 0)
			str = ft_strjoin_free_2("+", str);
	}
	if (all_flags->negative)
	{
		if (j != 0)
			str[j - 1] = '-';
		else if (j == 0)
			str = ft_strjoin_free_2("-", str);
	}
	return (str);
}

char	*ft_change_sp(char *str, t_all_flags *all_flags, int i)
{
	int tmp;

	tmp = ft_atoi(str);
	if (tmp >= 0 && i == 4 && all_flags->width.point <= 0)
	{
		str = ft_strjoin_free_2(" ", str);
	}
	ft_change_width_nb(&str, all_flags, i);
	ft_change_width_prec(&str, all_flags);
	return (str);
}
