/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <amanukya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:32:25 by amanukya          #+#    #+#             */
/*   Updated: 2016/01/26 17:02:53 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_putlight(char *color)
{
	if (!ft_strcmp(color, "LIGHT GRAY") || !ft_strcmp(color, "light gray"))
		color = "37";
	if (!ft_strcmp(color, "LIGHT RED") || !ft_strcmp(color, "light red"))
		color = "91";
	if (!ft_strcmp(color, "LIGHT GREEN") || !ft_strcmp(color, "light green"))
		color = "92";
	if (!ft_strcmp(color, "LIGHT YELLOW") || !ft_strcmp(color, "light yellow"))
		color = "93";
	if (!ft_strcmp(color, "LIGHT BLUE") || !ft_strcmp(color, "light blue"))
		color = "94";
	if (!ft_strcmp(color, "LIGHT MAGENTA")
			|| !ft_strcmp(color, "light magenta"))
		color = "95";
	if (!ft_strcmp(color, "LIGHT CYAN") || !ft_strcmp(color, "light cyan"))
		color = "96";
	if (!ft_strcmp(color, "WHITE") || !ft_strcmp(color, "white"))
		color = "97";
	return (color);
}

void		ft_putcolor(char *str, char *color)
{
	ft_putstr("\033[");
	if (!ft_strcmp(color, "BLACK") || !ft_strcmp(color, "black"))
		color = "30";
	if (!ft_strcmp(color, "RED") || !ft_strcmp(color, "red"))
		color = "31";
	if (!ft_strcmp(color, "GREEN") || !ft_strcmp(color, "green"))
		color = "32";
	if (!ft_strcmp(color, "YELLOW") || !ft_strcmp(color, "yellow"))
		color = "33";
	if (!ft_strcmp(color, "BLUE") || !ft_strcmp(color, "blue"))
		color = "34";
	if (!ft_strcmp(color, "MAGENTA") || !ft_strcmp(color, "magenta"))
		color = "35";
	if (!ft_strcmp(color, "CYAN") || !ft_strcmp(color, "cyan"))
		color = "36";
	if (!ft_strcmp(color, "DARK GRAY") || !ft_strcmp(color, "dark gray"))
		color = "90";
	if (!ft_strcmp(color, "DEFAULT") || !ft_strcmp(color, "default"))
		color = "39";
	else
		color = ft_putlight(color);
	ft_putstr(color);
	ft_putchar('m');
	ft_putstr(str);
	ft_putstr("\033[0m");
}
