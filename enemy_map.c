/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:28:31 by anestor           #+#    #+#             */
/*   Updated: 2018/05/21 18:21:20 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		set_e_map_value(t_flr *data, int y, int x)
{
	if (data->player == 0)
	{
		if (data->map[y][x] == (char)PLR_2)
			return (1);
		else
			return (0);
	}
	else
	{
		if (data->map[y][x] == (char)PLR_1)
			return (1);
		else
			return (0);
	}
}

void	mnhtn_enemy(t_flr *data)
{
	t_xy	i;

	i.y = 0;
	while (i.y != data->emp_h)
	{
		i.x = 0;
		while (i.x != data->emp_w)
		{
			if (data->e_map[i.y][i.x] == 1)
			{
				data->e_map[i.y][i.x] =
					(ABS((i.y - data->e_pos.y + data->rect.y))) +
					(ABS((i.x - data->e_pos.x + data->rect.x)));
			}
			i.x++;
		}
		i.y++;
	}
}

int		check_naked(t_flr *data, t_xy i)
{
	t_xy	s;
	t_xy	e;
	t_xy	n;

	s = ft_xy(i.x - 1, i.y - 1);
	e = ft_xy(i.x + 1, i.y + 1);
	(s.y < YMO) ? s.y = YMO : 0;
	(s.x < XMO) ? s.x = XMO : 0;
	(e.y >= data->mp_h + YMO) ? e.y = data->mp_h + YMO - 1 : 0;
	(e.x >= data->mp_w + XMO) ? e.x = data->mp_w + XMO - 1 : 0;
	n.y = s.y;
	while (n.y <= e.y)
	{
		n.x = s.x;
		while (n.x <= e.x)
		{
			if (data->map[n.y][n.x] != (char)PLR_1 &&
					data->map[n.y][n.x] != (char)PLR_2)
				return (1);
			n.x++;
		}
		n.y++;
	}
	return (0);
}

t_xy	find_highest_pos(t_flr *data)
{
	int		highest;
	t_xy	pos;
	t_xy	i;
	char	enemy;

	pos = ft_xy(data->e_pos.x, data->e_pos.y);
	highest = 0;
	enemy = (data->player == 0) ? PLR_2 : PLR_1;
	i.y = YMO;
	while (i.y != data->mp_h + YMO)
	{
		i.x = XMO;
		while (i.x != data->mp_w + XMO)
		{
			if (data->map[i.y][i.x] == enemy)
				if (check_naked(data, i) &&
					data->e_map[FU_NORM_Y][FU_NORM_X] > highest)
				{
					highest = data->e_map[FU_NORM_Y][FU_NORM_X];
					pos = ft_xy(FU_NORM_X, FU_NORM_Y);
				}
			i.x++;
		}
		i.y++;
	}
	return (pos);
}

void	mnhtn_enemy_map(t_flr *data, t_xy place)
{
	t_xy	i;

	i.y = 0;
	while (i.y != data->emp_h)
	{
		i.x = 0;
		while (i.x != data->emp_w)
		{
			data->e_map[i.y][i.x] =
				(ABS((i.y - place.y))) +
				(ABS((i.x - place.x)));
			i.x++;
		}
		i.y++;
	}
}

void	make_enemy_map(t_flr *data)
{
	t_xy	i;
	t_xy	size;

	data->emp_w = data->mp_w + data->rect.x;
	data->emp_h = data->mp_h + data->rect.y;
	size = ft_xy(data->emp_w, data->emp_h);
	data->e_map = ft_make_matrix(size.y, size.x);
	i.y = data->rect.y;
	while (i.y != data->emp_h)
	{
		i.x = data->rect.x;
		while (i.x != data->emp_w)
		{
			data->e_map[i.y][i.x] = set_e_map_value(data,
				i.y - data->rect.y + YMO, i.x - data->rect.x + XMO);
			i.x++;
		}
		i.y++;
	}
	mnhtn_enemy(data);
	i = find_highest_pos(data);
	mnhtn_enemy_map(data, i);
}

void	calc_closest(t_xy place, t_xy offset, t_flr *data, int *len)
{
	t_xy	i;
	char	enemy;
	int		length;

	enemy = (data->player == 0) ? PLR_2 : PLR_1;
	i.y = YMO;
	while (i.y != data->mp_h + YMO)
	{
		i.x = XMO;
		while (i.x != data->mp_w + XMO)
		{
			if (data->map[i.y][i.x] == enemy)
			{
				length =
					(ABS((i.y - YMO - (place.y + offset.y - data->rect.y)))) +
					(ABS((i.x - XMO - (place.x + offset.x - data->rect.x))));
				if (length <= *len)  /// <
					*len = length;
			}
			i.x++;
		}
		i.y++;
	}
}

int		check_closest(t_xy place, t_flr *data)
{
	t_xy	i;
	int		len;

	len = INT_MAX;
	i.y = data->rect.y;
	while (i.y != data->rect.y + data->rect.h)
	{
		i.x = data->rect.x;
		while (i.x != data->rect.x + data->rect.w)
		{
			if (data->piece[i.y][i.x] == '*')
				calc_closest(place, i, data, &len);
			i.x++;
		}
		i.y++;
	}
	return (len);
}

void	update_enemy_map(t_flr *data)
{
	t_xy	i;

	i.y = -data->rect.y;
	while (i.y != data->mp_h)
	{
		i.x = -data->rect.x;
		while (i.x != data->mp_w)
		{
			if (check_coord(data, i.x, i.y))
				if (check_closest(i, data) < 4)
					data->e_map[i.y + data->rect.y][i.x + data->rect.x] = 0;
			i.x++;
		}
		i.y++;
	}
}
