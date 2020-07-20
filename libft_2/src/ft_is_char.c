/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <ghusk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:25:07 by ghusk             #+#    #+#             */
/*   Updated: 2020/02/15 14:00:09 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

const char	*ft_is_char(const char c, const char *ar_char)
{
	if (!(ar_char))
		return (NULL);
	while (*ar_char)
	{
		if (*ar_char == c)
			return (ar_char);
		ar_char++;
	}
	return (NULL);
}

const char	*ft_reis_char(const char c, const char *ar_char)
{
	size_t	len;

	if (!(ar_char))
		return (NULL);
	len = 0;
	while (ar_char[len])
		len++;
	while (len--)
		if (ar_char[len] == c)
			return (ar_char + len);
	return (NULL);
}
