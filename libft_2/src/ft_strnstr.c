/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:01:13 by ghusk             #+#    #+#             */
/*   Updated: 2019/09/21 18:32:35 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len1;
	size_t	len2;

	if (*needle == '\0')
		return ((char *)haystack);
	len1 = 0;
	while (haystack[len1] && len1 < len)
	{
		len2 = 0;
		while (needle[len2] == haystack[len1 + len2] && len1 + len2 < len)
		{
			len2++;
			if (needle[len2] == '\0')
				return ((char *)(haystack + len1));
		}
		len1++;
	}
	return (0);
}
