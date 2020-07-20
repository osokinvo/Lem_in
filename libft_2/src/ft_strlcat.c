/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:41:37 by ghusk             #+#    #+#             */
/*   Updated: 2019/10/03 18:24:51 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (dst == NULL && src == NULL)
		return (0);
	len1 = 0;
	while (dst[len1])
		len1++;
	len2 = 0;
	while (src[len2] && size && (len1 + len2) < size - 1)
	{
		dst[len1 + len2] = src[len2];
		len2++;
	}
	i = 0;
	while (len1 + len2 + i < size)
		dst[len1 + len2 + i++] = '\0';
	while (src[len2])
		len2++;
	if (size <= len1)
		return (len2 + size);
	return (len1 + len2);
}
