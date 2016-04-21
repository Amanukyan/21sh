/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_arrow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:13:38 by amanukya          #+#    #+#             */
/*   Updated: 2016/04/21 16:13:40 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../21sh.h"

static void		arrow_up(t_hist *history, t_hist **tmp)
{
	free(main_line.cmd);
	main_line.cmd = ft_strdup((*tmp)->cmd);
	main_line.curs_x = (*tmp)->size;
	main_line.curs_x_win = main_line.prompt + main_line.curs_x;
	main_line.size_x = main_line.curs_x;
	main_line.curs_y = 0;
	main_line.size_y = 1;
	ft_puts("cr");
	ft_puts("cd");
	prompt(NULL, main_line.cmd);
	if ((*tmp) == history)
		return;
	(*tmp) = (*tmp)->next;
	return;
}

static void		arrow_down(t_hist *history, t_hist **tmp)
{
	free(main_line.cmd);
	main_line.cmd = ft_strdup((*tmp)->cmd);
	main_line.curs_x = (*tmp)->size;
	main_line.curs_x_win = main_line.prompt + main_line.curs_x;
	main_line.size_x = main_line.curs_x;
	main_line.curs_y = 0;
	main_line.size_y = 1;
	ft_puts("cr");
	ft_puts("cd");
	prompt(NULL, main_line.cmd);
	if ((*tmp) == history->next)
		return;
	(*tmp) = (*tmp)->prev;
	return;
}

static void		left_arrow(void)
{
	if (main_line.size_x > 0 && main_line.curs_x > 0)
	{
		main_line.curs_x--;
		if (main_line.curs_x_win == 0)
		{
			main_line.curs_y--;
			main_line.curs_x_win = main_line.win_col - 1;
			ft_puts("up");
			fmovex(main_line.win_col - 1);
		}
		else
		{
			main_line.curs_x_win--;
			ft_puts("le");
		}
	}
}

static void		right_arrow(void)
{
	if (main_line.curs_x < main_line.size_x)
	{
		main_line.curs_x++;
		if (main_line.curs_x_win == main_line.win_col - 1)
		{
			main_line.curs_x_win = 0;
			main_line.curs_y++;
			ft_puts("do");
			ft_puts("cr");
		}
		else
		{
			main_line.curs_x_win++;
			ft_puts("nd");
		}
	}
}

void			press_arrow(char key, t_hist *history, t_hist **tmp)
{
	if (key == 66 && history)
		arrow_down(history, tmp);
	else if (key == 65 && history)
		arrow_up(history, tmp);
	else if (key == 68)
		left_arrow();
	else if (key == 67)
		right_arrow();
}
