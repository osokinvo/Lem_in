/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:45:06 by val               #+#    #+#             */
/*   Updated: 2020/07/25 15:35:37 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_find_dead_end(t_room *head, int key, int power, int key_start)
{
	int counter;
	int dead_end;
	int	key_in;
	int	counter2;

	head[key].vertex = power++;
	dead_end = 1;
	counter = head[key].count_tube;
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
			if ((head[key_in]).vertex == -1 || (head[key_in]).vertex > power)
			{
				if (!(ft_find_dead_end(head, key_in, power, key_start)))
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

t_room	*ft_head_culc_copy(t_room *head_culc, t_storage *st)
{
	t_room *result;
	int		count_rooms;
	int		count_tube;
	int		key_room;

	count_rooms = st->count_rooms;
	if (!(result = (t_room *)malloc(count_rooms * sizeof(t_room))))
		return (NULL);
	while (count_rooms--)
	{
		if (!(result[count_rooms].tube_in = (int *)malloc(2 * (head_culc[count_rooms].count_tube))))
		{
			while (++count_rooms < st->count_rooms)
				free(result[count_rooms].tube_in);
			free(result);
			return (NULL);
		}
		count_tube = head_culc[count_rooms].count_tube;
		result[count_rooms].tube_out = result[count_rooms].tube_in + count_tube;
		while(count_tube--)
		{
			key_room = head_culc[count_rooms].tube_in[count_tube];
			result[count_rooms].tube_in[count_tube] = key_room;
			result[count_rooms].tube_out[count_tube] = key_room;
		}
	}
	return (result);
}

int	ft_data_processing(t_storage *st)
{
	t_room *head_culc;
	
	st->key_start = hesh_get_key(st->name_start, st);
	st->key_end = hesh_get_key(st->name_end, st);
	if (!(head_culc = ft_head_culc_copy(st->head, st)))
		return
	ft_find_dead_end(head_culc, st->key_end, 0, st->key_start);
	if (ft_recurse(head_culc, ft_create_list_path(), st))
		return (EXIT_FAILURE);
	ft_print_path(st);//еще нет
	
	return (EXIT_SUCCESS);
}
