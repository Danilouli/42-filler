/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:38:12 by dsaadia           #+#    #+#             */
/*   Updated: 2018/03/09 11:36:54 by schmurz          ###   ########.fr       */
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

void play(t_infs *infs)
{
	t_points our_moves;
	t_points their_moves;
	t_point choice;
	static int spread_over = 1;
	static int spreadr_over = 0;

	our_moves = get_our_moves(infs);
	if (our_moves.len == 0)
	{
		ft_printf("0 0\n");
		return ;
	}
	their_moves = get_their_moves(infs);
	if (dist_to_rdir(infs) <= 0)
	{
		spread_over = 0;
		spreadr_over = 1;
	}
	if (dist_to_dir(infs) <= 0)
		spread_over = 1;
	if (!spread_over)
		choice = to_spread(infs, our_moves);
	if (!spreadr_over)
		choice = to_spreadr(infs, our_moves);
	if ((spread_over && spreadr_over) || (infs->maph <= 25 && infs->mapw <=25))
		choice = (infs->strategy && infs->maph <= 25 && infs->mapw <=25) ? kill_enemy(infs, our_moves) :
		minpt_of_mins(their_moves, our_moves);
	else
	{
		(infs->loc).x = choice.x;
		(infs->loc).y = choice.y;
	}
	ft_printf("%d %d\n",choice.y, choice.x);
	free_strtab(infs->map);
	free_strtab(infs->tet);
	ft_free_all(4, our_moves.vals, their_moves.vals, infs->map, infs->tet);
}
