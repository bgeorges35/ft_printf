/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatcher_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:05:08 by bgeorges          #+#    #+#             */
/*   Updated: 2018/03/29 16:12:28 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_flags(char *str, t_all_flags *all_flags, int i)
{
	if (all_flags->width.point && !all_flags->width.nb)
		all_flags->width.point = -1;
	if (((!ft_strcmp(str, "0") && all_flags->flags.neg) || (!ft_strcmp(str, "")
			&& !all_flags->flags.neg)) && all_flags->flags.sp && i != 8)
		all_flags->width.prec--;
	if ((!all_flags->flags.pos && !all_flags->flags.zero)
		&& all_flags->negative && !all_flags->width.nb)
	{
		all_flags->negative = 0;
		str = ft_strjoin_free_2("-", str);
	}
	str = ft_get_dispatcher_flags(str, all_flags, i);
	ft_change_width_nb(&str, all_flags, i);
	ft_change_width_prec(&str, all_flags);
	if ((!all_flags->flags.pos && !all_flags->flags.zero)
		&& all_flags->negative)
		str = ft_strjoin_free_2("-", str);
	return (str);
}

char	*ft_get_dispatcher_flags(char *str, t_all_flags *all_flags, int i)
{
	if (all_flags->flags.neg)
		str = ft_change_neg(str, all_flags, i);
	if (all_flags->flags.hashtag)
		str = ft_change_hashtag(str, all_flags, i);
	if (all_flags->flags.zero)
		str = ft_change_zero(str, all_flags, i);
	if (all_flags->flags.pos)
		str = ft_change_pos(str, all_flags, i);
	if (all_flags->flags.sp && !all_flags->flags.pos)
		str = ft_change_sp(str, all_flags, i);
	return (str);
}
