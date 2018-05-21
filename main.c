/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 19:35:30 by anestor           #+#    #+#             */
/*   Updated: 2018/05/21 15:05:42 by anestor          ###   ########.fr       */
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
			dprintf(fd, "%d ", data->e_map[i.y][i.x]);
			i.x++;
		}
		dprintf(fd, "\n");
		i.y++;
	}
	dprintf(3, "e_pos x %d y %d\n", data->e_pos.x, data->e_pos.y);
}

void	make_temp_result(t_flr *data, t_xyz *temp, int y, int x)
{
	t_rect	r;

	r = data->rect;
	dprintf(3, "is seg here?\n");
	if (data->e_map[y + r.y][x + r.x] < temp[0].z)
	{
		temp[0].x = x;
		temp[0].y = y;
		temp[0].z = data->e_map[y + r.y][x + r.x];
	}
	if (data->e_map[y + r.y][x + r.x + r.w] < temp[1].z)
	{
		temp[1].x = x;
		temp[1].y = y;
		temp[1].z = data->e_map[y + r.y][x + r.x + r.w];
	}
	if (data->e_map[y + r.y + r.h][x + r.x] < temp[2].z)
	{
		temp[2].x = x;
		temp[2].y = y;
		temp[2].z = data->e_map[y + r.y + r.h][x + r.x];
	}
	if (data->e_map[y + r.y + r.h][x + r.x + r.w] < temp[3].z)
	{
		temp[3].x = x;
		temp[3].y = y;
		temp[3].z = data->e_map[y + r.y + r.h][x + r.x + r.w];
	}
	dprintf(3, "no its not\n");
}

void	make_result(t_flr *data)
{
	t_xy	i;
	t_xyz	temp[4];
	t_rect	r;

	temp[0] = ft_xyz(0, 0, 100000);
	temp[1] = ft_xyz(0, 0, 100000);
	temp[2] = ft_xyz(0, 0, 100000);
	temp[3] = ft_xyz(0, 0, 100000);
	r = data->rect;
	i.y = -r.y;
	while (i.y != data->mp_h - r.h)
	{
		i.x = -r.x;
		while (i.x != data->mp_w - r.w)
		{
			if (check_coord(data, i.x, i.y) == 1)
				make_temp_result(data, temp, i.y, i.x);
			i.x++;
		}
		i.y++;
	}
	data->result = temp[0];
	if (temp[1].z < data->result.z)
		data->result = temp[1];
	if (temp[2].z < data->result.z)
		data->result = temp[2];
	if (temp[3].z < data->result.z)
		data->result = temp[3];
	dprintf(3, "x %d y %d z %d\n", data->result.x, data->result.y, data->result.z);
}

/*
void	make_result(t_flr *data)
{
	t_xy	i;
	t_xyz	temp;
	t_rect	r;

	temp = ft_xyz(0, 0, -1);
	r = data->rect;
	i.y = -r.y;
	while (i.y != data->mp_h)
	{
		i.x = -r.x;
		while (i.x != data->mp_w)
		{
			if (check_coord(data, i.x, i.y) == 1 &&
					data->e_map[i.y + r.y + 1][i.x + r.x + 1] > temp.z)
			{
				temp.x = i.x;
				temp.y = i.y;
				temp.z = data->e_map[i.y + r.y + 1][i.x + r.x + 1];
				dprintf(3, "x %d y %d z %d\n", temp.x, temp.y, temp.z);
			}
			i.x++;
		}
		i.y++;
	}
	data->result = temp;
	dprintf(3, "x %d y %d z %d\n", data->result.x, data->result.y, data->result.z);
}
*/

void	enemy_pos(t_flr *data)
{
	t_xy	i;
	char	enemy;

	if (data->e_pos.y == 0 && data->e_pos.x == 0)
	{
		enemy = (data->player == 0) ? PLR_2 : PLR_1;
		i.y = YMO;
		while (i.y != data->mp_h + YMO)
		{
			i.x = XMO;
			while (i.x != data->mp_w + XMO)
			{
				if (data->map[i.y][i.x] == enemy)
				{
					data->e_pos.x = i.x - XMO;
					data->e_pos.y = i.y - YMO;
					return ;
				}
				i.x++;
			}
			i.y++;
		}
	}
}

int		filler(void)
{
	t_flr	*data;
	int		fd = open("trace", O_RDWR | O_CREAT | O_TRUNC, 0644); ///

	data = ft_memalloc(sizeof(t_flr));
	if (!get_player(data, fd)) ///
		return (0);
	while (read_filler(data))
	{
		enemy_pos(data);
		make_rect(data);
		print_filler(data, fd); ///
		make_enemy_map(data);
		print_enemy_map(data, fd);
		make_res(data);
		
		print_enemy_map(data, fd);
		make_result(data);
	//	make_res(data);
	//	clear_filler(data);
		dprintf(3, "%d %d\n", data->result.y, data->result.x);
		dprintf(1, "%d %d\n", data->result.y, data->result.x);
	}
	ft_memdel((void **)&data);
	return (1);
}

int		main(void)
{
	filler();	
	return (0);
}
