/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_enter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:14:04 by amanukya          #+#    #+#             */
/*   Updated: 2016/04/21 16:14:06 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../21sh.h"

static int 		cmp(void)
{
	char		*str;

	str = ft_strtrim(main_line.cmd);
	if (!ft_strcmp(str, "history"))
		return (1);
	else
		return (0);
}

t_hist			*press_enter(t_env *env_list, t_hist *history)
{
	int 		i;
	int 		size;
	int 		len;

	i = 0;
	if (cmp() && history)
		i = print_history(history);
	len = main_line.size_y + 1;
	while (len-- > 0)
		ft_putchar('\n');
	if (main_line.cmd)
	{
		if (!history)
			history = init_history(history);
		else
			history = add_line_to_history(history);
		default_terminal_mode();
		ft_handle_cmdline();
		raw_terminal_mode();

	}
	size = prompt(env_list, NULL);
	init_line(size);
	return (history);
}
