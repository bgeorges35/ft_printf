/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags_hash_zero.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:02:08 by bgeorges          #+#    #+#             */
/*   Updated: 2018/03/29 16:04:18 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_change_zero_bis(char *str, t_all_flags *all_flags, int i, int nb)
{
	char	*tmp;
	int		count;

	count = -1;
	if ((all_flags->negative && all_flags->width.prec) ||
	(all_flags->flags.sp && nb > 0 && i == 4
	&& all_flags->width.point <= 0))
		all_flags->width.prec--;
	ft_change_width_nb(&str, all_flags, i);
	ft_change_width_prec(&str, all_flags);
	while (str[++count] == ' ' && (!all_flags->width.point ||
	(i >= 8 && i <= 11)))
		str[count] = '0';
	if (i == 0 && all_flags->flags.hashtag && nb)
	{
		tmp = ft_strsub(str, 0, count);
		str = ft_strsub_free(str, count, ft_strlen(str) - count);
		str = ft_strjoin_free_2(tmp, str);
		str = ft_strjoin_free_2("0X", str);
		ft_strdel(&tmp);
	}
	return (str);
}

char	*ft_change_zero(char *str, t_all_flags *all_flags, int i)
{
	int		count;
	int		nb;

	nb = ft_atoi(str);
	if (i == 0)
		nb = ft_atoi_base(str, 16);
	if (i == 1 || i == 2)
		nb = ft_atoi_base(str, 8);
	count = -1;
	if (!all_flags->flags.neg)
		str = ft_change_zero_bis(str, all_flags, i, nb);
	if (all_flags->negative && !all_flags->flags.pos)
		str = ft_strjoin_free_2("-", str);
	return (str);
}

char	*ft_change_hashtag_x_o(char *str, t_all_flags *all_flags,
								int i, int tmp)
{
	int		j;
	char	*temp;

	j = 0;
	while (str[j] == ' ')
		j++;
	if ((i == 2 || i == 1) && tmp)
	{
		temp = ft_strsub(str, j, ft_strlen(str) - j);
		temp = ft_strjoin_free_2("0", temp);
		str = ft_strsub_free(str, 0, j);
		str = ft_strjoin_free(str, temp);
		ft_strdel(&temp);
	}
	if (i == 0 && tmp && (!all_flags->flags.zero || all_flags->flags.neg ||
		all_flags->width.point))
	{
		temp = ft_strsub(str, j, ft_strlen(str) - j);
		temp = ft_strjoin_free_2("0X", temp);
		str = ft_strsub_free(str, 0, j);
		str = ft_strjoin_free(str, temp);
		ft_strdel(&temp);
	}
	return (str);
}

char	*ft_change_hashtag(char *str, t_all_flags *all_flags, int i)
{
	int		tmp;

	if (i == 0)
		tmp = ft_atoi_base(str, 16);
	if (i == 2 || i == 1)
		tmp = ft_atoi_base(str, 8);
	if (i == 0 && tmp)
		all_flags->width.prec -= 2;
	if ((i == 2 || i == 1) && tmp)
		all_flags->width.prec--;
	if (!all_flags->flags.neg)
	{
		if (i == 0)
			ft_change_width_nb(&str, all_flags, i);
		ft_change_width_prec(&str, all_flags);
	}
	str = ft_change_hashtag_x_o(str, all_flags, i, tmp);
	if (!all_flags->flags.neg)
		ft_change_width_prec(&str, all_flags);
	return (str);
}
