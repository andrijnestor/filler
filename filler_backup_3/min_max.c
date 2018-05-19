/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:14:05 by anestor           #+#    #+#             */
/*   Updated: 2018/03/29 16:28:22 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_xy	find_min(t_flr *data, char plr)
{
	t_xy	i;
	t_xy	min;

	min.y = data->mp_y;
	min.x = data->mp_x;
	i.y = 0;
	while (i.y != data->mp_y)
	{
		i.x = 0;
		while (i.x != data->mp_x)
		{
			if (data->map[i.y + YMO][i.x + XMO] == plr)
			{
				if (i.y <= min.y)
					min.y = i.y;
				if (i.x <= min.x)
					min.x = i.x;
			}
			i.x++;
		}
		i.y++;
	}
	return (min);
}

t_xy	find_max(t_flr *data, char plr)
{
	t_xy	i;
	t_xy	max;

	max.y = 0;
	max.x = 0;
	i.y = 0;
	while (i.y != data->mp_y)
	{
		i.x = 0;
		while (i.x != data->mp_x)
		{
			if (data->map[i.y + YMO][i.x + XMO] == plr)
			{
				if (i.y >= max.y)
					max.y = i.y;
				if (i.x >= max.x)
					max.x = i.x;
			}
			i.x++;
		}
		i.y++;
	}
	return (max);
}

void	min_max(t_flr *data)
{
	char	plr;
	char	eplr;

	plr = (data->player ==  0) ? 'O' : 'X';
	eplr = (data->player == 0) ? 'X' : 'O';
	data->pmin = find_min(data, plr);
	data->emin = find_min(data, eplr);
	data->pmax = find_max(data, plr);
	data->emax = find_max(data, eplr);
}
