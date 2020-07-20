/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 06:12:21 by val               #+#    #+#             */
/*   Updated: 2020/07/09 06:35:18 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list_path	*ft_create_list_path(int max_count_path)
{
	t_list_path *new;

	if (!(new = (t_list_path *)malloc(sizeof(t_list_path))))
		return (NULL);
	if (new->path = (t_path *)malloc(max_count_path * sizeof(t_path)))
	{
		free(new);
		return (NULL);
	}
	while (max_count_path-- >= 0)
	{
		((new->path)[max_count_path]).room = NULL;
		((new->path)[max_count_path]).number_rooms = 0;
	}
	new->count_path = 0;
	new->length = -1;
	return (new);
}

void		ft_free_list_path(t_list_path *list_path)
{
	if (list_path)
	{
		free(list_path->path);
		free(list_path);
	}
}