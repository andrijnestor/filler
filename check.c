/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:06:14 by anestor           #+#    #+#             */
/*   Updated: 2018/05/22 18:22:45 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_place(t_flr *data, int x, int y)
{
	t_xy	i;
	int		x_cnt;
	int		o_cnt;

	o_cnt = 0;
	x_cnt = 0;
	i.y = data->rect.y - 1;
	while (++i.y != data->rect.y + data->rect.h)
	{
		i.x = data->rect.x - 1;
		while (++i.x != data->rect.x + data->rect.w)
			if (data->piece[i.y][i.x] == '*')
			{
				if (data->map[i.y + y + YMO][i.x + x + XMO] == 'X')
					x_cnt++;
				else if (data->map[i.y + y + YMO][i.x + x + XMO] == 'O')
					o_cnt++;
			}
	}
	if (data->player == 0 && o_cnt == 1 && x_cnt == 0)
		return (1);
	if (data->player == 1 && x_cnt == 1 && o_cnt == 0)
		return (1);
	return (0);
}

int		check_coord(t_flr *data, int x, int y)
{
	t_rect	r;
	t_xy	map;

	r = data->rect;
	map.x = data->mp_w;
	map.y = data->mp_h;
	if (x >= -r.x && x <= map.x - r.w - r.x &&
		y >= -r.y && y <= map.y - r.h - r.y)
		if (check_place(data, x, y))
			return (1);
	return (0);
}

int		check_pc_w(t_flr *data, int x)
{
	int		y;

	y = 0;
	while (y != data->pc_h)
	{
		if (data->piece[y][x] != '.')
			return (1);
		y++;
	}
	return (0);
}

int		check_pc_h(t_flr *data, int y)
{
	int		x;

	x = 0;
	while (x != data->pc_w)
	{
		if (data->piece[y][x] != '.')
			return (1);
		x++;
	}
	return (0);
}
