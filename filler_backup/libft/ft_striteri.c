/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:49:38 by anestor           #+#    #+#             */
/*   Updated: 2017/10/31 16:10:34 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		n;

	n = 0;
	if (s && f)
	{
		while (s[n] != '\0')
		{
			(*f)(n, &s[n]);
			n++;
		}
	}
}
