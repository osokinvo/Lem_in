/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:45:06 by val               #+#    #+#             */
/*   Updated: 2020/07/24 13:06:05 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_find_dead_end(t_room *head, int key, int power, int key_start)
{
	int counter;
	int dead_end;
	int	key_in;
	int	counter2;
	int	counter2;

	head[key].vertex = power++;
	dead_end = 1;
	counter = head[key].count_tube;
	while (counter--)
	{
		key_in = (head[key]).tube_in[counter];

	head[key].vertex = power++;
	dead_end = 1;
	counter = head[key].count_tube;
	while (counter--)
	{
		key_in = (head[key]).tube_in[counter];
		if (key_in != -1)
		{
			if (key_in == key_start)
				return (0);
			if ((head[key_in]).vertex == -1 || (head[counter]).vertex > power)
			{
				if (!(ft_find_dead_end(head, counter, power, key_start)))
				{
					dead_end = 0;
				}
				else
				{
					(head[key]).tube_in[counter] = -1;
					counter2 = (head[key_in]).count_tube;
					while (counter2--)
					{
						if ((head[key_in]).tube_in[counter2] == key)
							(head[key_in]).tube_in[counter2] = -1;
					}
				}
			}
		}
	}
	return (dead_end);
}

int	ft_data_processing2(t_storage *st)
{
	t_room	*head_culc;
	t_room	*head;
	int		len;
	int		counter;

	if (st->count_rooms == 0 || !(head_culc = (t_room *)malloc(st->count_rooms * sizeof(t_room))))
	{
		return (ft_error(st));
	}
	len = 0;
	head = st->head;
	while (len < st->count_rooms)
	{
		if (!((head_culc[len]).tube_in = (int *)malloc(sizeof(int) * (head[len]).count_tube)))
		{
			while (len--)
			{
				free((head_culc[len]).tube_in);
				free((head_culc[len]).tube_out);
			}
			free(head_culc);
			return (ft_error(st));
		}
		counter = (head[len]).count_tube;
		while (counter--)
		{
			(head_culc[len]).tube_in[counter] = head[len].tube_in[counter];
		}
		(head_culc[len]).count_tube = (head[len]).count_tube;
		if (!((head_culc[len]).tube_out = (int *)malloc(sizeof(int) * (head[len]).count_tube)))
		{
			free((head_culc[len]).tube_in);
			while (len--)
			{
				free((head_culc[len]).tube_in);
				free((head_culc[len]).tube_out);
			}
			free(head_culc);
			return (ft_error(st));
		}
		counter = (head[len]).count_tube;
		while (counter--)
		{
			(head_culc[len]).tube_out[counter] = head[len].tube_in[counter];
		}
		(head_culc[len]).count_tube = (head[len]).count_tube;
		(head_culc[len]).key = (head[len]).key;
		(head_culc[len]).weight_in = NULL;
		(head_culc[len]).weight_out = NULL;
		(head_culc[len]).vertex = -1;
		len++;
	}
	st->head_culc = head_culc;
}

int	ft_data_processing(t_storage *st)
{
	st->key_start = hesh_get_key(st->name_start, st);
	st->key_end = hesh_get_key(st->name_end, st);
	
	ft_find_dead_end(st->head_culc, st->head_culc + st->key_end, 0, st->key_start);
	return (ft_data_processing2(st));
}
