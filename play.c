/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:38:12 by dsaadia           #+#    #+#             */
/*   Updated: 2018/03/06 21:32:04 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_points get_our_moves(t_infs *infs)
{
	t_points ret;
	int i;
	int j;
	t_point point;

	ret.vals = (t_point*)malloc(sizeof(t_point) * (infs->maph * infs->mapw));
	ret.len = 0;
	i = 0;
	point.y = 0;
	point.x = 0;
	while (i < infs->maph)
	{
		j = 0;
		while (j < infs->mapw)
		{
			if (is_placable(infs, i, j))
			{
				point.y = i;
				point.x = j;
				ret.vals[ret.len] = point;
				ret.len = ret.len + 1;
			}
			j++;
		}
		i++;
	}
	return (ret);
}

static t_points get_their_moves(t_infs *infs)
{
	t_points ret;
	int i;
	int j;
	t_point point;

	ret.vals = (t_point*)malloc(sizeof(t_point) * (infs->maph * infs->mapw));
	ret.len = 0;
	i = 0;
	point.y = 0;
	point.x = 0;
	while (i < infs->maph)
	{
		j = 0;
		while (j < infs->mapw)
		{
			if (is_enfree(infs, i, j))
			{
				point.y = i;
				point.x = j;
				ret.vals[ret.len] = point;
				ret.len = ret.len + 1;
			}
			j++;
		}
		i++;
	}
	return (ret);
}

static int dist(t_point p1, t_point p2)
{
	return ((p1.y - p2.y)*(p1.y - p2.y) + (p1.x - p2.x)*(p1.x - p2.x));
}

static int min_dist_to_en(t_points their_moves, t_point we)
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

static t_point min_of_mins(t_points their_moves, t_points our_moves)
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


int play(t_infs *infs)
{
	t_points our_moves;
	t_points their_moves;
	t_point choice;

	our_moves = get_our_moves(infs);
	if (our_moves.len == 0)
		return (0);
	their_moves = get_their_moves(infs);
	choice = min_of_mins(their_moves, our_moves);
	ft_fprintf(2, "---------CHOIX %d %d touch %d\n",choice.y, choice.x, touch_one(infs, choice.y, choice.x));
	ft_printf("%d %d\n",choice.y, choice.x);
	return(1);
}
