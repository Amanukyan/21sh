/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_null.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:03:27 by amanukya          #+#    #+#             */
/*   Updated: 2016/04/21 16:03:30 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_remove_null(char **arr, int origin_size)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	if (ft_tablen(arr) != origin_size)
	{
		while (i < origin_size + 1)
		{
			if (arr[i] == NULL)
			{
				tmp = i;
				j = i + 1;
				while (j < origin_size + 1)
				{
					arr[i] = arr[j];
					i++;
					j++;
				}
				i = tmp;
			}
			i++;
		}
	}
}
