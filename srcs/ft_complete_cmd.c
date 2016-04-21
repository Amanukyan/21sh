/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complete_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:09:17 by amanukya          #+#    #+#             */
/*   Updated: 2016/04/21 16:09:19 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../21sh.h"

char	*ft_complete_cmd(char special, char *separator)
{
	char		*line;
	char		*full_cmd;

	line = NULL;
	full_cmd = ft_strjoin(main_line.cmd, separator);
	while (!line || !ft_strchr(line, special))
	{
		ft_putstr(">");
		get_next_line(0, &line);
		full_cmd = ft_strjoin(full_cmd, line);
		full_cmd = ft_strjoin(full_cmd, separator);
	}
	return (full_cmd);
}
