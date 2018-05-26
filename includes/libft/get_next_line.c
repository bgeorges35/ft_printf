/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:25:05 by bgeorges          #+#    #+#             */
/*   Updated: 2018/02/22 16:44:53 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strjoin_a(const char *s1, const char *s2)
{
	char	*res;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	if (!(res = malloc(sizeof(*res) * i + 1)))
		return (NULL);
	i = 0;
	while (*s1)
		res[i++] = *s1++;
	while (*s2)
		res[i++] = *s2++;
	res[i] = '\0';
	return (res);
}

static int		ft_get_write_file(int i, char ***str, char ***line)
{
	char	*tmp_first_part;
	char	*tmp_sec_part;
	char	*tmp_line;

	if (!(tmp_line = ft_strdup(**line)))
		return (-1);
	ft_strdel(*line);
	if (!(tmp_first_part = ft_strsub(**str, 0, i)))
		return (-1);
	if (!(**line = ft_strjoin_a(tmp_line, tmp_first_part)))
		return (-1);
	ft_strdel(&tmp_line);
	ft_strdel(&tmp_first_part);
	if (!(tmp_sec_part = ft_strsub(**str, i + 1, ft_strlen(**str) - i)))
		return (-1);
	ft_strdel(*str);
	if (!(**str = ft_strdup(tmp_sec_part)))
		return (-1);
	ft_strdel(&tmp_sec_part);
	return (1);
}

static int		ft_end_of_read(char ***str, char ***line)
{
	char	*tmp_line;

	if (!(tmp_line = ft_strdup(**line)))
		return (-1);
	ft_strdel(&(**line));
	if (!(**line = ft_strjoin_a(tmp_line, **str)))
		return (-1);
	ft_strdel(&tmp_line);
	ft_strdel(&(**str));
	if (!(**str = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	return (0);
}

static int		ft_get_read_file(int ret, int fd, char **line, char **str)
{
	int		i;

	i = -1;
	while (ret >= 0)
	{
		if ((*str)[++i] == '\n')
		{
			if ((ret = ft_get_write_file(i, &str, &line)) < 0)
				return (-1);
			return (1);
		}
		if ((*str)[i] == '\0')
		{
			if ((ft_end_of_read(&str, &line)) < 0)
				return (-1);
			if ((ret = read(fd, *str, BUFF_SIZE)) >= 0)
				(*str)[ret] = '\0';
			if (ret == 0 && ft_strlen(*line) > 0)
				return (1);
			if (ret == 0)
				return (0);
			i = -1;
		}
	}
	return (-1);
}

int				get_next_line(const int fd, char **line)
{
	static char		*str = NULL;
	int				ret;

	ret = 0;
	if ((fd == 2 || fd < 0) || BUFF_SIZE <= 0 || line == NULL)
		return (-1);
	if (str == NULL)
	{
		if (!(str = ft_strnew(BUFF_SIZE + 1)))
			return (-1);
		ret = read(fd, str, BUFF_SIZE);
		if (ret < 0)
			return (-1);
		str[ret] = '\0';
	}
	if (!(*line = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	ret = ft_get_read_file(ret, fd, line, &str);
	return (ret);
}
