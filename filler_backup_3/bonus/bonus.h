/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:26:01 by anestor           #+#    #+#             */
/*   Updated: 2018/04/01 20:12:00 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H
# include "libft.h"
# include <limits.h>
# include <stdio.h>
# include <SDL2/SDL.h>
# include <SDL2_image/SDL_image.h>
# define WIN_H 800
# define WIN_W 1200
# define GAME_H 700
# define GAME_W 700
# define WIN_POS_X 200
# define WIN_POS_Y 200
# define BTN_X_S1 817
# define BTN_X_S2 996
# define BTN_Y_S 45
# define BTN_W 175
# define BTN_H 60
# define BTN_STEP 70
# define VM_PATH "../resources/filler_vm"
# define F_MAP "-f"
# define VM_MAP0 "../resources/maps/map00"
# define VM_MAP1 "../resources/maps/map01"
# define VM_MAP2 "../resources/maps/map02"
# define PLR1 "-p1"
# define PLR2 "-p2"
# define PLR_NAME_1 "../anestor.filler"
# define PLR_NAME_2 "../resources/players/abanlin.filler"
# define PLR_NAME_3 "../resources/players/carli.filler"
# define PLR_NAME_4 "../resources/players/champely.filler"
# define PLR_NAME_5 "../resources/players/grati.filler"
# define PLR_NAME_6 "../resources/players/hcao.filler"
# define PLR_NAME_7 "../resources/players/superjeannot.filler"
# define BTNS 18
# define H_DPI 2

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	SDL_Event		event;
	int				activities;
	int				running;
}					t_sdl;

typedef struct		s_btn
{
	SDL_Texture		*tex_on;
	SDL_Texture		*tex_off;
	SDL_Rect		rect;
	int				active;
}					t_btn;

typedef struct		s_data
{
	t_sdl			sdl;
	int				pipefd[2];
	int				start;
	char			mp[100][100];
	SDL_Rect		mp_rect;
	SDL_Rect		plr_r[100][100];
	int				plr_rect;
	SDL_Texture		*plr_one;
	SDL_Texture		*plr_two;
	int				p1;
	int				p2;
	SDL_Texture		*background;
	t_btn			btn[BTNS];
	int				win;
}					t_data;

enum				e_btn
{
	BTN_P1_ANESTOR = 0,
	BTN_P1_ABANLIN = 1,
	BTN_P1_CHAMPLEY = 2,
	BTN_P1_HCAO = 3,
	BTN_P1_CARLI = 4,
	BTN_P1_GRATI = 5,
	BTN_P1_SUPER = 6,
	BTN_MAP1 = 7,
	BTN_MAP2 = 8,
	BTN_MAP3 = 9,
	BTN_P2_ANESTOR = 10,
	BTN_P2_ABANLIN = 11,
	BTN_P2_CHAMPLEY = 12,
	BTN_P2_HCAO = 13,
	BTN_P2_CARLI = 14,
	BTN_P2_GRATI = 15,
	BTN_P2_SUPER = 16,
	BTN_START = 17
};

int					sdl_init(t_sdl *sdl);
void				sdl_hook(t_data *d);
void				sdl_loop(t_data *d);
SDL_Texture			*sdl_texture_from_file(char *filename,
											SDL_Renderer *renderer);
SDL_Rect			sdl_rect(int x, int y, int h, int w);
void				mouse_down(int x, int y, t_data *d);
void				mouse_up(int x, int y, t_data *d);

int					return_function(char *str);
void				start_program(t_data *d);
void				read_from_pipe(t_data *d);
void				render(t_data *d);
void				read_from_pipe(t_data *d);
void				buttons_init(t_data *d);
void				button_render_copy(t_data *d);

#endif
