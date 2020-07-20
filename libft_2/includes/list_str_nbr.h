/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_str_nbr.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <ghusk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 18:59:01 by ghusk             #+#    #+#             */
/*   Updated: 2020/02/15 13:41:36 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_STR_NBR_H
# define LIST_STR_NBR_H

typedef struct	s_list_str_nbr
{
	char					*string;
	int						number;
	struct s_list_str_nbr	*next;
}				t_list_str_nbr;

# define BUFF_SIZE 8

t_list_str_nbr	*ft_create_list_str_nbr(int n);

#endif
