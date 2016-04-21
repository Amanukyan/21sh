/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <amanukya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:32:25 by amanukya          #+#    #+#             */
/*   Updated: 2016/01/26 17:05:49 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_tolower(char *str)
{
	char	*lowered;
	int		i;

	lowered = ft_strnew(ft_strlen(str));
	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			lowered[i] = str[i] + 32;
		else
			lowered[i] = str[i];
		i++;
	}
	return (lowered);
}
