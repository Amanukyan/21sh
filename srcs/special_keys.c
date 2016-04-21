/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:15:04 by amanukya          #+#    #+#             */
/*   Updated: 2016/04/21 16:15:07 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../21sh.h"
// GESTION DES TOUCHES ctrl + ...
// debut de ligne (ctrl + a): 1 0 0
// fin de ligne (ctrl + e): 5 0 0
// couper toute la ligne (ctrl + u): 21 0 0
// couper la fin de la ligne (ctrl + k): 11 0 0
// coller (ctrl + y):
// clear (ctrl + l): 12 0 0

void		go_to_start(void)
{
	int i;

	i = main_line.curs_y;
	main_line.curs_x = 0;
	main_line.curs_y = 0;
	main_line.curs_x_win = main_line.prompt;
	while (i > 0)
	{
		ft_puts("up");
		i--;
	}
	fmovex(main_line.curs_x_win);
}

void		go_to_end(void)
{
	print_line(0);
	main_line.curs_x = main_line.size_x;
	main_line.curs_x_win = (main_line.size_x + 3) % main_line.win_col;
	main_line.curs_y = (main_line.size_x + 3) / main_line.win_col;
}

// void		cut_entire_line(void)
// {
// 	free(main_line.clipboard);
// 	main_line.clipboard = ft_strdup(main_line.cmd);
// 	free(main_line.cmd);
// 	main_line.cmd = ft_strnew(1);
// 	main_line.curs_x = 0;
// 	main_line.curs_x_win = main_line.prompt;
// 	main_line.curs_y = 0;
// 	main_line.curs_y_win = main_line.prompt_y + 1;
// 	main_line.size_x = 0;
// 	main_line.size_y = 1;
// 	fmove(main_line.curs_x_win, main_line.curs_y_win);
// 	ft_puts("cd");
// }

// void		cut_end_of_line(void)
// {
// 	return;
// }

// void		paste(void)
// {
// 	size_t		i;

// 	i = 0;
// 	if (main_line.clipboard && ft_strlen(main_line.clipboard) > 0)
// 	{
// 		while (i < ft_strlen(main_line.clipboard))
// 		{
// 			edit_add_char(main_line.clipboard[i]);
// 			print_line(main_line.clipboard[i]);
// 			i++;
// 		}
// //		ft_putstr(main_line.clipboard);
// 	}
// }
