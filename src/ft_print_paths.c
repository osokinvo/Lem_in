/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 21:50:41 by val               #+#    #+#             */
/*   Updated: 2020/07/26 01:02:47 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <unistd.h>
#include <fcntl.h>

int	ft_print_lem(int lem, char *room)
{
	char	*str;

	if (!(str = ft_itoa(lem)))
		return(EXIT_FAILURE);
	write(1, "L", 1);
	write(1, str, ft_strlen(str));
	write(1, "-", 1);
	write(1, room, ft_strlen(room));
	free(str);
}

int	ft_print_file(t_storage *st)
{
	char	tmp[SIZE_FILE + 1];
	int		ret;

	tmp[SIZE_FILE] = '\0';
	close(st->fd);
	if ((st->fd = open(st->file_name, O_RDONLY)) == -1)
		return (EXIT_FAILURE);
	while ((ret = read(st->fd, tmp, SIZE_FILE)))
	{
		write(1, tmp, SIZE_FILE);
	}
	if (ret == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
/*
int	ft_create_additions(t_room *head, t_storage *st)
{
	int 			key_room;
	t_room_addition	*add;

	key_room = st->count_rooms;
	
	while (key_room--)
	{
		if (!(head[key_room].add - (t_room_addition *)malloc(sizeof(t_room_addition))))
		{
			while (++key_room < st->count_rooms)
			{
				free(head[key_room].add);
			}
			return (EXIT_FAILURE);
		}
		head[key_room].add->name = hesh_get_name(key_room, st->table_hesh);
	}
	ft_free_list_hash1(st->table_hesh);
	st->table_hesh = NULL;
}

void	ft_install_default_lem(t_path *path, t_storage *st)
{
	int	min_heigth;
	int	counter;
	
	if (path)
		min_heigth = path->count_rooms;
	while (path)
	{
		counter = path->count_rooms - 1;
		while (counter--)
		{
			
		}
		
		
	}
	
}*/

int	*ft_create_table_lem(int heigth, int count_paths, t_path *path)
{
	int	*result;
	int	k;
	int	h;
	int	n;
	int	min;

	if (!(result = (int *)malloc(heigth * count_paths * sizeof(int))))
		return (NULL);
	k = 0;
	min = path->count_rooms;
	while (k < count_paths)
	{
		result[k] = min - path->count_rooms;
		path = path->next;
	}
	h = 0;
	while (++h < heigth)
	{
		k = 0;
		while (k < count_paths)
		{
			result[(h * count_paths) + k] = result[((h - 1) * count_paths) + k] - 1;
			k++;
		}
	}
	return (result);
}

char	**ft_create_table_name(int heigth, int count_paths, t_path *path, t_list_hesh *table_hesh)
{
	char	**result;
	int	k;
	int	h;
	int	n;
	int	min;
	int	diff;

	if (!(result = (char **)malloc(heigth * count_paths * sizeof(char *))))
		return (NULL);
	k = 0;
	min = path->count_rooms;
	while (k < count_paths)
	{
		h = 0;
		diff = path->count_rooms - min;
		while (h < heigth)
		{
			n = (h * count_paths) + k;
			if ((h >= path->count_rooms + diff) || (h < diff))
				result[n] = NULL;
			else
			{
				result[n] = hesh_get_name(path->rooms[h - diff + 1], table_hesh);
			}
			h++;
		}
		k++;
		path = path->next;
	}
	return (result);
}

int	ft_max_count_rooms(t_path *path)
{
	int result;

	result = path->count_rooms;
	while (path)
	{
		if (path->count_rooms > result)
			result = path->count_rooms;
		path = path->next;
	}
	return (result);
}

void	ft_set_new_line(int	*table_lem, int count_paths, int *last_ant, int count_ants)
{
	while (count_paths--)
	{
		if((*last_ant) < count_ants)
		{
			if (table_lem[count_paths] >= 0)
				table_lem[count_paths] = ++(last_ant);
			if (table_lem[count_paths] < 0)
				(table_lem[count_paths])++;
		}
		else
		{
			table_lem[count_paths] = - count_paths;
		}
		
	}
}

void	ft_print_lines(int *table_lem, char **table_name, int heigth, int count_paths)
{
	int	k;
	int	n;

	while (heigth--)
	{
		k = 0;
		while (k < count_paths)
		{
			n = (heigth * count_paths) + k++;
			if (table_lem[n] > 0)
			{
				write(1, table_name[n], ft_strlen(table_name[n]));
				if (k != count_paths)
					write(1, " ", 1);
			}
		}
	}
	write(1, "\n", 1);
}

void	ft_lem_shift(int *table_lem, int heigth, int count_paths)
{
	int	k;
	int	n;

	while (--heigth)
	{
		k = count_paths;
		while (k--)
		{
			n = (heigth * count_paths) + k;
			table_lem[n] = table_lem[n - count_paths];
		}
	}
}

void	ft_print_movement(int *table_lem, char **table_name, int heigth, t_storage *st)
{
	int	last_ant;
	int	count_ants;
	int	count_paths;

	last_ant = 0;
	count_ants = st->count_ants;
	count_paths = st->path_list->count_path;
	write(1, "\n", 1);
	while (last_ant != count_ants)
	{
		ft_set_new_line(table_lem, count_paths, &last_ant, count_ants);
		ft_print_lines(table_lem, table_name, heigth, count_paths);
		ft_lem_shift(table_lem, heigth, count_paths);
	}
	
}

int	ft_print_paths(t_path *path,t_storage *st)
{
	int		*table_lem;
	char	**table_name;
	int 	heigth;
	int 	count_paths;

	if (ft_print_file(st))
		return (EXIT_FAILURE);
	heigth = ft_max_count_rooms(path);
	count_paths = st->path_list->count_path;
	if (!(table_lem = ft_create_table_lem(heigth, count_paths, path)))
		return (EXIT_FAILURE);
	if (!(table_name = ft_create_table_name(heigth, count_paths, path, st->table_hesh)))
	{
		free(table_lem);
		return (EXIT_FAILURE);
	}
	ft_print_movement(table_lem, table_name, heigth, st);
	free(table_name);
	free(table_name);
	/*if (ft_create_additions(st->head, st))
		return (EXIT_FAILURE);
	ft_install_default_lem(st->path_list->paths, st);*/
	
}