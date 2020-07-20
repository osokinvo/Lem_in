/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <ghusk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 09:47:11 by ghusk             #+#    #+#             */
/*   Updated: 2020/02/15 13:46:33 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char		*ft_itoa(int n)
{
	char	*result;
	int		len;
	int		size;

	size = n;
	len = 1;
	while (size /= 10)
		len++;
	if (n < 0)
		size = 1;
	else
		size = 0;
	result = (char *)malloc((len + size + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[len + size] = '\0';
	result[0] = '-';
	while (len--)
	{
		result[len + size] = '0' + ft_abs(n % 10);
		n = n / 10;
	}
	return (result);
}
