/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_hesh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 05:25:04 by val               #+#    #+#             */
/*   Updated: 2020/07/24 18:31:46 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list_hesh	*ft_create_list_hesh(char *name, int x, int y, t_storage *st)
{
	t_list_hesh *result;
	t_list_hesh	*list;

	if (!(result = (t_storage *)malloc(sizeof(t_list_hesh))))
		return (NULL);
	result->name = result;
	result->x = x;
	result->y = y;
	result->level = 0;
	result->next = NULL;
	result->deep = NULL;
	if (!(list = st->table_hesh))
	{
		st->table_hesh = result;
	}
	else
	{
		if ((list->name)[0] > name[0])
		{
			result->next = list;
			st->table_hesh = result;
			return (result);
		}
		while (list)
		{
			if ((list->name)[list->level] < name[result->level])
			{
				if (!(list->next))
				{
					list->next = result;
					return (result);
				}
				else if ((list->next->name)[list->level] > name[result->level])
				{
					result->next = list->next;
					list->next = result;
					return (result);
				}
				else
				{
					list = list->next;
				}	
			}
			else if ((list->name)[list->level] == name[result->level])
			{
				if (ft_strequ(list->name, name))
				{
					free (result);
					return (NULL);
				}
				(result->level)++;
				if (!(list->deep))
				{
					list->deep = result;
					return (result);
				}
				else if ((list->deep->name)[list->level] > name[result->level])
				{
					result->next = list->deep;
					list->deep = result;
					return (result);
				}
				list = list->deep;
			}
		}
	}
	return (result);
}

int		hesh_install_key(int key, t_list_hesh *list)
{
	if (!(list))
	{
		return key;
	}
	list->key = key++;
	key = hesh_install_key(key, list->deep);
	key = hash_install_key(key, list->next);
	return (key);
}

int	hesh_get_key(char *name, t_storage *st)
{
	t_list_hesh	*list;

	if (!(list = st->table_hesh))
		return (-1);
	while (list)
	{
		if ((list->name)[list->level] < name[list->level])
		{
			list = list->next;
		}
		else if (ft_strequ(list->name, name))
		{
			return (list->key);
		}
		else if ((list->name)[list->level] == name[list->level])
		{
			list = list->deep;
		}
		else
		{
			return (-1);
		}
	}
	return (-1);
}

char	*hash_get_name(int key, t_list_hesh *list)
{
	if (!(list) || list->key > key)
		return (NULL);
	if (list->key == key)
		return (list->name);
	return (hash_get_name(key, list->deep) || hash_get_name(key, list->next));
}

void	ft_free_list_hash(t_list_hesh *list)
{
	if (list->deep)
	{
		ft_free_list_hash(list->deep);
	}
	if (list->next)
	{
		ft_free_list_hash(list->next);
	}
	free(list->name);
	free(list);
}
