/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:34:25 by anestor           #+#    #+#             */
/*   Updated: 2018/02/22 14:59:17 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	lst_add_sort(t_list **list, t_list *new) 
{
	t_list	*tmp;

	if (*list == NULL || ((t_xy *)(*list)->content)->z <= ((t_xy *)new->content)->z)
	{
		new->next = *list;
		*list = new;
	}
	else
	{
		tmp = *list;
		while (tmp->next != NULL && ((t_xy *)tmp->next->content)->z > ((t_xy *)new->content)->z)
			tmp = tmp->next;
		new->next = tmp->next;
		tmp->next = new;
	}
}

void	make_list(t_flr *data, t_list **list)
{
	t_xy	temp;
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
	//		temp.z = (temp.x + 1) * (data->mp_x - temp.x) * (temp.y + 1) * (data->mp_y - temp.y);
//				temp.z = EAST(temp.x + 1, temp.y + 1, data->mp_y);

				temp.z = NORTH(temp.x + 1, temp.y + 1, data->mp_x);

			//	temp.z = NE(temp.x + 1, temp.y + 1, data->mp_y);
			//	dprintf(3, "%d %d %d\n", temp.y, temp.x, temp.z);
			/*
				if (data->map[data->mp_y / 2][data->mp_x / 2] == 'O'
				|| data->map[data->mp_y / 2][data->mp_x / 2] == 'X')
					temp.z *= -1;
			*/
				//		dprintf(2, "%d\n", temp.z);
			//	if (temp.z <= 0)
			//		dprintf(2, "%d\n", temp.z);
			//	if (temp.z < 0)
			//		temp.z *= -1;
				lst_add_sort(list, ft_lstnew(&temp, sizeof(t_xy)));
//				ft_lstadd(list, ft_lstnew(&temp, sizeof(t_xy)));
			}
			i.x++;
		}
		i.y++;
	}
}
