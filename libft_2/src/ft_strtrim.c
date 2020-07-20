/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:47:35 by ghusk             #+#    #+#             */
/*   Updated: 2019/09/20 08:10:50 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	size_t	l;
	char	*str;

	if (s == NULL)
		return (NULL);
	while (*s && (*s == ' ' || *s == '\n' || *s == '\t'))
		s++;
	l = 0;
	while (s[l])
		l++;
	while (l && (s[l - 1] == ' ' || s[l - 1] == '\n' || s[l - 1] == '\t'))
		l--;
	str = (char *)malloc(l + 1);
	if (str == NULL)
		return (NULL);
	str[l] = '\0';
	while (l--)
		str[l] = s[l];
	return (str);
}
