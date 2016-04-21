/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <amanukya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 15:43:30 by amanukya          #+#    #+#             */
/*   Updated: 2016/02/10 15:44:09 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_replace(char *origin, char *rep, char *with)
{
	char	*start;
	size_t	size_rep;
	char	*new;

	if (!(start = ft_strstr(origin, rep)))
		return (origin);
	size_rep = ft_strlen(rep);
	new = ft_strnew(ft_strlen(origin) - ft_strlen(rep) + ft_strlen(with));
	ft_strncpy(new, origin, start - origin);
	ft_strcat(new, with);
	ft_strcat(new, start + size_rep);
	return (new);
}
