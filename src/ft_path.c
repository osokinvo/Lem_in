/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 06:12:21 by val               #+#    #+#             */
/*   Updated: 2020/07/25 15:14:37 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list_path	*ft_create_list_path(void)
{
	t_list_path *new;

	if (!(new = (t_list_path *)malloc(sizeof(t_list_path))))
		return (NULL);
	new->paths = NULL;
	new->count_path = 0;
	return (new);
}

void	ft_free_path(t_path *path)
{
	if (path->rooms)
		free(path->rooms);
	if (path->next)
		ft_free_path(path->next);
	free(path);
}

void	ft_feee_list_paths(t_list_path *paths)
{
	if (paths->paths)
		ft_free_path(paths->paths);
	free(paths);
}