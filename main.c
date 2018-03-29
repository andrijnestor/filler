/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 19:35:30 by anestor           #+#    #+#             */
/*   Updated: 2018/03/29 19:45:35 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	make_rect(t_flr *data)
{
	int		i;

	i = 0;
	while (i < data->pc_y && !check_pc_y(data, i))
		i++;
	data->rect.y = i;

	while (i < data->pc_y && check_pc_y(data, i))
		i++;
	data->rect.h = i - data->rect.y;

	i = 0;
	while (i < data->pc_x && !check_pc_x(data, i))
		i++;
	data->rect.x = i;

	while (i < data->pc_x && check_pc_x(data, i))
		i++;
	data->rect.w = i - data->rect.x;

	/*
	i = data->pc_y - 1;
	while (!check_pc_y(data, i) && i > -1)
		i--;
	data->rect.h = i - data->rect.y + 1;
	i = data->pc_x - 1;
	while (!check_pc_x(data, i) && i > -1)
		i--;
	data->rect.w = i - data->rect.x + 1;
*/

	dprintf(3, "rect x %d y %d h %d w %d\n", data->rect.x, data->rect.y, data->rect.h, data->rect.w);
}

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

int		z_calc(t_flr *data, t_xy reg)
{
	int		z;

	z = 0;
	if (data->pmin.y >= data->emin.y)
	{
		z = WEST(reg.x, reg.y, data->mp_x);
		/*
		if (data->pmin.x >= data->emin.x)
		{
	//		NW
			z = NW(reg.x, reg.y, data->mp_x);
		}
		else
		{
	//		NE
			z = NE(reg.x, reg.y, data->mp_x);
		}
		*/
	} 
	else if (data->pmax.y <= data->emax.y)
	{
		z = SOUTH(reg.x, reg.y, data->mp_y);
		/*
		if (data->pmax.x <= data->emax.x)
		{
	//		SE
			z = SE(reg.x, reg.y, data->mp_x);
		}
		else
		{
	//		SW
			z = SW(reg.x, reg.y, data->mp_x);
		}
		*/
	}
	else if (data->pmin.x >= data->emin.x)
	{
		z = EAST(reg.x, reg.y, data->mp_x);
	}
	else if (data->pmax.x >= data->emax.x)
	{
		z = NORTH(reg.x, reg.y, data->mp_y);
	}
	return (z);
}

void	attack(t_flr *data, t_list **list)
{
	int		z;
//	int		n_z;
	t_xy	reg;
	t_xy	max;
	t_list	*tmp;
	char 	plr;

	z = 0;
	max.x = 0;
	max.y = 0;
	plr = (data->player == 0) ? 'O' : 'X';
	while (*list != NULL)
	{
		reg.x = ((t_xy *)(*list)->content)->x;
		reg.y = ((t_xy *)(*list)->content)->y;
	//	if (z <= NE(reg.x, reg.y, data->mp_x))
		if (z <= z_calc(data, reg))
		{
		//	z = NE(reg.x, reg.y, data->mp_x);
			z = z_calc(data, reg);
			max.x = reg.x;
			max.y = reg.y;
		}
		tmp = *list;
		*list = (*list)->next;
		ft_memdel((void **)&tmp->content);
		ft_memdel((void **)&tmp->content);
	}
	dprintf(1, "%d %d\n", max.y, max.x);
}

void	print_enemy_map(t_flr *data, int fd)
{
	t_xy	i;
	t_xy	size;

	size.x = data->mp_x + 2;
	size.y = data->mp_y + 2;
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
		trim_piece(data);
		print_filler(data, fd); ///
	//	make_list(data, &list);
//		min_max(data);
	//	dprintf(2, "%d %d %d %d %d %d %d %d\n", data->pmin.x, data->pmin.y, data->pmax.x, data->pmax.y,
	//											data->emin.x, data->emin.y, data->emax.x, data->emax.y);
//		attack(data, &list);
	
		make_enemy_map(data);
	//	print_enemy_map(data, fd);
		make_list(data, &list);
	//	check_coord(data, ((t_xy *)list->content)->x, ((t_xy *)list->content)->y);
	//	while (list != NULL && check_coord(data, ((t_xy *)list->content)->x, ((t_xy *)list->content)->y) != 1)

//		while (list != NULL)
//		{
//			(list != NULL)
//				dprintf(1, "%d %d\n", ((t_xyz *)list->content)->y, ((t_xyz *)list->content)->x);
//				dprintf(3, "out %d %d\n", ((t_xyz *)list->content)->y, ((t_xyz *)list->content)->x);
//			list = list->next;
//		}	
		if (list != NULL)
		{
			dprintf(1, "%d %d\n", ((t_xyz *)list->content)->y, ((t_xyz *)list->content)->x);
			dprintf(3, "out %d %d\n", ((t_xyz *)list->content)->y, ((t_xyz *)list->content)->x);
		}
	//	while (list != NULL)
	//	{
	//		dprintf(3, "out 2 %d %d\n", ((t_xyz *)list->content)->y, ((t_xyz *)list->content)->x);
	//		list = list->next;
	//	}	

		if (list == NULL)
		{
			dprintf(1, "0 0\n");
			dprintf(3, "out 0 0\n");
		}
		t_list	*list_next;
		while (list->next != NULL)
		{
			list_next = list->next;
			ft_memdel((void **)&list->content);
			ft_memdel((void **)&list);
			list = list_next;
		}
	//	while (list->next != NULL)
	//	{
	//		list = list->next;
	//		dprintf(fd, "%d %d\n", ((t_xyz *)list->content)->y, ((t_xyz *)list->content)->x);
	//	}
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
