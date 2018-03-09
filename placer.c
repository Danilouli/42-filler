/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:40:44 by dsaadia           #+#    #+#             */
/*   Updated: 2018/03/09 12:52:49 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int touch_one(t_infs *infs, int y, int x)
{
	int i;
	int j;
	int touchs;

	touchs = 0;
	i = -1;
	while (++i < infs->teth)
	{
		j = -1;
		while (++j < infs->tetw)
		{
			if ((infs->tet)[i][j] == '*' && (infs->map)[y + i][x + j] == infs->mark)
				touchs = touchs + 1;
			if ((infs->tet)[i][j] == '*'
		 	&& ((infs->map)[y + i][x + j] == infs->enmark
			|| (infs->map)[y + i][x + j] == ft_tolower(infs->enmark)))
				return (0);
		}
	}
	return ((touchs == 1) ? 1 : 0);
}

int	is_placable(t_infs *infs, int y, int x, t_point *point)
{
	if (infs->mapw - x >= infs->tetw && infs->maph - y >= infs->teth)
	{
		if (touch_one(infs, y, x))
		{
			point->y = y;
			point->x = x;
			return (1);
		}
		else
			return (0);
	}
	return (0);
}

int is_enfree(t_infs *infs, int i, int j)
{
	if((infs->map[i][j] == infs->enmark
	|| infs->map[i][j] == ft_tolower(infs->enmark))
	&& ((j - 1 >= 0 && infs->map[i][j - 1] == '.')
	|| (j + 1 < infs->mapw && infs->map[i][j + 1] == '.')
	|| (i - 1 >= 0 && infs->map[i - 1][j] == '.')
	|| (i + 1 < infs->maph && infs->map[i + 1][j] == '.')))
		return (1);
	return (0);
}

int min_dist_to_en(t_points their_moves, t_point we)
{
	int i;
	int min;
	int d;

	i = 0;
	if (their_moves.len == 0)
		return (0);
	min = 2147483647;
	d = 0;
	while (i < their_moves.len)
	{
		d = dist(their_moves.vals[i], we);
		min = (d <= min) ? d : min;
		i++;
	}
	return (min);
}
