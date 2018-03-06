/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:20:47 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/06 15:21:20 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/includes/libft.h"
# define ABS(x) ((x < 0) ? (x * -1) : (x))

typedef struct s_infs
{
  int   pnum;
  int   maph;
  int   mapw;
  char  mark;
  char  enmark;
  char  **map;
  int   teth;
  int   tetw;
  int   locy;
  int   locx;
  char  **tet;
}             t_infs;

typedef struct s_point
{
	int y;
	int x;
}								t_point;

typedef struct s_points
{
	t_point *vals;
	int			len;
}								t_points;

void read_infos(t_infs *infs);
void read_map_tet(t_infs *infs);
int touch_one(t_infs *infs, int y, int x);
int	is_placable(t_infs *infs, int y, int x);
int is_enfree(t_infs *infs, int i, int j);
int play(t_infs *infs);

#endif
