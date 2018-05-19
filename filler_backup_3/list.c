/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:34:25 by anestor           #+#    #+#             */
/*   Updated: 2018/03/30 21:22:31 by anestor          ###   ########.fr       */
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

void	make_list(t_flr *data, t_list **list)
{
	t_xy	i;
	t_xyz	temp;
	int		plr;

	plr = (data->player == 0) ? 'O' : 'X';
	i.y = -data->rect.y;
	while (i.y != data->mp_h)
	{
		i.x = -data->rect.x;
		while (i.x != data->mp_w)
		{
			if (check_coord(data, i.x, i.y) == 1)
			{
				temp.x = i.x;
				temp.y = i.y;
				temp.z = data->e_map_1[i.y + data->rect.y][i.x - 2 + data->rect.y] * 10
					+ data->e_map_2[i.y + data->rect.y][i.x - 2 + data->rect.y];
	//			dprintf(3, "hi x %d y %d z %d\n", temp.x, temp.y, temp.z);
				lst_add_sort(list, ft_lstnew(&temp, sizeof(t_xyz)));
			}
			else
			{
				temp.x = 0;
				temp.y = 0;
				temp.z = -1;
	//			dprintf(3, "hi x %d y %d z %d\n", temp.x, temp.y, temp.z);
				lst_add_sort(list, ft_lstnew(&temp, sizeof(t_xyz)));
			}
			i.x++;
		}
		i.y++;
	}
	dprintf(3, "end_hi\n");
}
