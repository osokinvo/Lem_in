/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_storage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 06:03:26 by val               #+#    #+#             */
/*   Updated: 2020/07/26 19:04:21 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <unistd.h>

t_storage *ft_create_storage(void)
{
	t_storage *result;

	if (!(result = (t_storage *)malloc(sizeof(t_storage))))
		return (NULL);
	result->head = NULL;
	result->key_end = 0;
	result->key_start = 0;
	result->link = 0;
	result->path_list = NULL;
	result->table_hesh = NULL;
	result->fd = -2;
	return (result);
}

t_room *ft_create_head(t_storage *st)
{
	t_room	*result;
	int		len;

	if (!(result = (t_room *)malloc(st->count_rooms * sizeof(t_room))))
	{
		return (NULL);
	}
	len = 0;
	while (len < st->count_rooms)
	{
		(result[len]).key = len;
		(result[len]).count_tube = 0;
		(result[len]).tube_in = NULL;
		(result[len]).tube_out = NULL;
		(result[len]).visited = 0;
		(result[len]).vertex = -1;
		len++;
	}
	return (result);
}

void	ft_free_head(t_room *head, int count_rooms)
{
	while (count_rooms--)
	{
		if (head[count_rooms].tube_in)
			free(head[count_rooms].tube_in);
	}
	free(head);
}

void	ft_free_storage(t_storage *st)
{
	if (st->fd > 2)
		close(st->fd);
	if (st->head)
		ft_free_head(st->head, st->count_rooms);
	if (st->path_list)
		ft_free_list_paths(st->path_list);
	if (st->table_hesh)
		ft_free_list_hesh(st->table_hesh);
	free(st);
}
