/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_letter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:14:27 by amanukya          #+#    #+#             */
/*   Updated: 2016/04/21 16:14:29 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../21sh.h"

static void		go_start_next_line(void)
{
	ft_puts("do");
	ft_puts("cr");
	main_line.curs_y++;
}

void			print_line(int edit)
{
	int			i;

	i = main_line.curs_y;
	if (edit == 1)
		ft_puts("sc");
	while (i > 0)
	{
		ft_puts("up");
		i--;
	}
	ft_puts("cr");
	ft_puts("cd");
	prompt(NULL, main_line.cmd);
	if (edit == 1)
	{
		ft_puts("rc");
		ft_puts("nd");
	}
}

void		edit_add_char(char key)
{
	char		*new;
	int			pos;
	int			j;
	int			i;
	int			len;

	i = 0;
	len = ft_strlen(main_line.cmd);
	pos = main_line.curs_x;
	new = ft_strnew(len + 1);
	while (i < pos)
	{
		new[i] = main_line.cmd[i];
		i++;
	}
	new[i] = key;
	j = i + 1;
	while (i < len)
	{
		new[j] = main_line.cmd[i];
		i++;
		j++;
	}
	new[j] = '\0';
	free(main_line.cmd);
	main_line.cmd = ft_strdup(new);
}

void			print_letter(char *key)
{
	int 		i;
	
	i = 0;
	if (main_line.curs_x_win == main_line.win_col - 1 && (i = 1))
	{
		main_line.curs_x_win = 0;
		main_line.size_y++;
	}
	else
		main_line.curs_x_win++;
	if (main_line.curs_x == main_line.size_x)
	{
		ft_putstr(key);
		main_line.cmd = ft_strjoin(main_line.cmd, key);
		(i == 1) ? go_start_next_line() : 1;
	}
	else
	{
		edit_add_char(key[0]);
		print_line(1);
		(i == 1) ? go_start_next_line() : 1;
	}
	main_line.curs_x++;
	main_line.size_x++;
}
