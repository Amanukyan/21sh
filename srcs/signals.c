/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:14:55 by amanukya          #+#    #+#             */
/*   Updated: 2016/04/21 16:14:57 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../21sh.h"

void				handle_ctrl_d(void)
{
	ft_puts("do");
	// TO DO :
	//		Function save line with static variable 
	//		to be able to free the line.
	default_terminal_mode();
	exit (0);
}

static void			sighandler(int signum)
{
	if (signum == SIGQUIT || signum == SIGKILL)
		return;
	else if (signum == SIGWINCH)
		resize();
	// else if (signum == SIGTSTP)
	// 	handle_stop();
	// else if (signum == SIGCONT)
	// 	handle_cont();
	else if (signum == SIGINT)
		handle_ctrl_d();
	else if (signum == SIGSEGV)
	{
		
		ft_printf("Action not supported\nExiting program...\n");
		exit(0);
	}
}

void				ft_signal(void)
{
	int 			i;

	i = 1;
	while (i < 32)
	{
		signal(i, sighandler);
		i++;
	}
}
