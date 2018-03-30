/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:28:31 by anestor           #+#    #+#             */
/*   Updated: 2018/03/30 21:09:41 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		set_e_map_value(t_flr * data, int y, int x, t_xy size)
{
	if (x == 0 || y == 0)
		return (BORDER);
	else if (y == size.y - 1 || x == size.x - 1)
		return (BORDER);
	else
	{
		if (data->player == 0)
		{
			if (data->map[y][x + 2] == PLR_2)
				return (E_VALUE);
			else
				return (0);
		}
		else
		{
			if (data->map[y][x + 2] == PLR_1)
				return (E_VALUE);
			else
				return (0);
		}
	}
}

int		calc_position_1(int **map, int y, int x)
{
	int		val;

	val = map[y - 1][x - 1] + map[y][x - 1] + map[y + 1][x - 1];
	val += map[y - 1][x] + map[y][x] + map[y + 1][x];
	val += map[y - 1][x + 1] + map[y][x + 1] + map[y + 1][x + 1];
	val /= 9;
	return (val);
}

int		calc_position_2(int **map, int y, int x)
{
	int		val;
	int		min;

	val = 0;
	min = 0;
	min = map[y - 1][x - 1];
	if (min > 0)
		val = min - F_EM;
	min = map[y][x - 1];
	if (min > 0 && min > val)
		val = min - F_EM;
	min = map[y + 1][x - 1];
	if (min > 0 && min > val)
		val = min - F_EM;
	min = map[y - 1][x];
	if (min > 0 && min > val)
		val = min - F_EM;
	min = map[y][x];
	if (min > 0 && min > val)
		val = min - F_EM;
	min = map[y + 1][x];
	if (min > 0 && min > val)
		val = min - F_EM;
	min = map[y - 1][x + 1];
	if (min > 0 && min > val)
		val = min - F_EM;
	min = map[y][x + 1];
	if (min > 0 && min > val)
		val = min - F_EM;
	min = map[y + 1][x + 1];
	if (min > 0 && min > val)
		val = min - F_EM;
	return (val);
}

void	calc_enemy_map_1(int **map, t_xy size)
{
	t_xy	i;

	i.y = 1;
	while (i.y != size.y - 1)
	{
		i.x = 1;
		while (i.x != size.x - 1)
		{
			map[i.y][i.x] = calc_position_1(map, i.y, i.x);
			i.x++;
		}
		i.y++;
	}
}

void	calc_enemy_map_1_2(int **map, t_xy size)
{
	t_xy	i;

	i.y = size.y - 2;
	while (i.y != 0)
	{
		i.x = size.x - 2;
		while (i.x != 0)
		{
			map[i.y][i.x] = calc_position_1(map, i.y, i.x);
			i.x--;
		}
		i.y--;
	}
}

void	calc_enemy_map_2(int **map, t_xy size)
{
	t_xy	i;

	i.y = 1;
	while (i.y != size.y - 1)
	{
		i.x = 1;
		while (i.x != size.x - 1)
		{
			map[i.y][i.x] = calc_position_2(map, i.y, i.x);
			i.x++;
		}
		i.y++;
	}
}

void	calc_enemy_map_2_2(int **map, t_xy size)
{
	t_xy	i;

	i.y = size.y - 2;
	while (i.y != 0)
	{
		i.x = size.x - 2;
		while (i.x != 0)
		{
			map[i.y][i.x] = calc_position_2(map, i.y, i.x);
			i.x--;
		}
		i.y--;
	}
}

void	make_enemy_map(t_flr *data)
{
	t_xy	i;
	t_xy	size;

	data->emp_w = data->mp_w + 2 + data->pc_w - data->rect.w;
	data->emp_h = data->mp_h + 2 + data->pc_h - data->rect.h;
	size.x = data->emp_w;
	size.y = data->emp_h;
	data->e_map_1 = (int **)ft_memalloc(sizeof(int *) * size.y);
	data->e_map_2 = (int **)ft_memalloc(sizeof(int *) * size.y);
	i.y = 0;
	while (i.y != size.y)
	{
		data->e_map_1[i.y] = (int *)ft_memalloc(sizeof(int) * size.x);
		data->e_map_2[i.y] = (int *)ft_memalloc(sizeof(int) * size.x);
		i.x = 0;
		while (i.x != size.x)
		{
			if (i.x > data->rect.x && i.y > data->rect.y &&
				i.x <= data->rect.x + data->mp_w && i.y <= data->rect.y + data->mp_h)
			{
				data->e_map_1[i.y][i.x] =
					set_e_map_value(data, i.y - data->rect.y, i.x - data->rect.x, size);
				data->e_map_2[i.y][i.x] = data->e_map_1[i.y][i.x];
			}
			i.x++;
		}
		i.y++;
	}
//	for (int k = 0; k != 1; k++)
//	{
	calc_enemy_map_1(data->e_map_1, size);
	calc_enemy_map_1_2(data->e_map_1, size);
	calc_enemy_map_2(data->e_map_2, size);
	calc_enemy_map_2_2(data->e_map_2, size);
//	}
}
