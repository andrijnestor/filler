/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:34:25 by anestor           #+#    #+#             */
/*   Updated: 2018/02/22 20:40:15 by anestor          ###   ########.fr       */
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

int		calc_power(t_flr *data, int x, int y, int plr)
{
	int		z;
//	char	plr;
//	static int	test = 0;

	(void)plr;
//	plr = (data->player = 0) ? 'O' : 'X';
//	if (test < 10)
	z = (x + 1) * (data->mp_x - x) * (y + 1) * (data->mp_y - y);
//	else if (!ft_strchr(data->map[1], plr))
	//	z = NORTH(x + 1, y + 1, data->mp_x);
//	else  
//		z = SOUTH(x + 1, y + 1, data->mp_x);
//	z = NE(x + 1, y + 1, data->mp_x);
	/*
	if (!ft_strchr(data->map[1], plr))
		z = NORTH(x + 1, y + 1, data->mp_x);
//	else if (data->map[data->mp_y / 2][4] != plr)
//		z = WEST(x + 1, y + 1, data->mp_y);
	else if (!ft_strchr(data->map[data->mp_y - 1], plr))
		z = SOUTH(x + 1, y + 1, data->mp_x);
	else
		z = NW(x + 1, y + 1, data->mp_y);
//	else if (data->map[data->mp_y / 2][4] != plr)
//		z = WEST(x + 1, y + 1, data->mp_y);
//	else
//	{
//		z = (x + 1) * (data->mp_x - x) * (y + 1) * (data->mp_y - y);
//		z *= -1;
//	}
*/
//	z = NE(x + 1, y + 1, data->mp_x);
	return (z);
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

				temp.z = calc_power(data, temp.x, temp.y, plr);
			//	temp.z = NORTH(temp.x + 1, temp.y + 1, data->mp_x);

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
