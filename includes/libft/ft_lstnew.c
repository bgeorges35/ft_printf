/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:30:36 by bgeorges          #+#    #+#             */
/*   Updated: 2017/11/29 05:43:14 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_list;

	new_list = (t_list*)malloc(sizeof(*new_list));
	if (new_list != NULL)
	{
		if (content == NULL)
		{
			new_list->content_size = 0;
			new_list->content = NULL;
		}
		else
		{
			new_list->content = (void*)malloc(sizeof(content_size));
			if (new_list->content == NULL)
				return (NULL);
			ft_memcpy(new_list->content, content, content_size);
			new_list->content_size = content_size;
		}
		new_list->next = NULL;
		return (new_list);
	}
	else
		return (NULL);
}
