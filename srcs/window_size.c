/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:15:27 by amanukya          #+#    #+#             */
/*   Updated: 2016/04/21 16:15:28 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../21sh.h"

/*
int			ft_check_size(t_select *params)
{	
	if (params->win_row - 2 < params->size_list
		|| params->win_col - 2 < params->col_n)
	{
		ft_puts("cl");
		ft_putendl_fd("Windows too small!", 2);
		return (0);
	}
	else
	{
		ft_puts("cl");
		print_lst(params);
	}
	return (1);
}

void		ft_resize(void)
{
	t_select		*params;
	struct winsize	win;

	params = NULL;
	params = save_term(params, 1);
	ft_puts("cl");
	ioctl(0, TIOCGWINSZ, &win);
	params->win_col = win.ws_col;
	params->win_row = win.ws_row;
	ft_check_size(params);
}

void		ft_get_col_n(t_select *params)
{
	t_lst		*tmp;
	t_lst		*base;

	base = params->list;
	tmp = base->next;
	while (tmp != base)
	{
		if (tmp->len > params->col_n)
			params->col_n = tmp->len;
		tmp = tmp->next;
	}
}
*/

void		get_window_size(void)
{
	struct winsize	win;

	ioctl(0, TIOCGWINSZ, &win);
	main_line.win_col = win.ws_col;
	main_line.win_row = win.ws_row;
}

void		clr_screen(void)
{
	if (main_line.size_x >= (0.90 * main_line.win_col))
	{
		ft_puts("ho");
		ft_puts("cd");
		prompt(NULL, main_line.cmd);
		main_line.curs_x = main_line.size_x;
		main_line.curs_x_win = (main_line.size_x + 3) % (main_line.win_col);
		main_line.curs_y = (main_line.size_x + 3) / (main_line.win_col);
		main_line.size_y = main_line.curs_y + main_line.size_prompt;
	}
}

void		resize(void)
{
	get_window_size();
	clr_screen();
}
