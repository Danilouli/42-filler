/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:38:12 by dsaadia           #+#    #+#             */
/*   Updated: 2018/03/06 19:12:01 by dsaadia          ###   ########.fr       */
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
	return (ABS(p1.y - p2.y) + 1 + ABS(p1.x - p2.x) + 1);
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
		// ft_fprintf(2, "dist entre (%d, %d) et (%d, %d) : %d\n",their_moves.vals[i].y,their_moves.vals[i].x, we.y, we.x, d);
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
		if ((k = min_dist_to_en(their_moves, our_moves.vals[i])) <= min)
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
	// int i = 0;
	// while (i < our_moves.len)
	// {
	// 	ft_fprintf(2, "(%d, %d) , ",our_moves.vals[i].y, our_moves.vals[i].x);
	// 	i++;
	// }
	// sleep(1);
	// ft_fprintf(2, "et eux\n");
	their_moves = get_their_moves(infs);
	// i = 0;
	// while (i < their_moves.len)
	// {
	// 	ft_fprintf(2, "(%d, %d) , ",their_moves.vals[i].y, their_moves.vals[i].x);
	// 	i++;
	// }
	// sleep(3);
	choice = min_of_mins(their_moves, our_moves);
	ft_fprintf(2, "---------CHOIX %d %d\n",choice.y, choice.x);
	ft_printf("%d %d\n",choice.y, choice.x);
	return(1);
}
