/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 05:23:43 by val               #+#    #+#             */
/*   Updated: 2020/08/03 10:21:56 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include <unistd.h>
# include "ft_list.h"

# define SIZE_FILE 1024
# define DEEP_RECURSE 100000

int	ft_error(t_storage *st);

int	ft_data_processing(t_storage *st);

int	ft_recurse(t_room *head_culc, t_list_path *paths, t_storage *st, int rank);

t_path *ft_find_path(t_room *head_culc, t_storage *st, int uncrosing, int *exist);
void	ft_deffult_vertex(t_room *head_culc, int count_rooms);

void	ft_del_crossing(t_room *head_culc, t_list_path *paths, t_path *path);

int	ft_print_paths(t_path *path,t_storage *st);

#endif

/*
Уязвимости
Ссылки комнат на самих себя
Старт не соединён с финишем
Несколько стартов или финишей
Существует только старт и финиш
*/