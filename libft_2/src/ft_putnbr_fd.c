/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:46:25 by ghusk             #+#    #+#             */
/*   Updated: 2019/09/21 18:54:55 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void		ft_putnbr_fd(int n, int fd)
{
	char	nbr;

	if (n < 0)
		write(fd, "-", 1);
	if (n / 10 != 0)
		ft_putnbr_fd(ft_abs(n / 10), fd);
	nbr = '0' + ft_abs(n % 10);
	write(fd, &nbr, 1);
}
