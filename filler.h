/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 19:33:39 by anestor           #+#    #+#             */
/*   Updated: 2018/02/09 21:21:33 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# define XMO 4
# define YMO 2

typedef struct		s_flr
{
	char			*line1;
	char			*line2;
	char			*map;
	char			*piece;
	unsigned char	map_x;
	unsigned char	map_y;
	unsigned char	p_x;
	unsigned char	p_y;
}					t_flr;

#endif
