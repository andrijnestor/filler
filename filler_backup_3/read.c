/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 12:44:20 by anestor           #+#    #+#             */
/*   Updated: 2018/03/31 02:35:37 by anestor          ###   ########.fr       */
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
	set_xy(data->mp, &data->mp_w, &data->mp_h);
	data->map = ft_memalloc(sizeof(char *) * data->mp_h + 1);
	i = 0;
	while (i != data->mp_h + 1)
		get_next_line(0, &data->map[i++]);
	if (!get_next_line(0, &data->pc))
		return (0);
	set_xy(data->pc, &data->pc_w, &data->pc_h);
	data->piece = ft_memalloc(sizeof(char *) * data->pc_h);
	i = 0;
	while (i < data->pc_h)
		get_next_line(0, &data->piece[i++]);
	return (1);
}

void	clear_filler(t_flr *data)
{
	int		i;

	ft_memdel((void **)&data->mp);
	i = 0;
	while (i != data->mp_h + 1)
		ft_memdel((void **)&data->map[i++]);
	ft_memdel((void **)&data->map);
	ft_memdel((void **)&data->pc);
	i = 0;
	while (i != data->pc_h)
		ft_memdel((void **)&data->piece[i++]);
	ft_memdel((void **)&data->piece);
	ft_del_matrix(data->e_map, data->emp_h);
}
