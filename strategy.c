/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:52:36 by dsaadia           #+#    #+#             */
/*   Updated: 2018/03/17 21:09:54 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_point	minpt_of_mins(t_points their_moves, t_points our_moves)
{
	int		i;
	int		min;
	t_point	ret;
	int		k;

	min = 2147483647;
	ret = our_moves.vals[0];
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

t_point	find_enemy(t_infs *in)
{
	int		i;
	int		j;
	t_point	ret;

	i = 0;
	ret.x = 0;
	ret.y = 0;
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

t_point	kill_enemy(t_infs *in, t_points our_moves)
{
	t_point	en_loc;
	int		i;
	int		min;
	t_point	ret;
	int		k;

	en_loc = find_enemy(in);
	min = 2147483647;
	ret = our_moves.vals[0];
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

t_point	to_spread(t_infs *in, t_points our_moves)
{
	int		i;
	int		min;
	t_point	ret;
	int		k;

	min = 2147483647;
	ret = our_moves.vals[0];
	i = 0;
	while (i < our_moves.len)
	{
		if ((k = spread_dist(in, our_moves.vals[i])) <= min)
		{
			ret = our_moves.vals[i];
			min = k;
		}
		i++;
	}
	return (ret);
}

t_point	to_spreadr(t_infs *in, t_points our_moves)
{
	int		i;
	int		min;
	t_point	ret;
	int		k;

	min = 2147483647;
	ret = our_moves.vals[0];
	i = 0;
	while (i < our_moves.len)
	{
		if ((k = spreadr_dist(in, our_moves.vals[i])) < min)
		{
			ret = our_moves.vals[i];
			min = k;
		}
		i++;
	}
	return (ret);
}
