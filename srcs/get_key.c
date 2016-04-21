/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:12:17 by amanukya          #+#    #+#             */
/*   Updated: 2016/04/21 16:12:19 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../21sh.h"

static int		is_arrow(char *key)
{
	if (key[0] == 27 && key[1] == 91 && key[2] >= 65 && key[2] <= 68)
		return (1);
	return (0);
}

static int		is_delete(char *key)
{
	if (key[0] == 127 || key[0] == 126 || key[0] == 8)
		return (1);
	else
		return (0);
}

static int		is_enter(char *key)
{
	if (key[0] == 10 && key[1] == 0 && key[2] == 0)
		return (1);
	else
		return (0);
}

static void		is_special_action(char *key)
{
	if (key[0] == 1 && key[1] == 0 && key[2] == 0)
		go_to_start();
	else if (key[0] == 5 && key[1] == 0 && key[2] == 0)
		go_to_end();
	// else if (key[0] == 21 && key[1] == 0 && key[2] == 0)
	// 	cut_entire_line();
	// else if (key[0] == 11 && key[1] == 0 && key[2] == 0)
	// 	cut_end_of_line();
	// else if (key[0] == 22 && key[2] == 0 && key[2] == 0)
	// 	paste();
	// else if (key[0] == 12 && key[1] == 0 && key[2] == 0)
	// 	clr_screen();
}

int				get_key(t_env *env_list)
{
	char		*key;
	t_hist		*history;
	t_hist		*tmp;

	history = NULL;
	key = ft_strnew(15);
	while (read(0, key, 15))
	{
		if (is_arrow(key))
			press_arrow(key[2], history, &tmp);
		else if (is_enter(key))
		{
			history = press_enter(env_list, history);
			tmp = history->next;
		}
		else if (is_delete(key))
			press_delete();
		else if (key[0] > 30)
			print_letter(key);
		else
			is_special_action(key);
		ft_bzero(key, 15);
	}
	return (0);
}
