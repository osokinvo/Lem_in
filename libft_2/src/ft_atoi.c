/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <ghusk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:53:35 by ghusk             #+#    #+#             */
/*   Updated: 2020/02/15 14:31:24 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <limits.h>
#include "libft.h"

static unsigned int	g_result;
static unsigned int	g_cutoff;
static unsigned int	g_cutlim;
static unsigned int	g_num;
static int			g_any;

static int		ft_norm_25(char c)
{
	g_any = 1;
	g_result = 0;
	g_cutoff = 214748364;
	if (c == '-')
	{
		g_cutlim = 8;
		return (1);
	}
	else
	{
		g_cutlim = 7;
		if (c == '+')
			return (1);
	}
	return (0);
}

int				ft_atoi(const char *str)
{
	while (ft_isspace(*str))
		str++;
	if (ft_norm_25(*str))
		str++;
	while (*str && ft_isdigit(*str) && g_any)
	{
		g_num = *str - '0';
		if (g_result > g_cutoff ||
			(g_result == g_cutoff && g_num > g_cutlim))
			g_any = 0;
		else
			g_result = g_result * 10 + g_num;
		str++;
	}
	if (g_any)
	{
		if (g_cutlim == 8)
			g_result = -g_result;
		return (g_result);
	}
	else if (g_cutlim == 8)
		return (INT_MIN);
	return (INT_MAX);
}
