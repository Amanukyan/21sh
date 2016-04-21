/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:10:47 by amanukya          #+#    #+#             */
/*   Updated: 2016/04/21 16:10:50 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../21sh.h"

char	*ft_handle_quote(void)
{
	char	*specials;

	specials = ft_strdup("\"'");
	while (*specials)
	{
		if (ft_count_char(main_line.cmd, *specials) % 2 != 0)
			return (ft_del_char(ft_complete_cmd(*specials, "\n"), *specials));
		specials++;
	}
	return (main_line.cmd);
}
