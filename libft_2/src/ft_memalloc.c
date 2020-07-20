/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:48:36 by ghusk             #+#    #+#             */
/*   Updated: 2019/09/21 17:43:21 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char *result;

	result = (unsigned char *)malloc(size);
	if (result == NULL)
		return (NULL);
	while (size--)
		result[size] = '\0';
	return (result);
}
