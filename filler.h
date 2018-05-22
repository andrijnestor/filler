/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 19:33:39 by anestor           #+#    #+#             */
/*   Updated: 2018/05/22 16:22:26 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include <limits.h>
# define XMO 4
# define YMO 1
# define ABS(x) (x < 0) ? -x : x
# define PLR_1 'O'
# define PLR_2 'X'
# define F_EM 1
# define FU_NORM_X i.x - XMO + data->rect.x
# define FU_NORM_Y i.y - YMO + data->rect.y
# include <stdio.h>

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
	int			**e_map;
	int			emp_w;
	int			emp_h;
	char		*pc;
	int			pc_w;
	int			pc_h;
	char		**piece;
	t_rect		rect;
	t_xyz		result;
	t_xyz		tmp_res;
	t_xy		e_pos;
	t_xy		a_pos;
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
//int				check_map_x(t_flr *data, int x, char plr);
//int				check_map_y(t_flr *data, int y, char plr);
int				check_pc_w(t_flr *data, int x);
int				check_pc_h(t_flr *data, int y);

/*
** etc
*/

void			make_enemy_map(t_flr * data);


void			update_enemy_map(t_flr *data);

#endif
