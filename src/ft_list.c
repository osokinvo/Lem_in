/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 12:53:23 by val               #+#    #+#             */
/*   Updated: 2020/07/24 12:59:51 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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