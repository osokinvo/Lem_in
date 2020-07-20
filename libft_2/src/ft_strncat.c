/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:41:37 by ghusk             #+#    #+#             */
/*   Updated: 2019/09/26 17:57:43 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len = 0;
	while (s1[len])
		len++;
	while (*s2 && n--)
	{
		s1[len] = *s2++;
		len++;
	}
	s1[len] = '\0';
	return (s1);
}
