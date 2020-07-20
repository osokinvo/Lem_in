/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dellist1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:35:58 by ghusk             #+#    #+#             */
/*   Updated: 2019/11/03 19:31:06 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_dellist(t_list **head)
{
	if (head == NULL || *head == NULL)
		return ;
	if ((*head)->next)
		ft_dellist(&((*head)->next));
	free((*head)->content);
	free(*head);
	*head = NULL;
}
