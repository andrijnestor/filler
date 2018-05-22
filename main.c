/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 19:35:30 by anestor           #+#    #+#             */
/*   Updated: 2018/05/22 18:23:42 by anestor          ###   ########.fr       */
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
}

int		get_player(t_flr *data)
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
	ft_memdel((void **)&plr);
	return (1);
}

int		filler(void)
{
	t_flr	*data;

	data = ft_memalloc(sizeof(t_flr));
	if (!get_player(data))
		return (0);
	while (read_filler(data))
	{
		make_rect(data);
		make_result(data);
		clear_filler(data);
		ft_putnbr_fd(data->result.y, 1);
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(data->result.x, 1);
		ft_putchar_fd('\n', 1);
	}
	ft_memdel((void **)&data);
	return (1);
}

int		main(void)
{
	filler();
	return (0);
}
