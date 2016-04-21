/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 15:26:27 by amanukya          #+#    #+#             */
/*   Updated: 2016/04/21 15:26:36 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAG_STRUCT_H
# define TAG_STRUCT_H

typedef struct		s_tag
{
	char	specifier;
	char	flag_minus;
	char	flag_plus;
	char	flag_space;
	char	flag_sharp;
	char	flag_zero;
	char	has_width;
	int		width;
	char	has_precision;
	int		precision;
	char	length;
}					t_tag;

#endif
