/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parentheses.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:11:04 by amanukya          #+#    #+#             */
/*   Updated: 2016/04/21 16:11:07 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../21sh.h"

char	ft_get_opposite(char special)
{
	if (special == '{')
		return ('}');
	if (special == '(')
		return (')');
	return (0);
}

char	*ft_parentheses(void)
{
	char	special;
	char	*tmp;

	special = main_line.cmd[0];
	if (ft_count_char(main_line.cmd, special) >
		ft_count_char(main_line.cmd, ft_get_opposite(special)))
	{
		tmp = ft_del_char(ft_complete_cmd(ft_get_opposite(special), ";"),
							special);
		return (ft_del_char(tmp, ft_get_opposite(special)));
	}
	return (NULL);
}
