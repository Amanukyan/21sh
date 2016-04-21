/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and_or.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:08:46 by amanukya          #+#    #+#             */
/*   Updated: 2016/04/21 16:08:50 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../21sh.h"

void		ft_and(t_tree *node, t_env *env_list)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		ft_choose_exec(node->left, env_list);
	}
	else
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) == 0)
		{
			ft_choose_exec(node->right, env_list);
		}
		else
			exit(1);
	}
}

void		ft_or(t_tree *node, t_env *env_list)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		ft_choose_exec(node->left, env_list);
	}
	else
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) != 0)
		{
			ft_choose_exec(node->right, env_list);
		}
		else
			exit(0);
	}
}
