/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 15:29:34 by amanukya          #+#    #+#             */
/*   Updated: 2016/04/21 15:29:45 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_del_char(char *origin, char c)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_strnew(ft_strlen(origin) - ft_count_char(origin, c));
	while (*origin)
	{
		while (*origin == c)
			origin++;
		new[i] = *origin;
		i++;
		origin++;
	}
	return (new);
}
