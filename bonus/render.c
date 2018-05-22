/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 11:47:49 by anestor           #+#    #+#             */
/*   Updated: 2018/05/22 19:31:50 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	set_rect(t_data *d)
{
	t_xy	i;
	int		div;

	if (d->mp_rect.h > d->mp_rect.w)
		div = (GAME_H) / d->mp_rect.h;
	else
		div = (GAME_W) / d->mp_rect.w;
	i.y = -1;
	while (++i.y != d->mp_rect.h)
	{
		i.x = -1;
		while (++i.x != d->mp_rect.w)
		{
			d->plr_r[i.y][i.x] =
				sdl_rect(i.x * div + 50, i.y * div + 50, div, div);
		}
	}
	d->plr_rect = 1;
	d->p1 = -1;
	while (!d->btn[++d->p1].active)
		;
	d->p2 = 9;
	while (!d->btn[++d->p2].active)
		;
}

void	win_render_copy(t_data *d)
{
	SDL_Rect	rect;

	rect = sdl_rect(237, 335, (BTN_H) * 2, (BTN_W) * 2);
	if (d->win == 1)
		SDL_RenderCopy(d->sdl.renderer, d->btn[d->p1].tex_off, NULL, &rect);
	else if (d->win == 2)
		SDL_RenderCopy(d->sdl.renderer, d->btn[d->p2].tex_off, NULL, &rect);
	d->win = 0;
}

void	render(t_data *d)
{
	t_xy	i;

	SDL_RenderCopy(d->sdl.renderer, d->background, NULL, NULL);
	if (d->start && d->plr_rect == 0)
		set_rect(d);
	i.y = 0;
	while (i.y != d->mp_rect.h)
	{
		i.x = 0;
		while (i.x != d->mp_rect.w)
		{
			if (d->mp[i.y][i.x] == 'O' || d->mp[i.y][i.x] == 'o')
				SDL_RenderCopy(d->sdl.renderer, d->plr_one,
											NULL, &d->plr_r[i.y][i.x]);
			if (d->mp[i.y][i.x] == 'X' || d->mp[i.y][i.x] == 'x')
				SDL_RenderCopy(d->sdl.renderer, d->plr_two,
											NULL, &d->plr_r[i.y][i.x]);
			i.x++;
		}
		i.y++;
	}
	button_render_copy(d);
	if (d->win != 0)
		win_render_copy(d);
	SDL_RenderPresent(d->sdl.renderer);
}
