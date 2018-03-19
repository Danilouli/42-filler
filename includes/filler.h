/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:20:47 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/19 10:40:46 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/includes/libft.h"

typedef struct		s_point
{
	int				y;
	int				x;
}					t_point;

typedef struct		s_points
{
	t_point			*vals;
	int				len;
}					t_points;

typedef struct		s_infs
{
	int				pnum;
	int				maph;
	int				mapw;
	char			mark;
	char			enmark;
	char			**map;
	int				teth;
	int				tetw;
	t_point			loc;
	char			**tet;
	int				strategy;
	int				direction;
	int				dirlen;
}					t_infs;

void				read_infos(t_infs *infs);
void				read_tet(t_infs *infs);
void				read_map_tet(t_infs *infs);
int					touch_one(t_infs *infs, int y, int x);
int					is_placable(t_infs *infs, int y, int x, t_point *point);
int					is_enfree(t_infs *infs, int i, int j);
void				play(t_infs *infs);
int					dist(t_point p1, t_point p2);
int					min_dist_to_en(t_points their_moves, t_point we);
t_point				minpt_of_mins(t_points their_moves, t_points our_moves);
int					max_dist_to_en(t_points their_moves, t_point we);
int					max_of_maxs(t_points their_moves, t_points our_moves);
t_point				mid_of_maxs(t_points their_moves, t_points our_moves);
t_point				max_dist_to_frame(t_infs *infs, t_points our_moves);
t_point				kill_enemy(t_infs *in, t_points our_moves);
t_point				to_spread(t_infs *in, t_points our_moves);
t_point				to_spreadm(t_infs *in, t_points our_moves);
int					spread_dist(t_infs *in, t_point m);
int					spreadr_dist(t_infs *in, t_point m);
t_point				to_spreadr(t_infs *in, t_points our_moves);
int					dist_to_dir(t_infs *in);
int					dist_to_rdir(t_infs *in);
int					min_dist_to_en(t_points their_moves, t_point we);

#endif
