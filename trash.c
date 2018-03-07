/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:17:50 by dsaadia           #+#    #+#             */
/*   Updated: 2018/03/07 20:14:16 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int max_dist_to_en(t_points their_moves, t_point we)
{
	int i;
	int max;
	int d;

	i = 0;
	if (their_moves.len == 0)
		return (0);
	max = 0;
	d = 0;
	while (i < their_moves.len)
	{
		d = dist(their_moves.vals[i], we);
		max = (d >= max) ? d : max;
		i++;
	}
	return (max);
}

t_point maxpt_of_maxs(t_points their_moves, t_points our_moves)
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

int min_of_mins(t_points their_moves, t_points our_moves)
{
	int i;
	int ret;
	int k;

	ret = 2147483647;
	i = 0;
	k = 0;
	while (i < our_moves.len)
	{
		if ((k = min_dist_to_en(their_moves, our_moves.vals[i])) < ret)
			ret = k;
		i++;
	}
	return (ret);
}

int moy_dist_to_en(t_points their_moves, t_point we)
{
	return ((max_dist_to_en(their_moves, we) + min_dist_to_en(their_moves, we)) / 2);
}

int max_of_maxs(t_points their_moves, t_points our_moves)
{
	int i;
	int ret;
	int k;

	ret = 0;
	i = 0;
	k = 0;
	while (i < our_moves.len)
	{
		if ((k = max_dist_to_en(their_moves, our_moves.vals[i])) > ret)
			ret = k;
		i++;
	}
	return (ret);
}

t_point mid_of_maxs(t_points their_moves, t_points our_moves)
{
	int i;
	int moy;
	t_point ret;
	int k;
	int d;

	moy = (max_of_maxs(their_moves, our_moves) + min_of_mins(their_moves, our_moves))/2;
	ret.y = -1;
	ret.x = -1;
	i = 0;
	k = 2147483647;
	d = 0;
	while (i < our_moves.len)
	{
		d = ABS(moy_dist_to_en(their_moves, our_moves.vals[i]) - moy);
		if (d < k)
		{
			k = d;
			ret = our_moves.vals[i];
		}
		i++;
	}
	return (ret);
}

int dist_to_frame(t_infs *infs, t_point m)
{
	int dt;
	int dr;
	int db;
	int dl;

	dt = (m.ay > m.y && void_there(infs, m.ay - 1, m.x)) ? m.ay : 0;
	dr = (m.ax < m.x && m.ax + 1 < infs->mapw && infs->map[m.ay][m.ax + 1] == '.') ? (infs->mapw - m.ax) : 0;
	db = (m.ay < m.y && m.ay + 1 < infs->maph && infs->map[m.ay + 1][m.ax] == '.') ? (infs->maph - m.ay) : 0;
	dl = (m.ax > m.x && m.ax - 1 >= 0 && infs->map[m.ay][m.ax - 1] == '.') ? m.ax : 0;
	return (ft_max_nums(4, dt, dr, db, dl));
}

t_point max_dist_to_frame(t_infs *infs, t_points our_moves)
{
	int i;
	int k;
	t_point ret;
	int maxn;

	ret.y = -1;
	ret.x = -1;
	i = 0;
	k = 0;
	while (i < our_moves.len)
	{
		if ((maxn = dist_to_frame(infs, our_moves.vals[i])) > k)
		{
			k = maxn;
			ret = our_moves.vals[i];
		}
		i++;
	}
	return (ret);
}
