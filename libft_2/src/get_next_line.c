/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <ghusk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 14:58:27 by ghusk             #+#    #+#             */
/*   Updated: 2020/02/15 13:41:17 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "list_str_nbr.h"

static int				get_line(char *s, t_list_str_nbr **l, char **line)
{
	char		*result;

	if (!(result = (char *)malloc(s - ((*l)->string) + 1)))
		return (-1);
	ft_strncpy(result, ((*l)->string), s - ((*l)->string));
	result[s - ((*l)->string)] = '\0';
	if (!(s = ft_strdup(s + 1)))
	{
		free(result);
		return (-1);
	}
	free(((*l)->string));
	((*l)->string) = s;
	*line = result;
	return (1);
}

static int				get_end(char **line, t_list_str_nbr **head,
		t_list_str_nbr **l, ssize_t ret)
{
	t_list_str_nbr	*list;

	list = *head;
	if (ret == 0 && *(((*l)->string)) != '\0')
	{
		ret = 1;
		*line = ((*l)->string);
	}
	else if (ret == -1 && *(((*l)->string)) != '\0')
		return (ret);
	if (ret < 1)
		free(((*l)->string));
	if (*head == *l)
		*head = (*l)->next;
	else
	{
		while (list->next != *l)
			list = list->next;
		list->next = (*l)->next;
	}
	free(*l);
	return (ret);
}

static int				get_next_line2(const int fd, char **line,
		t_list_str_nbr **head, t_list_str_nbr **l)
{
	char	str[BUFF_SIZE + 1];
	char	*s;
	ssize_t	ret;

	if ((s = ft_strstr(((*l)->string), "\n")))
		return (get_line(s, l, line));
	while ((ret = read(fd, str, BUFF_SIZE)) > 0)
	{
		str[ret] = '\0';
		s = ft_strjoin(((*l)->string), str);
		free(((*l)->string));
		((*l)->string) = s;
		if ((s = ft_strstr(((*l)->string), "\n")))
			return (get_line(s, l, line));
	}
	return (get_end(line, head, l, ret));
}

int						get_next_line(const int fd, char **line)
{
	static t_list_str_nbr	*head;
	t_list_str_nbr			*l;

	if (fd < 0 || line == NULL || (read(fd, NULL, 0) < 0))
		return (-1);
	if (!(head))
	{
		if (!(head = ft_create_list_str_nbr(fd)))
			return (-1);
		l = head;
	}
	else
	{
		l = head;
		while (l && l->number != fd)
			l = l->next;
		if (!(l))
		{
			if (!(l = ft_create_list_str_nbr(fd)))
				return (-1);
			l->next = head;
			head = l;
		}
	}
	return (get_next_line2(fd, line, &head, &l));
}
