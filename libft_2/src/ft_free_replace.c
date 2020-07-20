/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_replace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <ghusk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:58:57 by ghusk             #+#    #+#             */
/*   Updated: 2020/02/04 11:21:33 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_free_replace(char **p_place, char *new)
{
	if (!(new))
		return (EXIT_FAILURE);
	free(*p_place);
	*p_place = new;
	return (EXIT_SUCCESS);
}
