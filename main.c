/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 19:35:30 by anestor           #+#    #+#             */
/*   Updated: 2018/03/31 01:42:40 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	make_rect(t_flr *data)
{
	int		i;

	i = 0;
	while (i < data->pc_h && !check_pc_h(data, i))
		i++;
	data->rect.y = i;
	while (i < data->pc_h && check_pc_h(data, i))
		i++;
	data->rect.h = i - data->rect.y;
	i = 0;
	while (i < data->pc_w && !check_pc_w(data, i))
		i++;
	data->rect.x = i;
	while (i < data->pc_w && check_pc_w(data, i))
		i++;
	data->rect.w = i - data->rect.x;
	dprintf(3, "rect x %d y %d h %d w %d\n", data->rect.x, data->rect.y, data->rect.h, data->rect.w);
}

void	print_filler(t_flr *data, int fd)
{
	int		i;

	dprintf(fd, "%s x: %d y: %d\n", data->mp, data->mp_w, data->mp_h);
	i = 0;
	while (i != data->mp_h + 1)
		dprintf(fd, "%s\n", data->map[i++]);
	dprintf(fd, "%s x: %d y: %d\n", data->pc, data->pc_w, data->pc_h);
	i = 0;
	while (i != data->pc_h)
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

void	print_enemy_map(t_flr *data, int fd)
{
	t_xy	i;
	t_xy	size;

	size.x = data->emp_w;
	size.y = data->emp_h;
	dprintf(fd, "size x: %d, y: %d\n", size.x, size.y);
	i.y = 0;
	while (i.y != size.y)
	{
		i.x = 0;
		dprintf(fd, "%.4d: ", i.y);
		while (i.x != size.x)
		{
			dprintf(fd, "%d ", data->e_map_1[i.y][i.x]);
			i.x++;
		}
		dprintf(fd, "\n");
		i.y++;
	}
}

void	make_result(t_flr *data)
{
	t_xy	i;
	t_xyz	temp;
	t_rect	r;

	temp.x = 0;
	temp.y = 0;
	temp.z = -1;
	r = data->rect;
	i.y = -r.y;
	while (i.y != data->mp_h)
	{
		i.x = -r.x;
		while (i.x != data->mp_w)
		{
			if (check_coord(data, i.x, i.y) == 1 && data->e_map_1[i.y + r.y][i.x - 2 + r.y] * 2
					+ data->e_map_2[i.y + data->rect.y][i.x - 2 + r.y] > temp.z)
			{
				temp.x = i.x;
				temp.y = i.y;
				temp.z = data->e_map_1[i.y + r.y][i.x - 2 + r.y] * 2
					+ data->e_map_2[i.y + data->rect.y][i.x - 2 + r.y];
			}
			i.x++;
		}
		i.y++;
	}
	data->result = temp;
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
		make_rect(data);
		print_filler(data, fd); ///
		make_enemy_map(data);
		print_enemy_map(data, fd);
		make_result(data);
		dprintf(1, "%d %d\n", data->result.y, data->result.x);
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
