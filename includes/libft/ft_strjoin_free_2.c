/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 15:44:20 by bgeorges          #+#    #+#             */
/*   Updated: 2018/03/27 22:26:32 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free_2(char *tmp, char *buff)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(tmp) + ft_strlen(buff) + 1));
	if (!str)
	{
		ft_strdel(&buff);
		return (NULL);
	}
	while (tmp[i])
	{
		str[i] = tmp[i];
		i++;
	}
	while (buff[j])
	{
		str[i + j] = buff[j];
		j++;
	}
	str[i + j] = 0;
	ft_strdel(&buff);
	return (str);
}
