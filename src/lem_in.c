/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 06:01:18 by val               #+#    #+#             */
/*   Updated: 2020/07/14 19:58:08 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_list.h"

int			ft_set_link(int key1, int key2, t_storage *st)
{
	int	count_tube;
	int	*tube_in;

	count_tube = (st->head[key1]).count_tube_in;
	if (count_tube == 0)
	{
		if (!(tube_in = (int *)malloc(sizeof(int))))
		{
			return (EXIT_FAILURE);
		}
		((st->head[key1]).count_tube_in)++;
		tube_in[0] = key2;
		(st->head[key1]).tube_in = tube_in;
		return (EXIT_SUCCESS);
	}
	tube_in = (st->head[key1]).tube_in;
	while (count_tube--)
	{
		if (tube_in[count_tube] == key2)
			return (EXIT_SUCCESS);
	}
	count_tube = (st->head[key1]).count_tube_in + 1;
	if (!(tube_in = (int *)malloc(count_tube * sizeof(int))))
	{
		return (EXIT_FAILURE);
	}
		tube_in[--count_tube] = key2;
	while (count_tube--)
	{
		tube_in[count_tube] = (st->head[key1]).tube_in[count_tube];
	}
	free((st->head[key1]).tube_in);
	((st->head[key1]).count_tube_in)++;
	(st->head[key1]).tube_in = tube_in;
	return (EXIT_SUCCESS);
}

int			ft_crate_link(char *s, t_storage *st)
{
	int		key1;
	int		key2;
	char	*dash;
	char	*name1;
	char	*name2;

	name1 = s;
	dash = ft_is_char('-', s);
	name2 = dash + 1;
	*dash = '\0';
	if ((key1 = hash_get_key(name1, st)) < 0)
		return (EXIT_FAILURE);
	if ((key2 = hash_get_key(name2, st)) < 0)
		return (EXIT_FAILURE);
	if (key1 == key2)
		return (EXIT_FAILURE);
	if (ft_set_link(key1, key2, st))
		return (EXIT_FAILURE);
	if (ft_set_link(key2, key1, st))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
int			ft_is_link(char *s, t_storage *st)
{
	char	*dash;
	
	if (*s == 'L')
		return (0);
	if (!(dash = ft_is_char('-', s)))
		return (0);
	if (*(dash + 1) == '\0' || *(dash + 1) == 'L' || *(dash + 1) == '#')
		return (0);
	if ((dash = ft_is_char('-', dash + 1)))
		return (0);
	if (ft_is_char(' ', s))
		return (0);
	return(1);
}

t_list_hesh	*ft_is_room(char *s, t_storage *st)
{
	char	*name;
	int		x;
	int		y;
	int		len;
	t_list_hesh	*room;

	if (*s && *s == 'L')
		return (NULL);
	len = 0;
	while (s[len] != ' ')
		len++;
	if (!(name = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	ft_strncpy(name, s, len);
	name[len] = '\0';
	x = ft_atoi1(s + len + 1, &s, 1);
	if (*s != ' ')
	{
		free(name);
		return (NULL);
	}
	y = ft_atoi1(s + 1, &s, 1);
	if (*s != '\0')
	{
		free (name);
		return (NULL);
	}
	if (!(room = ft_create_list_hesh(name, x, y, st)))
	{
		free(name);	
		return (0);
	}
	return (room);
}

int	ft_read_other(char *s, t_storage *st)
{
	t_list_hesh	*room;

	if (!(st->link) && (room = ft_is_room(s, st)))
	{
		if (st->key_start == 1)
		{
			st->name_start = room->name;
			st->key_start = -1;
		}
		else if (st->key_end == 1)
		{
			st->name_end = room->name;
			st->key_start = -1;
		}
	}
	else if (ft_is_link(s, st))
	{
		if (st->link == 0)
		{
			st->link = 1;
			st->count_room = hesh_install_key(0, st->table_hesh);
			if (st->count_room == 0 || !(st->head = ft_create_head(st->table_hesh)))
				return (EXIT_FAILURE);
		}
		if (ft_create_link(s, st))
		{
			return (EXIT_FAILURE);
		}
	}
	else
	{
		return(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_read_comment(char *s, t_storage *st)
{
	if (!(ft_strcmp(s, "##end")))
	{
		if (!(st->key_end))
			st->key_end = 1;
		else
			return (EXIT_FAILURE);	
	}
	else if (!(ft_strcmp(s, "##start")))
	{
		if (!(st->key_start))
			st->key_start = 1;
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
		
}

int	ft_read_input(t_storage *st)
{
	char	*s;
	int ret;
	
	while ((ret = get_next_line1(1, &s)) > 0)
	{
		if (s && *s == '#')
		{
			if (ft_read_comment(s, st))
			{
				free(s);
				return(ft_error(st));
			}
		}
		else
		{
			if (ft_read_other(s, st))
			{
				free(s);
				return(ft_error(st));
			}
		}
		free (s);
	}
	return (ft_data_processing(st));
}

int	main(int argc, char *argv)
{
	t_storage *st;
	char	*s;
	char	*str_end;
	int		ret;

	if (argc > 1)
	{
		if (!(st = ft_create_storage()))
			return (ft_error(NULL));
		if (get_next_line1(0, &s) <= 0);
			return (ft_error(NULL));
		if (s && *s == '#')
		{
			ft_read_comment(s, st);
		}
		else
		{
			st->count_ants = ft_atoi1(s, str_end, 1);
			if (*str_end != '\0' || st->count_ants < 0)
			{
				return (ft_error(st));
			}
		}
		free(s);
		return (ft_read_input(st));
	}
	return (1);
}