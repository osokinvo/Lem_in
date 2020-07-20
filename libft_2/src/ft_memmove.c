/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:27:38 by ghusk             #+#    #+#             */
/*   Updated: 2019/09/26 17:21:23 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*pd;
	unsigned char	*ps;

	if (dst == NULL && src == NULL)
		return (NULL);
	pd = (unsigned char *)dst;
	ps = (unsigned char *)src;
	if (pd <= ps || pd >= (ps + len))
		while (len--)
			*pd++ = *ps++;
	else
		while (len--)
			*(pd + len) = *(ps + len);
	return (dst);
}
