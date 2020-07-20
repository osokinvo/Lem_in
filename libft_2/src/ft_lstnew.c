/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 11:11:59 by ghusk             #+#    #+#             */
/*   Updated: 2019/11/03 18:49:57 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static void	ft_re_lst(void *dest, void const *src, size_t size)
{
	unsigned char	*fdst;
	unsigned char	*fsrc;

	fdst = (unsigned char *)dest;
	fsrc = (unsigned char *)src;
	while (size--)
		*fdst++ = *fsrc++;
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*new_link;

	new_link = (t_list *)malloc(sizeof(t_list));
	if (new_link == NULL)
		return (NULL);
	new_link->next = NULL;
	if (content == NULL)
	{
		new_link->content = NULL;
		new_link->content_size = 0;
	}
	else
	{
		new_link->content = (void *)malloc(content_size);
		new_link->content_size = content_size;
		if (new_link->content == NULL)
		{
			free(new_link);
			return (NULL);
		}
		else
			ft_re_lst(new_link->content, content, content_size);
	}
	return (new_link);
}
