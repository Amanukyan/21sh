/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:13:16 by amanukya          #+#    #+#             */
/*   Updated: 2016/04/21 16:13:18 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../21sh.h"

void		free_line(t_line *line)
{
	ft_strdel(&line->cmd);
	ft_memdel((void **)line);
}

int			chars_by_line(int line_nb)
{
	int		total_size;
	int		res;

	if (line_nb < 1 || line_nb > main_line.size_y)
		return (0);
	total_size = ft_strlen(main_line.cmd) + main_line.prompt;
	res = total_size - (line_nb - 1) * main_line.win_col;
	if (line_nb == 1)
		return (res - main_line.prompt);
	else
		return (res);
}

void		init_new_line(void)
{
	free(main_line.cmd);
	main_line.cmd = ft_strnew(1);
	// main_line.prompt_y = main_line.prompt_y + main_line.size_prompt + main_line.size_y + 1;
	main_line.curs_x = 0;
	main_line.curs_x_win = main_line.prompt;
	main_line.curs_y = 0;
	main_line.size_x = 0;
	main_line.size_y = 1;
	get_window_size();
	// fmove(main_line.curs_x_win, main_line.curs_y_win);
}

void		init_line(int size_prompt)
{
	if (main_line.cmd)
		free(main_line.cmd);
	main_line.cmd = NULL;
	main_line.cmd = ft_strnew(1);
	main_line.clipboard = ft_strnew(1);
	main_line.prompt = ft_strlen(PROMPT);
	get_window_size();
	main_line.size_prompt = (size_prompt / main_line.win_col) + 1;
	// main_line.prompt_y = 0;
	main_line.curs_x = 0;
	main_line.curs_x_win = main_line.prompt;
	main_line.curs_y = 0;
	main_line.size_x = 0;
	main_line.size_y = 1;
}
