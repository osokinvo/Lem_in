/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_crossing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 16:23:23 by val               #+#    #+#             */
/*   Updated: 2020/07/25 18:01:22 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*ft_find_crossing_path(int *counter1, t_list_path *paths, t_path *path)
{
	t_path	*result;
	int		counter2;
	int		key;

	result = paths->paths;
	while (result)
	{
		*counter1 = result->count_rooms;
		while ((*counter1)--)
		{
			key = result->rooms[(*counter1)];
			counter2 = path->count_rooms;
			while (counter2--)
			{
				if (path->rooms[counter2] == key)
					return (result);
			}
		}
		result = result->next;
	}
	return (result);
}

void	ft_change_room_revisited(t_path *pre_crossing_path, t_room *head_culc)
{
	int count_rooms;
	int	count_tube;
	int	key_room;
	int	key_room1;
	int	key_room2;

	count_rooms = pre_crossing_path->count_rooms - 1;
	while (count_rooms-- > 1)
	{
		key_room = pre_crossing_path->rooms[count_rooms];
		key_room1 = pre_crossing_path->rooms[count_rooms - 1];
		key_room2 = pre_crossing_path->rooms[count_rooms + 1];
		head_culc[key_room].visited = 0;
		count_tube = head_culc[key_room].count_tube;
		while (count_tube--)
		{
			if (head_culc[key_room].tube_out[count_tube] == key_room1)
			{
				head_culc[key_room].tube_in[count_tube] = key_room1;
			}
			else if (head_culc[key_room].tube_in[count_tube] == key_room2)
			{
				head_culc[key_room].tube_in[count_tube] = key_room2;
			}
		}
		
	}
}

void	ft_del_tube(t_room *head_culc, int key_room1, int key_room2)
{
	int	counter;

	counter = head_culc[key_room1].count_tube;
	while (counter--)
	{
		if (head_culc[key_room1].tube_in[counter] == key_room2)
		{
			head_culc[key_room1].tube_in[counter] = INVALID_TUBE;
			head_culc[key_room1].tube_out[counter] = INVALID_TUBE;
			return;
		}
	}
}

void	ft_del_path(t_list_path *paths, t_path *path)
{
	t_path	*pre_path;

	if ((pre_path = paths->paths) == path)
	{
		paths->paths = path->next;
		path->next = NULL;
		return;
	}
	while (pre_path->next != path)
	{
		pre_path = pre_path->next;
	}
	pre_path->next = path->next;
	path->next = NULL;
}

void	ft_del_crossing(t_room *head_culc, t_list_path *paths, t_path *path)
{
	t_path *pre_crossing_path;
	int		key_room1;
	int		key_room2;
	int		counter;

	pre_crossing_path = ft_find_crossing_path(&counter, paths, path);
	ft_change_room_revisited(pre_crossing_path, head_culc);
	key_room1 = pre_crossing_path->rooms[counter];
	key_room2 = pre_crossing_path->rooms[counter - 1];
	ft_del_tube(head_culc, key_room1, key_room2);
	ft_del_tube(head_culc, key_room2, key_room1);
	ft_del_path(paths, pre_crossing_path);
	ft_free_path(pre_crossing_path);
	ft_free_path(pre_crossing_path);
}
