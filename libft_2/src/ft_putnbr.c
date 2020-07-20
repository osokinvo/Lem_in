/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:46:25 by ghusk             #+#    #+#             */
/*   Updated: 2019/09/21 18:53:17 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void		ft_putnbr(int n)
{
	char	nbr;

	if (n < 0)
		write(1, "-", 1);
	if (n / 10 != 0)
		ft_putnbr(ft_abs(n / 10));
	nbr = '0' + ft_abs(n % 10);
	write(1, &nbr, 1);
}
