/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 15:42:32 by ghusk             #+#    #+#             */
/*   Updated: 2019/10/09 18:29:30 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	len;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		len = 0;
		while (needle[len] && haystack[len] == needle[len])
			len++;
		if (needle[len] == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return ((char *)0);
}
