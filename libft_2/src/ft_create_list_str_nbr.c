/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list_str_nbr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 19:05:34 by ghusk             #+#    #+#             */
/*   Updated: 2019/11/03 19:56:39 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "list_str_nbr.h"

t_list_str_nbr	*ft_create_list_str_nbr(int n)
{
	t_list_str_nbr *list;

	if (!(list = (t_list_str_nbr *)malloc(sizeof(t_list_str_nbr))))
		return (NULL);
	if (!(list->string = ft_memalloc(1)))
	{
		free(list);
		return (NULL);
	}
	list->number = n;
	list->next = NULL;
	return (list);
}
