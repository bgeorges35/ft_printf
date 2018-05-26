/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_lenght.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 18:07:30 by bgeorges          #+#    #+#             */
/*   Updated: 2018/03/22 16:12:11 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_length	*ft_init_length(t_length *length)
{
	length->h = 0;
	length->hh = 0;
	length->l = 0;
	length->ll = 0;
	length->j = 0;
	length->z = 0;
	return (length);
}

t_length	*ft_find_length(t_length *length, char *format, int *len)
{
	length = ft_init_length(length);
	if (format[*len] == 'h' && format[*len + 1] == 'h')
		length->hh = 1;
	if (format[*len] == 'h' && !length->hh)
		length->h = 1;
	if (format[*len] == 'l' && format[*len + 1] == 'l')
		length->ll = 1;
	if (format[*len] == 'l' && !length->ll)
		length->l = 1;
	if (format[*len] == 'j')
		length->j = 1;
	if (format[*len] == 'z')
		length->z = 1;
	if (length->z || length->j || length->l || length->h)
		(*len)++;
	if (length->ll || length->hh)
		(*len) += 2;
	return (length);
}
