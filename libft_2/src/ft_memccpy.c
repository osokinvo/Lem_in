/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:23:11 by ghusk             #+#    #+#             */
/*   Updated: 2019/09/26 17:52:35 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*td;
	unsigned char	*tr;

	td = (unsigned char *)dst;
	tr = (unsigned char *)src;
	while (c < 0)
		c = c + 256;
	c = c % 256;
	while (n--)
	{
		*td++ = *tr;
		if (*tr++ == c)
			return (td);
	}
	return (NULL);
}
