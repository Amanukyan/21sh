/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:15:16 by amanukya          #+#    #+#             */
/*   Updated: 2016/04/21 16:15:17 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../21sh.h"

static int		myoutc(int c)
{
	return(write(1, &c, 1));
}

void			ft_puts(char *res)
{
	tputs(tgetstr(res, NULL), 1, myoutc);
}

void			fmove(int x, int y)
{
	tputs(tgoto(tgetstr("cm", NULL), x, y), 1, myoutc);
}

void			fmovex(int x)
{
	tputs(tgoto(tgetstr("ch", NULL), 0, x), 1, myoutc);
}
