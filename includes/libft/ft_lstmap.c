/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:33:10 by bgeorges          #+#    #+#             */
/*   Updated: 2017/12/03 15:08:00 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newptr;
	t_list *new;
	t_list *tmp;

	if (lst == NULL)
		return (NULL);
	new = NULL;
	while (lst)
	{
		tmp = f(lst);
		if (tmp != NULL && new == NULL)
		{
			new = tmp;
			newptr = new;
		}
		else if (tmp != NULL)
		{
			new->next = tmp;
			new = new->next;
		}
		lst = lst->next;
	}
	return (newptr);
}
