/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:13:25 by amanukya          #+#    #+#             */
/*   Updated: 2016/04/21 16:13:26 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../21sh.h"

t_line	main_line;

t_env	*store_env_variables(char **env)
{
	t_env	*head;
	int		i;
	char	*sep;
	char	*name;
	char	*value;

	i = 0;
	head = NULL;
	while (env[i])
	{
		if (!(sep = ft_strchr(env[i], '=')))
			return (NULL);
		name = ft_strndup(env[i], sep - env[i]);
		value = ft_strdup(sep + 1);
		ft_setenv(name, value, &head);
		i++;
	}
	return (head);
}

int					main(void)
{
	char			*buf;
	extern char		**environ;
	t_env			*env_list;
	int 			size_prompt;
	
	buf = NULL;
	env_list = store_env_variables(environ);
	execute_command("clear", &env_list, environ);
	size_prompt = prompt(env_list, NULL);
	init_line(size_prompt);
	ft_signal();
	if (raw_terminal_mode() == -1)
		return (-1);
	get_key(env_list);
	default_terminal_mode();
	return (0);
}
