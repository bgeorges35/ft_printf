/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_wchar_in_char.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 16:41:14 by bgeorges          #+#    #+#             */
/*   Updated: 2018/03/29 17:34:52 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_transform_wchar_in_char(wchar_t *ws)
{
	char	*str;
	int		i;
	int		k;
	int		len;

	if (!ws)
		return (0);
	i = 0;
	k = 0;
	len = ft_wbytelen(ws);
	if (!(str = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	str[len] = '\0';
	while (ws[k])
	{
		i = ft_wchar_to_char(ws[k], str, i);
		k++;
	}
	return (str);
}

char		*ft_transform_wchar_in_charc(wchar_t ws)
{
	char	*str;
	int		i;
	int		len;

	if (!ws)
		return (0);
	i = 0;
	len = ft_wcharlen(ws);
	if (!(str = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	str[len] = '\0';
	i = ft_wchar_to_char(ws, str, i);
	return (str);
}
