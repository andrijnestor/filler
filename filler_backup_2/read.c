/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 12:44:20 by anestor           #+#    #+#             */
/*   Updated: 2018/03/26 16:11:19 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	set_xy(char *str, int *x, int *y)
{
	int		i;

	i = 0;
	while (!ft_isdigit(str[i]))
		i++;
	*y = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	while (!ft_isdigit(str[i]))
		i++;
	*x = ft_atoi(&str[i]);
}

int		read_filler(t_flr *data)
{
	int		i;

	if (!get_next_line(0, &data->mp))
		return (0);
	set_xy(data->mp, &data->mp_x, &data->mp_y);
	data->map = ft_memalloc(sizeof(char *) * data->mp_y + 1);
	i = 0;
	while (i != data->mp_y + 1)
		get_next_line(0, &data->map[i++]);
	if (!get_next_line(0, &data->pc))
		return (0);
	set_xy(data->pc, &data->pc_x, &data->pc_y);
	data->piece = ft_memalloc(sizeof(char *) * data->pc_y);
	i = 0;
	while (i != data->pc_y)
		get_next_line(0, &data->piece[i++]);
	return (1);
}

void	clear_filler(t_flr *data)
{
	int		i;

	ft_memdel((void **)&data->mp);
	i = 0;
	while (i != data->mp_y + 1)
		ft_memdel((void **)&data->map[i++]);
	ft_memdel((void **)&data->map);
	ft_memdel((void **)&data->pc);
	i = 0;
	while (i != data->pc_y)
		ft_memdel((void **)&data->piece[i++]);
	ft_memdel((void **)&data->piece);
}
