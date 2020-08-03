/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 21:50:41 by val               #+#    #+#             */
/*   Updated: 2020/07/30 20:43:31 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <unistd.h>
#include <fcntl.h>

void	ft_print_lem(int lem, char *room, int *space)
{
	if (*space)
	{
		if (write(1, " ", 1) == -1)
			return;
	}
	else
		*space = 1;
	if (write(1, "L", 1) == -1)
		return;
	ft_putnbr(lem);
	if (write(1, "-", 1) == -1 || write(1, room, ft_strlen(room)) == -1)
		return;
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
		if (write(1, tmp, ret) == -1)
			return (EXIT_FAILURE);
	}
	if (ret == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	*ft_create_table_lem(int heigth, int count_paths, int count_ants, t_path *path)
{
	int	*result;
	int	k;
	int	h;
	int ant;
	t_path	*p;

	if (!(result = (int *)malloc(heigth * count_paths * sizeof(int))))
		return (NULL);
	k = count_paths;
	while (k--)
	{
		h = heigth;
		while (h--)
		{
			result[(h * count_paths) + k] = -1;
		}
	}
	h = heigth;
	ant = 0;
	while (h-- && ant < count_ants)
	{
		k = 0;
		p = path;
		while (k < count_paths && ant < count_ants)
		{
			if ((h - p->count_rooms) >= 0)
				result[((h - p->count_rooms) * count_paths) + k] = ++ant;
			k++;
			p = p->next;
		}
	}
	return (result);
}

char	**ft_create_table_name(int heigth, int count_paths, t_path *path, t_list_hesh *table_hesh)
{
	char	**result;
	int	k;
	int	h;
	int	invisible;

	if (!(result = (char **)malloc(heigth * count_paths * sizeof(char *))))
		return (NULL);
	k = count_paths;
	while (k--)
	{
		h = heigth;
		invisible = heigth - path->count_rooms;
		while (h--)
		{
			if (h > invisible)
				result[(h * count_paths) + k] = hesh_get_name(path->rooms[h - invisible], table_hesh);
			else
				result[(h * count_paths) + k] = NULL;
		}
		path = path->next;
	}
	return (result);
}

void	ft_print_lines(int *table_lem, char **table_name, int heigth, int count_paths)
{
	int	k;
	int	n;
	int	space;

	space = 0;
	while (heigth--)
	{
		k = 0;
		while (k < count_paths)
		{
			n = (heigth * count_paths) + k++;
			if (table_name[n] && table_lem[n] > 0)
			{
				ft_print_lem(table_lem[n], table_name[n], &space);
			}
		}
	}
	if (write(1, "\n", 1) ==-1 )
		return;
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
	k = count_paths;
	while (k--)
	{
		table_lem[k] = -1;
	}
}
int	ft_ant_in_room(int *table_lem, int heigth, int count_paths)
{
	int	k;

	while (heigth--)
	{
		k = count_paths;
		while (k--)
		{
			if (table_lem[(heigth * count_paths) + k] > 0)
			{
				return (1);
			}
		}
	}
	return (0);
}

int		ft_print_movement(int *table_lem, char **table_name, int heigth, t_storage *st)
{
	int	count_paths;

	count_paths = st->path_list->count_path;
	if (write(1, "\n", 1) == -1)
		return (EXIT_FAILURE);
	while (ft_ant_in_room(table_lem, heigth, count_paths))
	{
		ft_lem_shift(table_lem, heigth, count_paths);
		ft_print_lines(table_lem, table_name, heigth, count_paths);
	}
	return (EXIT_SUCCESS);
}

int	ft_print_paths(t_path *path,t_storage *st)
{
	int		*table_lem;
	char	**table_name;
	int 	heigth;
	int 	count_paths;

	if (ft_print_file(st))
		return (EXIT_FAILURE);
	heigth = st->path_list->heigth;
	count_paths = st->path_list->count_path;
	if (!(table_lem = ft_create_table_lem(heigth, count_paths, st->count_ants, path)))
		return (EXIT_FAILURE);
	if (!(table_name = ft_create_table_name(heigth, count_paths, path, st->table_hesh)))
	{
		free(table_lem);
		return (EXIT_FAILURE);
	}
	if (ft_print_movement(table_lem, table_name, heigth, st))
	{
		free(table_name);
		free(table_lem);
		return (EXIT_FAILURE);
	}
	free(table_name);
	free(table_lem);
	return (EXIT_SUCCESS);
}