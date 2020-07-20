/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:00:03 by ghusk             #+#    #+#             */
/*   Updated: 2019/09/26 17:24:41 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*fild;

	while (c < 0)
		c += 256;
	c = c % 256;
	fild = (unsigned char *)s;
	while (n--)
	{
		if (*fild == c)
			return (fild);
		fild++;
	}
	return (NULL);
}
