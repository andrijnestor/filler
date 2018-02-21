/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:34:25 by anestor           #+#    #+#             */
/*   Updated: 2018/02/21 14:53:39 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	make_list(t_flr *data, t_list *list)
{
	t_xy	temp;
	t_xy	i;
	t_list	*tmp;

	i.y = 0;
	tmp = NULL;
	while (i.y != data->mp_y + YMO)
	{
		i.x = 0;
		while (i.x != data->mp_x + XMO)
		{
			if (data->map[i.y][i.x] == PLR)
			{
				temp.x = i.x - XMO;
				temp.y = i.y - YMO;
				ft_lstnew(&temp, sizeof(t_xy));
				ft_lstadd(&list, tmp);
			}
			i.x++;
		}
		i.y++;
	}
}
