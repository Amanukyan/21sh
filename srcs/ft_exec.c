/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:09:28 by amanukya          #+#    #+#             */
/*   Updated: 2016/04/21 16:09:30 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../21sh.h"

void		change_fd(t_tree *node)
{
	if (node->from != -2 && node->to != -2)
	{
		if (node->to != -1)
		{
			dup2(node->to, node->from);
		}
		else
			close(node->from);
	}
}

int			ft_exec_cmd(t_tree *node, t_env *env_list)
{
	char		*path;

	if (builtin_commands(node->cmd[0], node->cmd, &env_list))
		return (1);
	if (!env_list)
		return (0);
	change_fd(node);
	if ((path = find_command(ft_tolower(node->cmd[0]), env_list)))
		execve(path, node->cmd, NULL);
	else
		ft_printf("Command not found: %s\n", node->cmd[0]);
	return (0);
}

void		ft_choose_exec(t_tree *node, t_env *env_list)
{
	if (node->token == TOKEN_CMD)
		ft_exec_cmd(node, env_list);
	else if (node->token == TOKEN_AND)
		ft_and(node, env_list);
	else if (node->token == TOKEN_OR)
		ft_or(node, env_list);
	else if (node->token == TOKEN_PIPE)
		ft_pipe(node, env_list);
	else if (node->token == TOKEN_SIMPLE_WRITE ||
			node->token == TOKEN_DOUBLE_WRITE)
		ft_write(node, env_list);
	else if (node->token == TOKEN_SIMPLE_READ)
		ft_simple_read(node, env_list);
	else if (node->token == TOKEN_DOUBLE_READ)
		ft_double_read(node, env_list);
}

int			ft_exec_tree(t_tree *node, t_env *env_list)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		ft_choose_exec(node, env_list);
		return (0);
	}
	else
	{
		waitpid(-1, &status, 0);
		return (0);
	}
}
