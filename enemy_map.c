/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:28:31 by anestor           #+#    #+#             */
/*   Updated: 2018/03/29 17:44:54 by anestor          ###   ########.fr       */
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

int		calc_position(int **map, int y, int x)
{
	int		val;

	val = map[y - 1][x - 1] + map[y][x - 1] + map[y + 1][x - 1];
	val += map[y - 1][x] + map[y][x] + map[y + 1][x];
	val += map[y - 1][x + 1] + map[y][x + 1] + map[y + 1][x + 1];
	val /= 9;
	return (val);
}

void	calc_enemy_map(int **map, t_xy size)
{
	t_xy	i;

	i.y = 1;
	while (i.y != size.y - 1)
	{
		i.x = 1;
		while (i.x != size.x - 1)
		{
			map[i.y][i.x] = calc_position(map, i.y, i.x);
			i.x++;
		}
		i.y++;
	}
}

void	calc_enemy_map_2(int **map, t_xy size)
{
	t_xy	i;

	i.y = size.y - 2;
	while (i.y != 0)
	{
		i.x = size.x - 2;
		while (i.x != 0)
		{
			map[i.y][i.x] = calc_position(map, i.y, i.x);
			i.x--;
		}
		i.y--;
	}
}

void	make_enemy_map(t_flr *data)
{
	t_xy	i;
	t_xy	size;

	size.x = data->mp_x + 2;
	size.y = data->mp_y + 2;
	data->e_map = (int **)ft_memalloc(sizeof(int *) * size.y);
	i.y = 0;
	while (i.y != size.y)
	{
		data->e_map[i.y] = (int *)ft_memalloc(sizeof(int) * size.x);
		i.x = 0;
		while (i.x != size.x)
		{
			data->e_map[i.y][i.x] = set_e_map_value(data, i.y, i.x, size);
			i.x++;
		}
		i.y++;
	}
	calc_enemy_map(data->e_map, size);
	calc_enemy_map_2(data->e_map, size);
	calc_enemy_map(data->e_map, size);
	calc_enemy_map_2(data->e_map, size);
	calc_enemy_map(data->e_map, size);
	calc_enemy_map_2(data->e_map, size);
	calc_enemy_map(data->e_map, size);
	calc_enemy_map_2(data->e_map, size);
}
