/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 16:28:50 by val               #+#    #+#             */
/*   Updated: 2020/07/25 17:52:16 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int ft_error_in_ft_recurse(t_path *first_path, t_path *second_path,
	t_room *head_culc, t_list_path *path)
{
	if (first_path)
		free(first_path);
	if (second_path)
		free(second_path);
	if (head_culc)
		free(head_culc);
	if (path)
		free(path);
	return (EXIT_FAILURE);
}

void	ft_change_room_visited(t_path *path, t_room *head_culc)//изменить
{
	int	count_rooms;
	int	count_tube;
	int	key_room;
	int	key_room1;
	int	key_room2;

	count_rooms = path->count_rooms - 1;
	while (count_rooms-- > 1)
	{
		key_room = path->rooms[count_rooms];
		key_room1 = path->rooms[count_rooms - 1];
		key_room2 = path->rooms[count_rooms + 1];
		count_tube = head_culc[key_room].count_tube;
		while (count_tube--)
		{
			if (head_culc[key_room].tube_in[count_tube] == key_room1)
			{
				head_culc[key_room].tube_in[count_tube] = INVALID_TUBE;
			}
			else if (head_culc[key_room].tube_out[count_tube] == key_room2)
			{
				head_culc[key_room].tube_out[count_tube] = INVALID_TUBE;
			}
		}
		head_culc[key_room].visited = 1;
	}
}

t_room	*ft_head_culc_copy(t_room *head_culc, t_path *first_path, t_storage *st)
{
	t_room *result;
	int		count_rooms;
	int		count_tube;

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
			result[count_rooms].tube_in[count_tube] = head_culc[count_rooms].tube_in[count_tube];
			result[count_rooms].tube_out[count_tube] = head_culc[count_rooms].tube_out[count_tube];
		}
	}
	ft_change_room_visited(first_path, result);
	return (result);
}

void	ft_add_path(t_list_path *paths, t_path *new_path)
{
	t_path	*path;

	if (!(path = paths->paths))
	{
		paths->paths = new_path;
		paths->count_path = 1;
		return;
	}
	while (path->next)
		path = path->next;
	path->next = new_path;
	(paths->count_path)++;
}

t_path		*ft_path_copy(t_path *exist_path, t_path *new_path)
{
	t_path	*result;
	int		count_rooms;

	if (!(result = (t_path *)malloc(sizeof(t_path))))
		return (NULL);
	count_rooms = exist_path->count_rooms;
	if (!(result->rooms = (int *)malloc(count_rooms * sizeof(int))))
	{
		free(result);
		return (NULL);
	}
	while (count_rooms--)
	{
		result->rooms[count_rooms] = exist_path->rooms[count_rooms];
	}
	if (exist_path->next)
	{
		if (!(result->next = ft_path_copy(exist_path->next, new_path)))
		{
			free(result->rooms);
			free (result);
			return (NULL);
		}
	}
	else
	{
		result->next = new_path;
	}
	result->count_rooms = exist_path->count_rooms;
	return (result);
}

t_list_path	*ft_paths_copy(t_list_path *paths, t_path *new_path)
{
	t_list_path *result;

	if (!(result = (t_list_path *)malloc(sizeof(t_list_path))))
	{
		free(new_path);
		return (NULL);
	}
	result->heigth = -1;
	if (!(paths->paths))
	{
		result->paths = new_path;
		result->count_path = 1;
		return (result);
	}
	else if (!(result->paths = ft_path_copy(paths->paths, new_path)))
	{
		free(new_path);
		free(result);
		return(NULL);
	}
	result->paths = paths->count_path + 1;
	return (result);
}

int ft_is_crossing_paths(t_path *path, t_room *head_culc)
{
	int	counter_rooms;
	int	key_room;
	
	counter_rooms = path->count_rooms - 1;
	while (counter_rooms-- > 1)
	{
		if (head_culc[path->rooms[counter_rooms]].visited)
			return (1);
	}
	return (0);
}

int		ft_heigth_paths(int	count_ants, int count_paths, t_path	*path)
{
	int	heigth_path[count_paths];
	int	counter;
	int	barrier;

	counter = 0;
	while (counter < count_paths)
	{
		heigth_path[counter++] = path->count_rooms;
		path = path->next;
	}
	barrier = 1;
	heigth_path[0] = __INT_MAX__;
	while (count_ants > 0)
		if (barrier < count_paths)
		{
			if (heigth_path[barrier - 1] < heigth_path[barrier])
			{
				counter = 0;
				while (counter < barrier)
				{
					(heigth_path[counter])++;
					count_ants--;
				}
			}
			else
				barrier++;
		}
		else
		{
			counter = 0;
			while (counter < count_paths)
			{
				(heigth_path[counter])++;
				count_ants--;
			}
		}
	return (heigth_path[0]);
}

void	ft_compare_paths(t_list_path *paths, t_storage *st)
{
	paths->heigth = ft_heigth_paths(st->count_ants, paths->count_path, paths->paths);
	if (!(st->path_list))
	{
		st->path_list = paths;
	}
	else
	{
		if (st->path_list->heigth > paths->heigth)
		{
			ft_feee_list_paths(st->path_list);
			st->path_list = paths;
		}
		else
			ft_feee_list_paths(paths);
	}
}

// готовые пути уже имеют вес -1
// head_culc является копией
// path является копией
int	ft_recurse(t_room *head_culc, t_list_path *paths, t_storage *st)
{
	t_path	*second_path;
	t_path	*first_path;

	if (!(head_culc) || !(paths))
		return (ft_error_in_ft_recurse(NULL, NULL, head_culc, paths));
	while (++(paths->count_path) <= st->max_count_path)
	{
		if (!(second_path = ft_find_path(head_culc, st, 0)))
			return (ft_error_in_ft_recurse(NULL, NULL, head_culc, paths));
		if (ft_is_crossing_paths(second_path, head_culc))
		{
			if (!(first_path = ft_find_path(head_culc, st, 1)))
			{
				return (ft_error_in_ft_recurse(NULL, second_path, head_culc, paths));
			}
			if (ft_recurse(ft_head_culc_copy(head_culc, first_path, st), ft_paths_copy(paths, first_path), st))
			{
				return (ft_error_in_ft_recurse(first_path, second_path, head_culc, paths));
			}
			ft_del_crossing(head_culc, paths, second_path);
		}
		else
		{
			ft_add_path(paths, second_path);
			ft_change_room_visited(second_path, head_culc);
		}
	}	
	ft_free_head(head_culc, st->count_rooms);
	ft_compare_paths(paths, st);
	return (EXIT_SUCCESS);
}