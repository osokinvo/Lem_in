/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:53:35 by ghusk             #+#    #+#             */
/*   Updated: 2020/04/05 15:49:53 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <limits.h>

static unsigned int	g_result;
static unsigned int	g_cutoff;
static unsigned int	g_cutlim;
static unsigned int	g_num;
static int			g_any;
static const char	*g_str;

static int			ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int			ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' ||
		c == ' ')
		return (1);
	return (0);
}

static void			ft_atoi1unity(const char *nptr, char **end)
{
	g_cutoff = INT_MAX / 10;
	while (g_any && *g_str && ft_isdigit(*g_str))
	{
		g_num = *g_str - '0';
		if (g_result > g_cutoff ||
			(g_result == g_cutoff && g_num > g_cutlim))
			g_any = 0;
		else
		{
			g_result = g_result * 10 + g_num;
			g_any = 1;
		}
		g_str++;
	}
	if (end)
	{
		if (g_any < 1)
			*end = (char *)nptr;
		else
			*end = (char *)g_str;
	}
}

static int			ft_atoi1neg(const char *nptr, char **end)
{
	g_cutlim = 8;
	ft_atoi1unity(nptr, end);
	if (g_any)
		return (-g_result);
	else
		return (INT_MIN);
}

int					ft_atoi1(const char *nptr, char **end, int neg)
{
	g_str = nptr;
	g_any = -1;
	g_result = 0;
	while (ft_isspace(*g_str))
		g_str++;
	if (*g_str == '-')
	{
		g_str++;
		if (neg)
			return (ft_atoi1neg(nptr, end));
	}
	else if (*g_str == '+')
		g_str++;
	g_cutlim = 7;
	ft_atoi1unity(nptr, end);
	if (g_any)
		return (g_result);
	else
		return (INT_MAX);
}
