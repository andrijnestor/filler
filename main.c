/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 19:35:30 by anestor           #+#    #+#             */
/*   Updated: 2018/02/21 14:51:27 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
/*
int		read(void)
{
	int		fd;
	char	*line1;
	char	*line2;
	char	*map;
	char	*piece;

	fd = 0;
	get_nex_line(fd, &line1);
	
}
*/

void	print_filler(t_flr *data, int fd)
{
	int		i;

	dprintf(fd, "%s x: %d y: %d\n", data->mp, data->mp_x, data->mp_y);
	i = 0;
	while (i != data->mp_y + 1)
		dprintf(fd, "%s\n", data->map[i++]);
	dprintf(fd, "%s x: %d y: %d\n", data->pc, data->pc_x, data->pc_y);
	i = 0;
	while (i != data->pc_y)
		dprintf(fd, "%s\n", data->piece[i++]);
}

int		get_player(t_flr *data, int fd) ///
{
	char	*plr;

	if (!get_next_line(0, &plr))
		return (0);
	if (ft_strstr(plr, "p1"))
		data->player = 0;
	else if (ft_strstr(plr, "p2"))
		data->player = 1;
	else
		return (0);
	dprintf(fd, "%s\n", plr); ////
	ft_memdel((void **)&plr);
	return (1);
}

int		filler(void)
{
	t_flr	*data;
	t_list	*list;
	int		fd = open("trace", O_RDWR | O_CREAT | O_TRUNC, 0644); ///

	list = NULL;
	data = ft_memalloc(sizeof(t_flr));
	if (!get_player(data, fd)) ///
		return (0);
	while (read_filler(data))
	{
		print_filler(data, fd); ///
		make_list(data, list);
		while (list != NULL)
		{
			dprintf(fd, "%d ", list->content->x);
			list = list->next;
		}
		write(1, "8 2\n", 4);
		clear_filler(data);
	}
	ft_memdel((void **)&data);
	return (1);
}

int		main(void)
{
	filler();	
	return (0);
}
