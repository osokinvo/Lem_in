/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 15:23:50 by ghusk             #+#    #+#             */
/*   Updated: 2019/09/26 18:03:33 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*str;
	size_t			len;

	str = (unsigned char *)s;
	while (c < 0)
		c += 256;
	c = c % 256;
	len = 0;
	while (str[len])
		len++;
	if (c == 0)
		return ((char *)(str + len));
	while (len-- > 0)
		if (str[len] == (unsigned char)c)
			return ((char *)(str + len));
	return ((char *)0);
}
