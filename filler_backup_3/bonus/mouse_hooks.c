/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 18:11:32 by anestor           #+#    #+#             */
/*   Updated: 2018/04/01 20:04:14 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int		xy_in_rect(int x, int y, SDL_Rect rect)
{
	x = x * H_DPI;
	y = y * H_DPI;
	if (x >= rect.x && y >= rect.y &&
			x <= rect.x + rect.w && y <= rect.y + rect.h)
		return (1);
	return (0);
}

void	set_active_btns(t_data *d, int i)
{
	int		k;

	k = 0;
	if (i >= 0 && i < 7)
		while (k != 7)
			d->btn[k++].active = 0;
	k = 7;
	if (i >= 7 && i < 10)
		while (k != 10)
			d->btn[k++].active = 0;
	k = 10;
	if (i >= 10 && i < 17)
		while (k != 17)
			d->btn[k++].active = 0;
	d->btn[i].active = 1;
}

void	mouse_down(int x, int y, t_data *d)
{
	int		i;

	i = 0;
	while (i != BTNS)
	{
		if (xy_in_rect(x, y, d->btn[i].rect))
		{
			set_active_btns(d, i);
			render(d);
		}
		i++;
	}
}

void	mouse_up(int x, int y, t_data *d)
{
	if (xy_in_rect(x, y, d->btn[BTN_START].rect) && d->btn[BTN_START].active)
	{
		d->plr_rect = 0;
		start_program(d);
		d->start = 1;
	}
	d->btn[BTN_START].active = 0;
}
