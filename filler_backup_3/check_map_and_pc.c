/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_and_pc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:47:14 by anestor           #+#    #+#             */
/*   Updated: 2018/03/30 18:47:22 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_map_x(t_flr *data, int x, char plr)
{
	int		y;

	y = 0;
	while (y != data->mp_h)
	{
		if (data->map[y + YMO][x + XMO] == plr)
			return (1);
		y++;
	}
	return (0);
}

int		check_map_y(t_flr *data, int y, char plr)
{
	int		x;

	x = 0;
	while (x != data->mp_w)
	{
		if (data->map[y + YMO][x + XMO] == plr)
			return (1);
		x++;
	}
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
