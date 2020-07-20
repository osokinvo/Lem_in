/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:29:02 by ghusk             #+#    #+#             */
/*   Updated: 2019/09/19 18:36:00 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	len++;
	if (s == NULL || len == 0)
		return (NULL);
	str = (char *)malloc(len--);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len--)
		str[len] = s[start + len];
	return (str);
}
