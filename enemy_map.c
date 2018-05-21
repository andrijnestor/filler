/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:28:31 by anestor           #+#    #+#             */
/*   Updated: 2018/05/21 14:54:59 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		set_e_map_value(t_flr * data, int y, int x)
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
	int		test;

	test = 0;
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
				test++;
			n.x++;
		}
		n.y++;
	}
	if (test < 3 && test > 0)
		return (1);
	return (0);
}

t_xy	find_highest_pos(t_flr *data)
{
	int		highest;
	t_xy	pos;
	t_xy	i;
	char	enemy;

	pos = ft_xy(0, 0);
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
						data->e_map[i.y - YMO + data->rect.y][i.x - XMO + data->rect.x] > highest)  //// >=
				{
					highest = data->e_map[i.y - YMO + data->rect.y][i.x - XMO + data->rect.x];
					pos = ft_xy(i.x - XMO + data->rect.x, i.y - YMO + data->rect.y);
				}
			i.x++;
		}
		i.y++;
	}
//	if (highest < 10 && data->map[data->emp_h / 2][data->emp_w / 2] != enemy)
//	if (highest < 10)
//		pos = ft_xy(data->emp_w, data->emp_h / 2);
//	if (highest == 0)
//		pos = ft_xy(data->emp_w / 2, data->emp_h / 2);
	if (highest < 20)
		pos = ft_xy(data->e_pos.x, data->e_pos.y);
	dprintf(3, "highest %d enemy %c rect.x %d rect.y %d\n", highest, enemy, data->rect.x, data->rect.y);
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
	dprintf(3, "highest pos x %d y %d\n", i.x, i.y);
	mnhtn_enemy_map(data, i);
}

void	calc_closest(t_xy place, t_xy offset, t_flr *data)
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
				length = (ABS((i.y - (place.y + offset.y)))) +
							(ABS((i.x - (place.x + offset.x))));
				if (place.y < data->result.y && data->result.y != 0)
				{
					data->result.x = place.x;
					data->result.y = place.y;
					data->result.z = length;
					dprintf(3, "less y\n");
				}
			//	else if (length == data->result.z && place.x < data->result.x && data->result.x != 0)
			//	{
			//		data->result.x = place.x;
			//		data->result.y = place.y;
			//		data->result.z = length;
			//	}
				else if (length < data->result.z)
				{
					data->result.x = place.x;
					data->result.y = place.y;
					data->result.z = length;
					dprintf(3, "x %d y %d x1 %d y1 %d z %d\n", i.x, i.y, place.x + offset.x, place.y + offset.y, length);
				}
			}
			i.x++;
		}
		i.y++;
	}
}

void	check_closest(t_xy place, t_flr *data)
{
	t_xy	i;

	i.y = data->rect.y;
	while (i.y != data->rect.y + data->rect.h)
	{
		i.x = data->rect.x;
		while (i.x != data->rect.x + data->rect.w)
		{
			if (data->piece[i.y][i.x] == '*')
				calc_closest(place, i, data);
			i.x++;
		}
		i.y++;
	}
}
/*
void	make_res(t_flr *data)
{
	t_xy	i;

	i.y = -data->rect.y;
	data->result = ft_xyz(0, 0, INT_MAX);
	while (i.y != data->mp_h)
	{
		i.x = -data->rect.x;
		while (i.x != data->mp_w)
		{
			if (check_coord(data, i.x, i.y))
				check_closest(i, data);
//			else
//				dprintf(3, "check_coord fail\n");
			i.x++;
		}
		i.y++;
	}
	dprintf(3, "ZET = %d\n", data->result.z);
}
*/
void	make_res(t_flr *data)
{
	t_xy	i;

	i.y = data->mp_h - 1;
	data->result = ft_xyz(0, 0, INT_MAX);
	while (i.y != -data->rect.y - 1)
	{
		i.x = data->mp_w - 1;
		while (i.x != -data->rect.x - 1)
		{
			if (check_coord(data, i.x, i.y))
				check_closest(i, data);
//			else
//				dprintf(3, "check_coord fail\n");
			i.x--;
		}
		i.y--;
	}
	dprintf(3, "ZET = %d\n", data->result.z);
}
