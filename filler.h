/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 19:33:39 by anestor           #+#    #+#             */
/*   Updated: 2018/03/31 01:26:23 by anestor          ###   ########.fr       */
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
# define ABS(x) (x < 0) ? -x : x
# define BORDER 0
# define E_VALUE 1000000
# define PLR_1 'O'
# define PLR_2 'X'
# define F_EM 1

# include <stdio.h>

typedef struct	s_xy
{
	int			x;
	int			y;
}				t_xy;

typedef struct	s_xyz
{
	int			x;
	int			y;
	int			z;
}				t_xyz;

typedef struct	s_rect
{
	int			x;
	int			y;
	int			w;
	int			h;
}				t_rect;

typedef struct	s_mtx
{
	char		*ar;
	char		**mx;
	int			w;
	int			h;
}				t_mtx;

typedef struct	s_flr
{
	int			player;
	char		*mp;
	int			mp_w;
	int			mp_h;
	char		**map;
	int			**e_map_1;
	int			**e_map_2;
	int			emp_w;
	int			emp_h;
	char		*pc;
	int			pc_w;
	int			pc_h;
	char		**piece;
	t_rect		rect;
	t_xyz		result;
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
int				check_map_x(t_flr *data, int x, char plr);
int				check_map_y(t_flr *data, int y, char plr);
int				check_pc_w(t_flr *data, int x);
int				check_pc_h(t_flr *data, int y);

/*
** etc
*/

void			make_enemy_map(t_flr * data);

#endif
