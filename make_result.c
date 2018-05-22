/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_result.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 18:10:01 by anestor           #+#    #+#             */
/*   Updated: 2018/05/22 18:23:21 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		calc_len(t_xy place, t_xy enemy, t_flr *data)
{
	t_xy	i;
	int		len;

	len = 0;
	i.y = data->rect.y;
	while (i.y != data->rect.y + data->rect.h)
	{
		i.x = data->rect.x;
		while (i.x != data->rect.x + data->rect.w)
		{
			if (data->piece[i.y][i.x] == '*')
			{
				len +=
					((ABS((place.y + i.y - (enemy.y - YMO)))) +
					(ABS((place.x + i.x - (enemy.x - XMO)))));
			}
			i.x++;
		}
		i.y++;
	}
	return (len);
}

/*
** i == enemy on data->map
*/

void	find_enemy(t_xy place, t_flr *data)
{
	t_xy	i;
	char	enemy;
	int		len;

	enemy = (data->player == 0) ? PLR_2 : PLR_1;
	i.y = YMO;
	while (i.y != data->mp_h + YMO)
	{
		i.x = XMO;
		while (i.x != data->mp_w + XMO)
		{
			if (data->map[i.y][i.x] == enemy)
			{
				if ((len = calc_len(place, i, data)) < data->result.z)
					data->result = ft_xyz(place.x, place.y, len);
			}
			i.x++;
		}
		i.y++;
	}
}

/*
** i == place == result
*/

void	make_result(t_flr *data)
{
	t_xy	i;

	data->result = ft_xyz(0, 0, INT_MAX);
	i.y = -data->rect.y;
	while (i.y != data->mp_h)
	{
		i.x = -data->rect.x;
		while (i.x != data->mp_w)
		{
			if (check_coord(data, i.x, i.y))
				find_enemy(i, data);
			i.x++;
		}
		i.y++;
	}
}
