/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 14:58:27 by ghusk             #+#    #+#             */
/*   Updated: 2019/11/03 19:34:30 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "list_str_nbr.h"
#include "libft.h"

static int	get_line(char *s, char **tmp, char **line)
{
	char		*result;

	if (!(result = (char *)malloc(s - *tmp + 1)))
		return (-1);
	ft_strncpy(result, *tmp, s - *tmp);
	result[s - *tmp] = '\0';
	if (!(s = ft_strdup(s + 1)))
	{
		free(result);
		return (-1);
	}
	free(*tmp);
	*tmp = s;
	*line = result;
	return (1);
}

static int	get_next_line2(ssize_t ret, char **tmp, char **line)
{
	if (*tmp && !(**tmp))
	{
		free(*tmp);
		*tmp = NULL;
		return (ret);
	}
	if (ret == 0)
	{
		*line = *tmp;
		*tmp = NULL;
		return (1);
	}
	return (ret);
}

int			get_next_line1(const int fd, char **line)
{
	char		str[BUFF_SIZE + 1];
	char		*s;
	static char	*sline;
	ssize_t		ret;

	if (fd < 0 || line == NULL || (read(fd, str, 0) < 0))
		return (-1);
	if (sline && (s = ft_strstr(sline, "\n")))
		return (get_line(s, &sline, line));
	if (sline == NULL)
		if (!(sline = ft_memalloc(1)))
			return (-1);
	while ((ret = read(fd, str, BUFF_SIZE)) > 0)
	{
		str[ret] = '\0';
		if (!(s = ft_strjoin(sline, str)))
			return (-1);
		free(sline);
		sline = s;
		if ((s = ft_strstr(sline, "\n")))
			return (get_line(s, &sline, line));
	}
	return (get_next_line2(ret, &sline, line));
}
