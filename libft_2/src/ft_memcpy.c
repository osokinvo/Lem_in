/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:27:38 by ghusk             #+#    #+#             */
/*   Updated: 2019/09/26 17:06:03 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*td;
	unsigned char	*ts;

	if (dst == NULL && src == NULL)
		return (NULL);
	td = (unsigned char *)dst;
	ts = (unsigned char *)src;
	while (n--)
		*td++ = *ts++;
	return (dst);
}
