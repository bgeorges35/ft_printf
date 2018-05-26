/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:03:22 by bgeorges          #+#    #+#             */
/*   Updated: 2017/12/03 17:32:00 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word_count(char const *str, char c)
{
	int i;
	int count;
	int count_next;

	i = -1;
	count = 0;
	count_next = 1;
	while (str[++i] != '\0')
	{
		if (count_next && str[i] != c)
		{
			count++;
			count_next = 0;
		}
		if (str[i] == c)
			count_next = 1;
	}
	return (count);
}

static int		ft_word_len(char const *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		i++;
	}
	return (i);
}

static char		*ft_strndup(char const *str, int n)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = (char*)malloc(sizeof(cpy) * n + 1);
	if (cpy == NULL)
		return (NULL);
	cpy[n] = '\0';
	while (str[i] != '\0' && i < n)
	{
		cpy[i] = str[i];
		i++;
	}
	return (cpy);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		w_counts;
	int		w_len;
	char	**words;

	if (s == NULL || c == 0)
		return (NULL);
	i = 0;
	w_counts = ft_word_count(s, c);
	words = (char**)malloc(sizeof(*words) * w_counts + 1);
	if (words == NULL)
		return (NULL);
	words[w_counts] = 0;
	while (w_counts--)
	{
		while (s[0] == c)
			s++;
		w_len = ft_word_len(s, c);
		words[i] = ft_strndup(s, w_len);
		s += w_len;
		i++;
	}
	return (words);
}
