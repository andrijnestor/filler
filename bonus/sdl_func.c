/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 11:36:01 by anestor           #+#    #+#             */
/*   Updated: 2018/04/01 19:32:09 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int		sdl_init(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_EVERYTHING))
		return_function("SDL init problem");
	if (!(sdl->win = SDL_CreateWindow("FILLER", SDL_WINDOWPOS_UNDEFINED,
							SDL_WINDOWPOS_UNDEFINED, WIN_W, WIN_H,
							SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI)))
		return_function("SDL window create problem");
	if (!(sdl->renderer = SDL_CreateRenderer(sdl->win, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
		return_function("SDL renderer create problem");
	SDL_SetRenderDrawColor(sdl->renderer, 100, 100, 100, 100);
	SDL_RenderClear(sdl->renderer);
	SDL_RenderPresent(sdl->renderer);
	sdl->running = 1;
	return (1);
}

void	sdl_hook(t_data *d)
{
	while (SDL_PollEvent(&d->sdl.event) != 0)
	{
		if (d->sdl.event.type == SDL_QUIT)
			d->sdl.running = 0;
		else if (d->sdl.event.type == SDL_KEYDOWN)
		{
			if (d->sdl.event.key.keysym.sym == SDLK_ESCAPE)
			d->sdl.running = 0;
		}
		else if (d->sdl.event.type == SDL_MOUSEBUTTONDOWN)
			mouse_down(d->sdl.event.button.x, d->sdl.event.button.y, d);
		else if (d->sdl.event.type == SDL_MOUSEBUTTONUP)
			mouse_up(d->sdl.event.button.x, d->sdl.event.button.y, d);
	}
}

void	sdl_loop(t_data *d)
{
	while (d->sdl.running)
	{
		sdl_hook(d);
		if (d->start == 1)
		{
			read_from_pipe(d);
		}
		if (d->sdl.activities)
		{
			render(d);
			d->sdl.activities = 0;
		}
	}
}

SDL_Texture	*sdl_texture_from_file(char *filename, SDL_Renderer *renderer)
{
	SDL_Surface *surface;
	SDL_Texture	*tmp;

	surface = IMG_Load(filename);
	tmp = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	return (tmp);
}

SDL_Rect	sdl_rect(int x, int y, int h, int w)
{
	SDL_Rect	tmp;

	tmp.x = x * H_DPI;
	tmp.y = y * H_DPI;
	tmp.h = h * H_DPI;
	tmp.w = w * H_DPI;
	return (tmp);
}
