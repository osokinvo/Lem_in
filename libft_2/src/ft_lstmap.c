/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 11:54:43 by ghusk             #+#    #+#             */
/*   Updated: 2019/11/03 19:33:46 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static void	ft_dellist1(t_list **head)
{
	if (head == NULL || *head == NULL)
		return ;
	if ((*head)->next)
		ft_dellist1(&((*head)->next));
	free((*head)->content);
	free(*head);
	*head = NULL;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*head;

	if (lst == NULL || f == NULL)
		return (NULL);
	head = (*f)(lst);
	if (head == NULL)
		return (NULL);
	new = head;
	lst = lst->next;
	while (lst)
	{
		new->next = (*f)(lst);
		if (new == NULL)
		{
			ft_dellist1(&head);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (head);
}
