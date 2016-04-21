/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:14:44 by amanukya          #+#    #+#             */
/*   Updated: 2016/04/21 16:14:46 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../21sh.h"

int 		prompt(t_env *env_list, char *current_line)
{
	char	*user;
	char	*pwd;
	char	*home_dir;
	int 	size;

	size = 0;
	home_dir = search_in_env("HOME", env_list);
	user = search_in_env("USER", env_list);
	pwd = search_in_env("PWD", env_list);
	if (user && pwd && home_dir)
	{
		pwd = ft_str_replace(pwd, home_dir, "~");
		ft_putcolor(user, "cyan");
		ft_putstr(" in ");
		ft_putcolor(pwd, "light yellow");
		ft_putchar('\n');
	}
	ft_putstr(PROMPT);
	if (current_line)
		ft_putstr(current_line);
	if (env_list != NULL)
		size = ft_strlen(user) + ft_strlen(pwd) + 4;
	return (size); 
}
