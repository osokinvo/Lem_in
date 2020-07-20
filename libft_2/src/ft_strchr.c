/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 15:10:45 by ghusk             #+#    #+#             */
/*   Updated: 2019/10/03 16:30:04 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (c < 0)
		c += 256;
	c = c % 256;
	while (*str || c == 0)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	return ((char *)0);
}
