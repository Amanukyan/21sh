/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <amanukya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:32:25 by amanukya          #+#    #+#             */
/*   Updated: 2016/01/26 17:05:01 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*dst_ptr;

	if (!dst || !src)
		return (NULL);
	dst_ptr = dst;
	while (*src && n > 0)
	{
		n--;
		*dst_ptr++ = *src++;
	}
	*dst_ptr = 0;
	while (n-- > 0)
		*dst_ptr++ = 0;
	return (dst);
}
