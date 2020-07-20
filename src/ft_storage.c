/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_storage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 06:03:26 by val               #+#    #+#             */
/*   Updated: 2020/07/14 20:13:52 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_storage *ft_create_storage(void)
{
	t_storage *result;

	if (!(result = (t_storage *)malloc(sizeof(t_storage))))
		return (NULL);
	result->head = NULL;
	result->head_culc = NULL;
	result->key_end = 0;
	result->key_start = 0;
	result->link = 0;
	result->path_list = NULL;
	result->path_list_condidate = NULL;
	result->table_hesh = NULL;
	return (result);
}

t_room *ft_create_head(t_storage *st)
{
	t_room	*result;
	int		len;

	if (st->count_room == 0 || !(result = (t_room *)malloc(st->count_room * sizeof(t_room))))
	{
		return (NULL);
	}
	len = 0;
	while (len < st->count_room)
	{
		(result[len]).key = len;
		(result[len]).count_tube_in = 0;
		(result[len]).count_tube_out = 0;
		(result[len]).tube_in = NULL;
		(result[len]).tube_out = NULL;
		(result[len]).weight_in = NULL;
		(result[len]).weight_out = NULL;
		(result[len]).vertex = -1;
		len++;
	}
	return (result);
}

void	ft_free_head(t_room *head, int count_room)
{
	while (count_room--)
	{
		if (head[count_room].tube_in)
			free(head[count_room].tube_in);
		if (head[count_room].tube_out)
			free(head[count_room].tube_out);
		if (head[count_room].tube_in)
			free(head[count_room].weight_in);
		if (head[count_room].tube_in)
			free(head[count_room].weight_out);
	}
	free(head);
}

void	ft_free_storage(t_storage *st)
{
	if (st->head)
		ft_free_head(st->head, st->count_room);
	if (st->head_culc)
		ft_free_head(st->head_culc, st->count_room);
	if (st->path_list)
		ft_free_path_list(st->path_list);
	if (st->path_list_condidate)
		ft_free_path_list(st->path_list_condidate);
	if (st->table_hesh)
		ft_free_list_hesh(st->table_hesh);
	free(st);
}
