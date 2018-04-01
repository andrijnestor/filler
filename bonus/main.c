/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:28:30 by anestor           #+#    #+#             */
/*   Updated: 2018/04/01 19:59:01 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int		return_function(char *str)
{
	ft_putendl(str);
	return (0);
}

void	set_program(t_data *d, char *plr1, char *plr2, char *map)
{
	(d->btn[0].active) ? plr1 = ft_strdup(PLR_NAME_1) : 0;
	(d->btn[1].active) ? plr1 = ft_strdup(PLR_NAME_2) : 0;
	(d->btn[2].active) ? plr1 = ft_strdup(PLR_NAME_3) : 0;
	(d->btn[3].active) ? plr1 = ft_strdup(PLR_NAME_4) : 0;
	(d->btn[4].active) ? plr1 = ft_strdup(PLR_NAME_5) : 0;
	(d->btn[5].active) ? plr1 = ft_strdup(PLR_NAME_6) : 0;
	(d->btn[6].active) ? plr1 = ft_strdup(PLR_NAME_7) : 0;
	(d->btn[10].active) ? plr2 = ft_strdup(PLR_NAME_1) : 0;
	(d->btn[11].active) ? plr2 = ft_strdup(PLR_NAME_2) : 0;
	(d->btn[12].active) ? plr2 = ft_strdup(PLR_NAME_3) : 0;
	(d->btn[13].active) ? plr2 = ft_strdup(PLR_NAME_4) : 0;
	(d->btn[14].active) ? plr2 = ft_strdup(PLR_NAME_5) : 0;
	(d->btn[15].active) ? plr2 = ft_strdup(PLR_NAME_6) : 0;
	(d->btn[16].active) ? plr2 = ft_strdup(PLR_NAME_7) : 0;
	(d->btn[7].active) ? map = ft_strdup(VM_MAP0) : 0;
	(d->btn[8].active) ? map = ft_strdup(VM_MAP1) : 0;
	(d->btn[9].active) ? map = ft_strdup(VM_MAP2) : 0;
	execl(VM_PATH, VM_PATH, F_MAP, map, PLR1, plr1, PLR2, plr2, (char *)0);
	ft_memdel((void **)&plr1);
	ft_memdel((void **)&plr2);
	ft_memdel((void **)&map);
}

void	start_program(t_data *d)
{
	pid_t	pid;

	if (pipe(d->pipefd) == -1)
		exit(1);
	if ((pid = fork()) == -1)
		exit(1);
	if (pid == 0)
	{
		dup2(d->pipefd[1], STDOUT_FILENO);
		close(d->pipefd[0]);
		close(d->pipefd[1]);
		set_program(d, NULL, NULL, NULL);
		exit(1);
	}
}

int		main(void)
{
	t_data	d;

	ft_bzero(&d, sizeof(d));
	if (!sdl_init(&d.sdl))
		return (1);
	buttons_init(&d);
	d.plr_one =
		sdl_texture_from_file("tex/hex_one.png", d.sdl.renderer);
	d.plr_two =
		sdl_texture_from_file("tex/hex_two.png", d.sdl.renderer);
	d.background =
		sdl_texture_from_file("tex/back.png", d.sdl.renderer);
	d.btn[0].active = 1;
	d.btn[7].active = 1;
	d.btn[10].active = 1;
	render(&d);
	sdl_loop(&d);	
	return (0);
}
