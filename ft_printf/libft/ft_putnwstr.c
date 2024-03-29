/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <amanukya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 14:25:38 by amanukya          #+#    #+#             */
/*   Updated: 2016/01/26 14:27:35 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnwstr(wchar_t *str, size_t n)
{
	if (!str)
		write(1, "(null)", 6);
	while (*str && n-- > 0)
	{
		ft_putwchar(*str);
		str++;
	}
}
