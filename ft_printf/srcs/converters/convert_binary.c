/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <amanukya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 15:40:28 by amanukya          #+#    #+#             */
/*   Updated: 2016/01/26 16:45:34 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_binary(t_tag *tag, va_list *args)
{
	uintmax_t	nbr;

	nbr = va_arg(*args, int);
	nbr = get_unsigned_length(nbr, tag);
	return (print_uint(tag, nbr, "01", "0b"));
}
