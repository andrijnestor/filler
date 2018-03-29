/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:06:14 by anestor           #+#    #+#             */
/*   Updated: 2018/03/29 20:10:17 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
/*
int		check_place(t_flr *data, int x, int y)
{
	t_xy	i;
	int		x_cnt;
	int		o_cnt;

	i.y = data->pre.y;
	o_cnt = 0;
	x_cnt = 0;
	while (i.y != data->pc_y - data->post.y)
	{
		i.x = data->pre.x;
		while (i.x != data->pc_x - data->post.x)
		{
			if (data->piece[i.y][i.x] == '*')
			{
			//	dprintf(2, "i.x: %d i.y: %d x: %d y: %d\n", i.x, i.y, x, y);
				if (data->map[i.y + y + YMO][i.x + x + XMO] == 'X')
					x_cnt++;
				else if (data->map[i.y + y + YMO][i.x + x + XMO] == 'O')
					o_cnt++;
			}
			i.x++;
		}
		i.y++;
	}
	if (data->player == 0 && o_cnt == 1 && x_cnt == 0)
			return (1);
	if (data->player == 1 && x_cnt == 1 && o_cnt == 0)
			return (1);
	return (0);
}

int		check_coord(t_flr *data, int x, int y)
{
	if (x >= -data->pre.x && x <= data->mp_x - data->pc_x - data->post.x &&
		y >= -data->pre.y && y <= data->mp_y - data->pc_y - data->post.y)
		if (check_place(data, x, y))
			return (1);
	return (0);
}
*/
int		check_place(t_flr *data, int x, int y)
{
	t_xy	i;
	int		x_cnt;
	int		o_cnt;
	t_rect	r;

	r.x = data->rect.x;
	r.y = data->rect.y;
	r.h = data->rect.h;
	r.w = data->rect.w;
	i.y = r.y; 
	o_cnt = 0;
	x_cnt = 0;
	while (i.y != r.y + r.h)
	{
		i.x = r.x;
		while (i.x != r.x + r.w)
		{
			if (data->piece[i.y][i.x] == '*')
			{
		//		if (i.y + y + YMO < data->mp_y && i.x + x + XMO < data->mp_x)
		//		{
					if (data->map[i.y + y + YMO][i.x + x + XMO] == 'X')
						x_cnt++;
					else if (data->map[i.y + y + YMO][i.x + x + XMO] == 'O')
						o_cnt++;
		//		}
			}
			i.x++;
		}
		i.y++;
	}
	if (data->player == 0 && o_cnt == 1 && x_cnt == 0)
			return (1);
	if (data->player == 1 && x_cnt == 1 && o_cnt == 0)
			return (1);
	return (0);
}

int		check_coord(t_flr *data, int x, int y)
{
	if (x >= 0 && x < data->mp_x - data->rect.h - data->rect.x - 1 && //dont -1
		y >= 0 && y < data->mp_y - data->rect.w - data->rect.y - 1)
		if (check_place(data, x, y))
			return (1);
	return (0);
}

/*
int		check_coord(t_flr *data, int x, int y)
{
	t_xy	i;

	i.y = 0;
	while (i.y != data->pc_y)
	{
		i.x = 0;
		while (i.x != data->pc_x)
		{
			if (data->piece[i.y][i.x] == '*')
				if (x - i.x >= 0 && x - i.x <= data->mp_x - data->pc_x &&
					y - i.y >= 0 && y - i.y <= data->mp_y - data->pc_y)
					if (check_place(data, x - i.x, y - i.y) == 1)
					{
						dprintf(1, "%d %d\n", y - i.y, x - i.x); //
						return (1);
					}
			i.x++;
		}
		i.y++;
	}
	return (0);
}
*/
/*
int		check_coord(t_flr *data, int x, int y)
{
	t_xy	i;

	i.y = data->pc_y - 1;
	while (i.y != -1)
	{
		i.x = data->pc_x - 1;
		while (i.x != -1)
		{
			if (data->piece[i.y][i.x] == '*')
				if (x - i.x >= 0 && x - i.x <= data->mp_x - data->pc_x &&
					y - i.y >= 0 && y - i.y <= data->mp_y - data->pc_y)
					if (check_place(data, x - i.x, y - i.y) == 1)
					{
						dprintf(1, "%d %d\n", y - i.y, x - i.x); //
						return (1);
					}
			i.x--;
		}
		i.y--;
	}
	return (0);
}
*/
