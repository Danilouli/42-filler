/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:52:36 by dsaadia           #+#    #+#             */
/*   Updated: 2018/03/07 21:52:49 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int dist(t_point p1, t_point p2)
{
	return (ABS(p1.y - p2.y) + ABS(p1.x - p2.x));
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

t_point minpt_of_mins(t_points their_moves, t_points our_moves)
{
	int i;
	int min;
	t_point ret;
	int k;

	min = 2147483647;
	ret.y = -1;
	ret.x = -1;
	i = 0;
	k = 0;
	while (i < our_moves.len)
	{
		if ((k = min_dist_to_en(their_moves, our_moves.vals[i])) < min)
		{
			ret = our_moves.vals[i];
			min = k;
		}
		i++;
	}
	return (ret);
}

int void_there(t_infs *i, int y, int x)
{
	return (0 <= x && x < i->mapw && 0 <= y && y < i->maph
		&& i->map[y][x] == '.');
}

t_point find_enemy(t_infs *in)
{
	int i;
	int j;
	t_point ret;

	i = 0;
	ret.y = -1;
	ret.x = -1;
	while (i < in->maph)
	{
		j = 0;
		while (j < in->mapw)
		{
			if (in->map[i][j] == ft_tolower(in->enmark))
			{
				ret.y = i;
				ret.x = j;
				return (ret);
			}
			j++;
		}
		i++;
	}
	return (ret);
}

t_point kill_enemy(t_infs *in, t_points our_moves)
{
	t_point en_loc;
	int i;
	int min;
	t_point ret;
	int k;

	en_loc = find_enemy(in);
	min = 2147483647;
	ret.y = -1;
	ret.x = -1;
	i = 0;
	while (i < our_moves.len)
	{
		if ((k = dist(en_loc, our_moves.vals[i])) < min)
		{
			ret = our_moves.vals[i];
			min = k;
		}
		i++;
	}
	return (ret);
}

int spread_dist(t_infs *in, t_point m)
{
	if (in->direction == 0)
		return (ABS(m.y));
	if (in->direction == 1)
		return (ABS(in->mapw - m.x));
	if (in->direction == 2)
		return (ABS(in->maph - m.y));
	if (in->direction == 3)
		return (ABS(m.x));
	return (ABS(m.x));
}

t_point to_spread(t_infs *in, t_points our_moves)
{
	int i;
	int min;
	t_point ret;
	int k;

	min = 2147483647;
	ret.y = -1;
	ret.x = -1;
	i = 0;
	while (i < our_moves.len)
	{
		if ((k = spread_dist(in, our_moves.vals[i])) < min)
		{
			ret = our_moves.vals[i];
			min = k;
		}
		i++;
	}
	return (ret);
}

t_point to_spreadm(t_infs *in, t_points our_moves)
{
	int i;
	int max;
	t_point ret;
	int k;

	max = 0;
	ret.y = -1;
	ret.x = -1;
	i = 0;
	while (i < our_moves.len)
	{
		if ((k = spread_dist(in, our_moves.vals[i])) > max)
		{
			ret = our_moves.vals[i];
			max = k;
		}
		i++;
	}
	return (ret);
}
