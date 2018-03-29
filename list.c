/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:34:25 by anestor           #+#    #+#             */
/*   Updated: 2018/03/29 20:12:53 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	lst_add_sort(t_list **list, t_list *new) 
{
	t_list	*tmp;

	if (*list == NULL || ((t_xyz *)(*list)->content)->z <= ((t_xyz *)new->content)->z)
	{
		new->next = *list;
		*list = new;
	}
	else
	{
		tmp = *list;
		while (tmp->next != NULL && ((t_xyz *)tmp->next->content)->z > ((t_xyz *)new->content)->z)
			tmp = tmp->next;
		new->next = tmp->next;
		tmp->next = new;
	}
}
/*
void	make_list(t_flr *data, t_list **list)
{
	t_xyz	temp;
	t_xy	i;
	int		plr;

	plr = (data->player == 0) ? 'O' : 'X';
	i.y = 1;
	while (i.y != data->mp_y + YMO)
	{
		i.x = 0;
		while (i.x != data->mp_x + XMO)
		{
			if (data->map[i.y][i.x] == plr)
			{
				temp.x = i.x - XMO;
				temp.y = i.y - YMO;
				temp.z = data->e_map[i.y][i.x - 2];  // -2 -3
				lst_add_sort(list, ft_lstnew(&temp, sizeof(t_xyz)));
				dprintf(2, "hi\n");
			}
			i.x++;
		}
		i.y++;
	}
}
*/

void	make_list(t_flr *data, t_list **list)
{
	t_xy	i;
	t_xyz	temp;
	int		plr;

	plr = (data->player == 0) ? 'O' : 'X';
	i.y = 0;
	while (i.y != data->mp_y)
	{
		i.x = 0;
		while (i.x != data->mp_x)
		{
			if (check_coord(data, i.x, i.y) == 1)
			{
				temp.x = i.x;
				temp.y = i.y;
				temp.z = data->e_map[i.y][i.x - 2];
				dprintf(3, "hi x %d y %d z %d\n", temp.x, temp.y, temp.z);
				lst_add_sort(list, ft_lstnew(&temp, sizeof(t_xyz)));
			}
			i.x++;
		}
		i.y++;
	}	
}


/*
void	make_list(t_flr *data, t_list **list)
{
	t_xy	i;
	t_xyz	temp;
	int		plr;

	plr = (data->player == 0) ? 'O' : 'X';
	i.y = -data->pre.y;
	while (i.y != data->mp_y + data->post.y)
	{
		i.x = -data->pre.x;
		while (i.x != data->mp_x + data->post.x)
		{
			if (check_coord(data, i.x, i.y) == 1)
			{
				temp.x = i.x;
				temp.y = i.y;
				temp.z = data->e_map[i.y][i.x - 3];
//				dprintf(3, "hi x %d y %d z %d\n", temp.x, temp.y, temp.z);
				lst_add_sort(list, ft_lstnew(&temp, sizeof(t_xyz)));
	//			t_list	*test;
	//		   	test = ft_lstnew(&temp, sizeof(t_xyz));
	//			dprintf(3, "gg x %d y %d\n", ((t_xyz *)test->content)->x, ((t_xyz *)test->content)->y);
			}
			i.x++;
		}
		i.y++;
	}
	
	t_list 	*tmp;
	tmp = *list;
	while (tmp != NULL)
	{
		dprintf(3, "gg y %d x %d z %d\n", ((t_xyz *)tmp->content)->y, ((t_xyz *)tmp->content)->x, ((t_xyz *)tmp->content)->z);
		tmp = tmp->next;
	}
	
}
*/

/*
void	make_list(t_flr *data, t_list **list)
{
	t_xy	i;
	int		plr;

	plr = (data->player == 0) ? 'O' : 'X';
	i.y = -data->pre.y;
	while (i.y != data->mp_y)
	{
		i.x = -data->pre.x;
		while (i.x != data->mp_x + data->post.x)
		{
			if (check_coord(data, i.x, i.y) == 1)
				ft_lstadd(list, ft_lstnew(&i, sizeof(t_xy)));
			i.x++;
		}
		i.y++;
	}
}
*/
