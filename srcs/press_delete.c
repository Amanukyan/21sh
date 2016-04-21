/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:13:52 by amanukya          #+#    #+#             */
/*   Updated: 2016/04/21 16:13:54 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../21sh.h"

static void		go_end_line_before(void)
{
	ft_puts("up");
	fmovex(main_line.win_col);
}

static void		delete_char(int i)
{
	int			len;

	len = ft_strlen(main_line.cmd);
	main_line.cmd = ft_strndup(main_line.cmd, len - 1);
	ft_puts("dm");
	if (i == 0)
		ft_puts("le");
	ft_puts("dc");
	ft_puts("ed");
}

static void		print_line_1(void)
{
	int			i;

	i = main_line.curs_y;
	ft_puts("sc");
	while (i > 0)
	{
		ft_puts("up");
		i--;
	}
	ft_puts("cr");
	ft_puts("cd");
	prompt(NULL, main_line.cmd);
	ft_puts("rc");
	ft_puts("le");
}

static void		edit_del_char(void)
{
	char		*new;
	int			pos;
	int			j;
	int			i;
	int			len;
	
	i = 0;
	len = ft_strlen(main_line.cmd);
	pos = main_line.curs_x - 1;
	new = ft_strnew(len + 1);
	while (i < pos)
	{
		new[i] = main_line.cmd[i];
		i++;
	}
	j = i + 1;
	while (j < len)
	{
		new[i] = main_line.cmd[j];
		i++;
		j++;
	}
	new[i] = '\0';
	free(main_line.cmd);
	main_line.cmd = ft_strdup(new);
}

void			press_delete(void)
{
	int			i;

	i = 0;
	if (main_line.size_x > 0 && main_line.curs_x > 0)
	{
		if (main_line.curs_x_win == 0 && (i = 1))
		{
			main_line.curs_y--;
			main_line.curs_x_win = main_line.win_col - 1;
		}
		else
			main_line.curs_x_win--;
		if (main_line.curs_x == main_line.size_x)
		{
			(i == 1) ? go_end_line_before() : 1;
			delete_char(i);
		}
		else
		{
			edit_del_char();
			print_line_1();
			// (i == 1) ? go_end_line_before() : 1;
		}
		main_line.curs_x--;
		main_line.size_x--;
	}
}
