/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:06:14 by anestor           #+#    #+#             */
/*   Updated: 2018/02/22 20:40:13 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_place(t_flr *data, int x, int y)
{
	t_xy	i;
	int		x_cnt;
	int		o_cnt;

	i.y = -1;
	o_cnt = 0;
	x_cnt = 0;
	while (++i.y != data->pc_y)
	{
		i.x = -1;
		while (++i.x != data->pc_x)
			if (data->piece[i.y][i.x] == '*')
			{
				//dprintf(2, "i.x: %d i.y: %d x: %d y: %d\n", i.x, i.y, x, y);
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
