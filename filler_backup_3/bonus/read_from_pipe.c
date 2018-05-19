/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 11:45:58 by anestor           #+#    #+#             */
/*   Updated: 2018/04/01 21:21:14 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	set_xy(char *str, int *x, int *y)
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

void		read_sub(t_data *d, char *line)
{
	static int	res;

	if (ft_strstr(line, "== O fin:"))
	{
		res = ft_atoi(line + 10);
		dprintf(2, "%s\n", line); //
	}
	if (ft_strstr(line, "== X fin:"))
	{
		d->win = (res > ft_atoi(line + 10)) ? 1 : 2;
		dprintf(2, "%s\n", line); //
		render(d);
		d->start = 0;
		d->plr_rect = 0;
	}
	if (ft_strstr(line, "error") || ft_strstr(line, "segmentation"))
	{
		d->start = 0;
		d->plr_rect = 0;
	}
}

void		read_from_pipe(t_data *d)
{
	char	*line;

	close(d->pipefd[1]);
	if (get_next_line(d->pipefd[0], &line) > 0)
	{
		if (ft_strstr(line, "Plateau"))
			set_xy(line, &d->mp_rect.w, &d->mp_rect.h);
		if (line[0] == '0')
			ft_memcpy(d->mp[ft_atoi(line)], line + 4, ft_strlen(line + 4));
		if (ft_strstr(line, "Piece"))
			d->sdl.activities = 1;
		read_sub(d, line);
		ft_memdel((void **)&line);
	}
}
