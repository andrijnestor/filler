/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 11:49:39 by anestor           #+#    #+#             */
/*   Updated: 2018/05/22 18:55:25 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	button_textures_init_1(t_data *d)
{
	d->btn[0].tex_on = sdl_texture_from_file("tex/0_1.png", d->sdl.renderer);
	d->btn[0].tex_off = sdl_texture_from_file("tex/0_0.png", d->sdl.renderer);
	d->btn[1].tex_on = sdl_texture_from_file("tex/1_1.png", d->sdl.renderer);
	d->btn[1].tex_off = sdl_texture_from_file("tex/1_0.png", d->sdl.renderer);
	d->btn[2].tex_on = sdl_texture_from_file("tex/2_1.png", d->sdl.renderer);
	d->btn[2].tex_off = sdl_texture_from_file("tex/2_0.png", d->sdl.renderer);
	d->btn[3].tex_on = sdl_texture_from_file("tex/3_1.png", d->sdl.renderer);
	d->btn[3].tex_off = sdl_texture_from_file("tex/3_0.png", d->sdl.renderer);
	d->btn[4].tex_on = sdl_texture_from_file("tex/4_1.png", d->sdl.renderer);
	d->btn[4].tex_off = sdl_texture_from_file("tex/4_0.png", d->sdl.renderer);
	d->btn[5].tex_on = sdl_texture_from_file("tex/5_1.png", d->sdl.renderer);
	d->btn[5].tex_off = sdl_texture_from_file("tex/5_0.png", d->sdl.renderer);
	d->btn[6].tex_on = sdl_texture_from_file("tex/6_1.png", d->sdl.renderer);
	d->btn[6].tex_off = sdl_texture_from_file("tex/6_0.png", d->sdl.renderer);
	d->btn[7].tex_on = sdl_texture_from_file("tex/7_1.png", d->sdl.renderer);
	d->btn[7].tex_off = sdl_texture_from_file("tex/7_0.png", d->sdl.renderer);
	d->btn[8].tex_on = sdl_texture_from_file("tex/8_1.png", d->sdl.renderer);
	d->btn[8].tex_off = sdl_texture_from_file("tex/8_0.png", d->sdl.renderer);
	d->btn[9].tex_on = sdl_texture_from_file("tex/9_1.png", d->sdl.renderer);
	d->btn[9].tex_off = sdl_texture_from_file("tex/9_0.png", d->sdl.renderer);
	d->btn[10].tex_on = sdl_texture_from_file("tex/10_1.png", d->sdl.renderer);
	d->btn[10].tex_off = sdl_texture_from_file("tex/10_0.png", d->sdl.renderer);
	d->btn[11].tex_on = sdl_texture_from_file("tex/11_1.png", d->sdl.renderer);
	d->btn[11].tex_off = sdl_texture_from_file("tex/11_0.png", d->sdl.renderer);
}

static void	button_textures_init_2(t_data *d)
{
	d->btn[12].tex_on = sdl_texture_from_file("tex/12_1.png", d->sdl.renderer);
	d->btn[12].tex_off = sdl_texture_from_file("tex/12_0.png", d->sdl.renderer);
	d->btn[13].tex_on = sdl_texture_from_file("tex/13_1.png", d->sdl.renderer);
	d->btn[13].tex_off = sdl_texture_from_file("tex/13_0.png", d->sdl.renderer);
	d->btn[14].tex_on = sdl_texture_from_file("tex/14_1.png", d->sdl.renderer);
	d->btn[14].tex_off = sdl_texture_from_file("tex/14_0.png", d->sdl.renderer);
	d->btn[15].tex_on = sdl_texture_from_file("tex/15_1.png", d->sdl.renderer);
	d->btn[15].tex_off = sdl_texture_from_file("tex/15_0.png", d->sdl.renderer);
	d->btn[16].tex_on = sdl_texture_from_file("tex/16_1.png", d->sdl.renderer);
	d->btn[16].tex_off = sdl_texture_from_file("tex/16_0.png", d->sdl.renderer);
	d->btn[17].tex_on = sdl_texture_from_file("tex/17_1.png", d->sdl.renderer);
	d->btn[17].tex_off = sdl_texture_from_file("tex/17_0.png", d->sdl.renderer);
}

static void	button_rect_params(t_data *d)
{
	int		i;
	int		x;
	int		y;
	int		step;

	i = 0;
	x = BTN_X_S1;
	y = 0;
	step = 0;
	while (i != BTNS)
	{
		d->btn[i].rect = sdl_rect(x, BTN_Y_S + y * BTN_STEP + step,
									BTN_H, BTN_W);
		i++;
		y++;
		(i == 7) ? step = 20 : 0;
		(i == 17) ? step = 160 : 0;
		if (i == 10)
		{
			x = BTN_X_S2;
			y = 0;
			step = 0;
		}
	}
}

void		button_render_copy(t_data *d)
{
	int		i;

	i = 0;
	while (i != BTNS)
	{
		if (d->btn[i].active == 1)
		{
			SDL_RenderCopy(d->sdl.renderer, d->btn[i].tex_on, NULL,
										&d->btn[i].rect);
		}
		else
		{
			SDL_RenderCopy(d->sdl.renderer, d->btn[i].tex_off, NULL,
										&d->btn[i].rect);
		}
		i++;
	}
}

void		buttons_init(t_data *d)
{
	button_textures_init_1(d);
	button_textures_init_2(d);
	button_rect_params(d);
}
