/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:38:12 by dsaadia           #+#    #+#             */
/*   Updated: 2018/03/07 21:59:03 by dsaadia          ###   ########.fr       */
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
			if (is_placable(infs, i, j, &point))
			{
				// point.y = i;
				// point.x = j;
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

int play(t_infs *infs)
{
	t_points our_moves;
	t_points their_moves;
	t_point choice;
	static int spread_over = 0;

	our_moves = get_our_moves(infs);
	if (our_moves.len == 0)
		return (0);
	their_moves = get_their_moves(infs);
	// if (!spread_over)
	// {
	// 	ft_fprintf(2, "ou on est (%d %d), dist to spread %d, la direction %d, long de la dir %d\n",
	// 	(infs->loc).x,(infs->loc).y,spread_dist(infs, infs->loc),infs->direction,infs->dirlen);
	// 	choice = to_spread(infs, our_moves);
	// }
	if (spread_dist(infs, infs->loc) > (infs->dirlen)*8/10)
		spread_over = 1;
	if (!(infs->strategy) && !spread_over)
	{
		choice = to_spread(infs, our_moves);
	}
	else
		choice = (infs->strategy) ? minpt_of_mins(their_moves, our_moves) : kill_enemy(infs, our_moves);
	if (choice.y < 0 || choice.x < 0)
		return (0);
	(infs->loc).x = choice.x;
	(infs->loc).y = choice.y;
	ft_printf("%d %d\n",choice.y, choice.x);
	ft_free_all(4, our_moves.vals, their_moves.vals, infs->map, infs->tet);
	return(1);
}
