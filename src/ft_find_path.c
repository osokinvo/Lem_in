/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 09:35:51 by val               #+#    #+#             */
/*   Updated: 2020/08/03 08:29:15 by val              ###   ########.fr       */
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

	head[key].vertex = power++;
	if (key == key_start)
		return;
	counter = head[key].count_tube;
	while (counter--)
	{
		key_in = (head[key]).tube_in[counter];
		if (key_in != INVALID_TUBE)
		{
			if ((head[key_in]).vertex == -1 || (head[key_in]).vertex > power)
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

	head[key].vertex = power++;
	if (key == key_start)
		return;
	counter = head[key].count_tube;
	while (counter--)
	{
		key_in = (head[key]).tube_in[counter];
		if (key_in != INVALID_TUBE && !((head[key_in]).visited))
		{
			if ((head[key_in]).vertex == -1 || (head[key_in]).vertex > power)
			{
				ft_breadth_first_search_uncrosing(head, key_in, power, key_start);
			}
		}
	}
}

void	ft_print_head(t_room *head_culc, int count_rooms, t_list_hesh *list)
{
	int	counter;
	int	counter1;

	ft_putstr("\nPrint head\n");
	counter = 0;
	while (counter < count_rooms)
	{
		ft_putstr("Rooms key = ");
		ft_putnbr(counter);
		ft_putchar('\n');
		ft_putstr("Rooms name: ");
		ft_putstr(hesh_get_name(counter, list));
		ft_putchar('\n');
		counter1 = head_culc[counter].count_tube;
		ft_putstr("Tube_in: \n");
		while (counter1--)
		{
			ft_putnbr(head_culc[counter].tube_in[counter1]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
		ft_putstr("Tube_out:\n");
		counter1 = head_culc[counter].count_tube;
		while (counter1--)
		{
			ft_putnbr(head_culc[counter].tube_out[counter1]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
		counter++;
	}
	ft_putchar('\n');
	
}

t_path *ft_find_path(t_room *head_culc, t_storage *st, int uncrosing, int *exist)
{
	t_path	*result;
	int		count_rooms;
	int		counter;
	int		key;
	int		min_vertex;

	//ft_print_head(head_culc, st->count_rooms, st->table_hesh);
	if (!(result = (t_path *)malloc(sizeof(t_path))))
		return (NULL);
	ft_deffult_vertex(head_culc, st->count_rooms);
	key = st->key_start;
	counter = head_culc[key].count_tube;
	if (uncrosing)
		ft_breadth_first_search_uncrosing(head_culc, st->key_end, 0, key);
	else
		ft_breadth_first_search(head_culc, st->key_end, 0, key);
	counter = head_culc[key].count_tube;
	if (head_culc[key].vertex == -1)
	{
		*exist = 0;
		free(result);
		return (NULL);
	}
	result->next = NULL;
	result->count_rooms = head_culc[key].vertex + 1;
	if (!(result->rooms = (int *)malloc(result->count_rooms * sizeof(int))))
	{
		ft_putstr("Exit01\n");
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
			if (counter == head_culc[key].count_tube || (min_vertex = head_culc[key].vertex - 1) < 0)
			{
				ft_putstr("Exit02\n");
				free(result->rooms);
				free(result);
				return (NULL);
			}
			while (counter < head_culc[key].count_tube && (head_culc[key].tube_out[counter] == INVALID_TUBE ||
				head_culc[head_culc[key].tube_out[counter]].vertex != min_vertex))
			{
				counter++;
			}
			if (counter == head_culc[key].count_tube)
			{
				counter = head_culc[key].count_tube;
				ft_putstr("Key_room = ");
				ft_putnbr(key);
				ft_putchar('\n');
				ft_putstr("Room_vertex = ");
				ft_putnbr(head_culc[key].vertex);
				ft_putchar('\n');
				ft_putstr("Room is visited ");
				ft_putnbr(head_culc[key].visited);
				ft_putchar('\n');
				ft_putstr("Min_vertex = ");
				ft_putnbr(min_vertex);
				ft_putchar('\n');
				while (counter--)
				{
					ft_putnbr(head_culc[key].tube_out[counter]);
					if (head_culc[key].tube_out[counter] != INVALID_TUBE)
					{
						ft_putchar(' ');
						ft_putnbr(head_culc[head_culc[key].tube_out[counter]].vertex);;
					}
					ft_putchar('\n');
				}
				ft_putstr("Key_start = ");
				ft_putnbr(st->key_start);
				ft_putchar('\n');
				ft_putstr("Key_end = ");
				ft_putnbr(st->key_end);
				ft_putchar('\n');
				count_rooms = st->count_rooms;
				while (count_rooms--)
				{
					if (head_culc[count_rooms].vertex == min_vertex)
					{
						ft_putstr("Must_room = ");
					ft_putnbr(count_rooms);
					ft_putchar('\n');
					counter = head_culc[count_rooms].count_tube;
					while (counter--)
					{
						ft_putchar('\t');
						ft_putnbr(head_culc[count_rooms].tube_in[counter]);
						if (head_culc[count_rooms].tube_in[counter] != INVALID_TUBE)
						{
							ft_putchar(' ');
							ft_putnbr(head_culc[head_culc[count_rooms].tube_in[counter]].vertex);;
						}
						ft_putchar('\n');
					}
					}
				}
				
				ft_putstr("Exit03\n");
				free(result->rooms);
				free(result);
				return (NULL);
			}
			key = head_culc[key].tube_out[counter];
		}
	}
	return (result);
}
