/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 19:33:39 by anestor           #+#    #+#             */
/*   Updated: 2018/02/22 20:40:17 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# define XMO 4
# define YMO 1
# define NORTH(x, y, n) n * ((x >= n / 2) ? (n + 1 - x) : x) + n + 1 - y
# define SOUTH(x, y, n) n * ((x >= n / 2) ? (n + 1 - x) : x) + y
# define EAST(x, y, n) x + n * ((y >= n / 2) ? (n + 1 - y) : y)
# define WEST(x, y, n) n + 1 - x + n * ((y >= n / 2) ? (n + 1 - y) : y)
# define NE(x, y, n) x + n * (n + 1 - y)
# define SE(x, y, n) x + n * y
# define NW(x, y, n) n + 1 - x + n * (n + 1 - y)
# define SW(x, y, n) n + 1 - x + n * y

# include <stdio.h>

typedef struct	s_xy
{
	int			x;
	int			y;
	int			z;
}				t_xy;

typedef struct	s_flr
{
	int			player;
	char		*mp;
	int			mp_x;
	int			mp_y;
	char		**map;
	char		*pc;
	int			pc_x;
	int			pc_y;
	char		**piece;
}				t_flr;

/*
** readings
*/

void			set_xy(char *str, int *x, int *y);
int				read_filler(t_flr *data);
void			clear_filler(t_flr *data);

/*
** lists
*/

void			make_list(t_flr *data, t_list **list);

/*
** checkings
*/

int				check_place(t_flr *data, int x, int y);
int				check_coord(t_flr *data, int x, int y);

#endif
