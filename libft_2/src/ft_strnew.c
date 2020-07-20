/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:08:37 by ghusk             #+#    #+#             */
/*   Updated: 2019/09/19 17:15:49 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*result;

	size++;
	if (size == 0)
		return (NULL);
	result = (char *)malloc(size);
	if (result == NULL)
		return (result);
	while (size--)
		result[size] = '\0';
	return (result);
}
