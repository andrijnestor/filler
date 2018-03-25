/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 19:35:30 by anestor           #+#    #+#             */
/*   Updated: 2018/02/21 19:51:11 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
		make_list(data, &list);
	//	check_coord(data, ((t_xy *)list->content)->x, ((t_xy *)list->content)->y);
		while (list != NULL && check_coord(data, ((t_xy *)list->content)->x, ((t_xy *)list->content)->y) != 1)
		{
		//	dprintf(2, "%d\n", ((t_xy *)list->content)->z);
			list = list->next;
		}
		if (list == NULL)
			dprintf(1, "0 0\n");
		//if (check_place(data, ((t_xy *)list->content)->x, ((t_xy *)list->content)->y) == 1)
		//	dprintf(1, "%d %d\n", ((t_xy *)list->content)->y, ((t_xy *)list->content)->x);
	//	if (check_place(data, 2, 7) == 1)
	//		dprintf(1, "%d %d\n", 7, 2);
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
