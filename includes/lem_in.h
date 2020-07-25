/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 05:23:43 by val               #+#    #+#             */
/*   Updated: 2020/07/25 22:07:54 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "ft_list.h"

# define SIZE_FILE 1024

int	ft_error(t_storage *st);

int	ft_data_processing(t_storage *st);

int	ft_recurse(t_room *head_culc, t_list_path *paths, t_storage *st);

t_path *ft_find_path(t_room *head_culc, t_storage *st, int uncrosing);

void	ft_del_crossing(t_room *head_culc, t_list_path *paths, t_path *path);

#endif

/*
Уязвимости
Ссылки комнат на самих себя
Старт не соединён с финишем
Несколько стартов или финишей
Существует только старт и финиш
*/