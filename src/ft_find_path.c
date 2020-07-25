/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 09:35:51 by val               #+#    #+#             */
/*   Updated: 2020/07/25 16:20:24 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_deffult_vertex(t_room *head_culc, int count_rooms)
{
	while (count_rooms--)
	{
		head_culc[count_rooms].vertex = -1;
	}
}

void	ft_breadth_first_search(t_room *head, int key, int power, int key_start)
{
	int counter;
	int	key_in;
	int	counter2;

	head[key].vertex = power++;
	counter = head[key].count_tube;
	while (counter--)
	{
		key_in = (head[key]).tube_in[counter];
		if (key_in != -1)
		{
			if (key_in == key_start)
				return;
			if ((head[key_in]).vertex == -1 || (head[counter]).vertex > power)
			{
				ft_breadth_first_search(head, key_in, power, key_start);
			}
		}
	}
}

void	ft_breadth_first_search_uncrosing(t_room *head, int key, int power, int key_start)
{
	int counter;
	int	key_in;
	int	counter2;

	head[key].vertex = power++;
	counter = head[key].count_tube;
	while (counter--)
	{
		key_in = (head[key]).tube_in[counter];
		if (key_in != INVALID_TUBE && !((head[key_in]).visited))
		{
			if (key_in == key_start)
				return;
			if ((head[key_in]).vertex == -1 || (head[counter]).vertex > power)
			{
				ft_breadth_first_search_uncrosing(head, key_in, power, key_start);
			}
		}
	}
}

t_path *ft_find_path(t_room *head_culc, t_storage *st, int uncrosing)
{
	t_path	*result;
	int		count_rooms;
	int		counter;
	int		key;
	int		min_vertex;

	if (!(result = (t_path *)malloc(sizeof(t_path))))
		return (NULL);
	ft_deffult_vertex(head_culc, st->count_rooms);
	key = st->key_start;
	if (uncrosing)
		ft_breadth_first_search_uncrosing(head_culc, st->key_end, 0, key);
	else
		ft_breadth_first_search(head_culc, st->key_end, 0, key);
	if (head_culc[key].vertex == -1)
	{
		free(result);
		return (NULL);
	}
	result->count_rooms = head_culc[key].vertex + 1;
	if (!(result->rooms = (int *)malloc(result->count_rooms * sizeof(int))))
	{
		free(result);
		return (NULL);
	}
	count_rooms = 0;
	while (count_rooms < result->count_rooms)
	{
		result->rooms[count_rooms++] = key;
		if (key != st->key_end)
		{
			counter = 0;
			while (counter < head_culc[key].count_tube && head_culc[key].tube_out[counter] == INVALID_TUBE)
			{
				counter++;
			}
			if (counter = head_culc[key].count_tube || (min_vertex = head_culc[key].vertex - 1) < 0)
			{
				free(result->rooms);
				free(result);
				return (NULL);
			}
			while (counter < head_culc[key].count_tube && head_culc[head_culc[key].tube_out[counter]].vertex != min_vertex)
			{
				counter++;
			}
			if (counter = head_culc[key].count_tube)
			{
				free(result->rooms);
				free(result);
				return (NULL);
			}
			key = head_culc[key].tube_out[counter];
		}
	}
	return (result);
}
