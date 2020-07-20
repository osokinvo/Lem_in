/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <ghusk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:53:35 by ghusk             #+#    #+#             */
/*   Updated: 2020/02/15 15:09:49 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <limits.h>
#include "libft.h"

static unsigned long long	g_result;
static unsigned long long	g_cutoff;
static unsigned int			g_cutlim;
static unsigned int			g_num;
static int					g_any;
static const char			*g_str;

static void			ft_base_is(unsigned int *base)
{
	if ((*base == 0 || *base == 16) &&
		*g_str == '0' && (g_str[1] == 'x' || g_str[1] == 'X'))
	{
		g_str += 2;
		*base = 16;
	}
	else if ((*base == 0 || *base == 2) &&
		*g_str == '0' && (g_str[1] == 'b' || g_str[1] == 'B'))
	{
		g_str += 2;
		*base = 2;
	}
	if (*base == 0)
	{
		if (*g_str == '0')
			*base = 8;
		else
			*base = 10;
	}
}

static int			ft_colculetenum(void)
{
	if (ft_isdigit(*g_str))
		g_num = *g_str - '0';
	else if (ft_isalphalowcase(*g_str))
		g_num = *g_str - 'a' + 10;
	else if (ft_isalphaupercase(*g_str))
		g_num = *g_str - 'A' + 10;
	else
		return (1);
	return (0);
}

static void			ft_strtolunity(const char *nptr, char **end,
unsigned int base)
{
	ft_base_is(&base);
	g_cutlim = (unsigned int)(g_cutoff % (unsigned long)base);
	g_cutoff = g_cutoff / base;
	while (*g_str && !(ft_colculetenum()) && g_num < base)
	{
		if (g_any)
		{
			if (g_result > g_cutoff ||
				(g_result == g_cutoff && g_num > g_cutlim))
				g_any = 0;
			else
			{
				g_result = g_result * base + g_num;
				g_any = 1;
			}
		}
		g_str++;
	}
	if (end)
	{
		if (g_any < 0)
			*end = (char *)nptr;
		else
			*end = (char *)g_str;
	}
}

static long long	ft_strtolneg(const char *nptr, char **end,
unsigned int base)
{
	g_str++;
	g_cutoff = -(unsigned long)LLONG_MIN;
	ft_strtolunity(nptr, end, base);
	if (g_any)
		return (-(long int)g_result);
	else
		return (LLONG_MIN);
}

long long			ft_strtoll(const char *nptr, char **end, unsigned int base)
{
	g_str = nptr;
	g_any = -1;
	g_result = 0;
	while (ft_isspace(*g_str))
		g_str++;
	if (*g_str == '-')
		return (ft_strtolneg(nptr, end, base));
	else if (*g_str == '+')
		g_str++;
	g_cutoff = LLONG_MAX;
	ft_strtolunity(nptr, end, base);
	if (g_any)
		return ((long int)g_result);
	else
		return (LLONG_MAX);
}
