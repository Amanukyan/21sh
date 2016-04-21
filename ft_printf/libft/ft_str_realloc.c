/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_realloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <amanukya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 15:44:28 by amanukya          #+#    #+#             */
/*   Updated: 2016/02/10 15:44:37 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_realloc(char *old, size_t size)
{
	char	*new;

	new = ft_strnew(size);
	ft_memcpy(new, old, ft_strlen(old));
	ft_memdel((void **)&old);
	return (new);
}
