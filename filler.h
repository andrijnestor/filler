/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 19:33:39 by anestor           #+#    #+#             */
/*   Updated: 2018/05/22 18:22:44 by anestor          ###   ########.fr       */
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

typedef struct	s_rect
{
	int			x;
	int			y;
	int			w;
	int			h;
}				t_rect;

typedef struct	s_flr
{
	int			player;
	char		*mp;
	int			mp_w;
	int			mp_h;
	char		**map;
	char		*pc;
	int			pc_w;
	int			pc_h;
	char		**piece;
	t_rect		rect;
	t_xyz		result;
}				t_flr;

/*
** readings and cleaning
*/

int				read_filler(t_flr *data);
void			clear_filler(t_flr *data);

/*
** checkings
*/

int				check_coord(t_flr *data, int x, int y);
int				check_pc_w(t_flr *data, int x);
int				check_pc_h(t_flr *data, int y);

/*
** result
*/

void			make_result(t_flr *data);

#endif
