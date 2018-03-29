/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_n_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 18:14:26 by anestor           #+#    #+#             */
/*   Updated: 2018/03/29 16:26:32 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_map_x(t_flr *data, int x, char plr)
{
	int		y;

	y = 0;
	while (y != data->mp_y)
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
	while (x != data->mp_x)
	{
		if (data->map[y + YMO][x + XMO] == plr)
			return (1);
		x++;
	}
	return (0);
}

int		check_pc_x(t_flr *data, int x)
{
	int		y;

	y = 0;
	while (y != data->pc_y)
	{
		if (data->piece[y][x] != '.')
			return (1);
		y++;
	}
	return (0);
}

int		check_pc_y(t_flr *data, int y)
{
	int		x;

	x = 0;
	while (x != data->pc_x)
	{
		if (data->piece[y][x] != '.')
			return (1);
		x++;
	}
	return (0);
}

void	trim_piece(t_flr *data)
{
	int		i;

	i = 0;
	while (!check_pc_y(data, i) && i < data->pc_y)
		i++;
	data->pre.y = i;
	i = 0;
	while (!check_pc_x(data, i) && i < data->pc_x)
		i++;
	data->pre.x = i;
	i = data->pc_y - 1;
	while (!check_pc_y(data, i) && i > -1)
		i--;
	data->post.y = data->pc_y - 1 - i;
	i = data->pc_x - 1;
	while (!check_pc_x(data, i) && i > -1)
		i--;
	data->post.x = data->pc_x - 1 - i;
}
