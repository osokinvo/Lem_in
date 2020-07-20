/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:18:31 by ghusk             #+#    #+#             */
/*   Updated: 2019/09/22 13:18:00 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*result;

	len = 0;
	while (s1[len])
		len++;
	result = (char *)malloc((len + 1));
	if (result == NULL)
		return (NULL);
	len = 0;
	while (s1[len])
	{
		result[len] = s1[len];
		len++;
	}
	result[len] = '\0';
	return (result);
}
