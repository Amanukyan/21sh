/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <amanukya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:32:25 by amanukya          #+#    #+#             */
/*   Updated: 2016/01/26 17:02:18 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*dst_pt;
	unsigned char	*src_pt;

	if (!dst || !src)
		return (NULL);
	ch = (unsigned char)c;
	dst_pt = (unsigned char*)dst;
	src_pt = (unsigned char*)src;
	while (n-- > 0)
	{
		*dst_pt = *src_pt;
		if (*dst_pt++ == ch)
			return (dst_pt);
		src_pt++;
	}
	return (NULL);
}
