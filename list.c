/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:34:25 by anestor           #+#    #+#             */
/*   Updated: 2018/02/24 18:14:16 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
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
*/
/*
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
				ft_lstadd(list, ft_lstnew(&temp, sizeof(t_xy)));
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
	int		plr;

	plr = (data->player == 0) ? 'O' : 'X';
	i.y = -data->pre.y;
	while (i.y != data->mp_y + data->post.y)
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
