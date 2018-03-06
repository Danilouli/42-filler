/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:40:44 by dsaadia           #+#    #+#             */
/*   Updated: 2018/03/06 18:43:42 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int good_point(t_infs *infs, int y, int x)
{
	return (0 <= y && y < infs->maph && 0 <= x && x < infs->mapw);
}

int touch_one(t_infs *infs, int y, int x)
{
	int i;
	int j;
	int touchs;

	touchs = 0;
	i = 0;
	while (i < infs->teth)
	{
		j = 0;
		while (j < infs->tetw)
		{
			if ((infs->tet)[i][j] == '*'
			&& (infs->map)[y + i][x + j] == infs->mark)
			{
				touchs++;
			}
			if ((infs->tet)[i][j] == '*'
		 	&& ((infs->map)[y + i][x + j] == infs->enmark
			|| (infs->map)[y + i][x + j] == ft_tolower(infs->enmark)))
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return ((touchs == 1) ? 1 : 0);
}

int	is_placable(t_infs *infs, int y, int x)
{
	if (infs->mapw - x >= infs->tetw && infs->maph - y >= infs->teth)
	{
		if (touch_one(infs, y, x))
			return (1);
	}
	return (0);
}

int is_enfree(t_infs *infs, int i, int j)
{
	if((infs->map[i][j] == infs->enmark || infs->map[i][j] == ft_tolower(infs->enmark))
	&&
	((j - 1 >= 0 && infs->map[i][j - 1] == '.')
	|| (j + 1 < infs->mapw && infs->map[i][j + 1] == '.')
	|| (i - 1 >= 0 && infs->map[i - 1][j] == '.')
	|| (i + 1 < infs->maph && infs->map[i + 1][j] == '.')))
	{
		return (1);
	}
	return (0);
}
