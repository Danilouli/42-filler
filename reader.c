/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:31:48 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/08 16:34:12 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void read_infos(t_infs *infs)
{
  char *line;
	char *k;

  if (get_next_line(0, &line) > 0)
  {
    infs->pnum = ft_atoi(line + 10);
    infs->mark = (infs->pnum == 1) ? 'O' : 'X';
    infs->enmark = (infs->pnum == 1) ? 'X' : 'O';
    ft_strdel(&line);
  }
  if (get_next_line(0, &line) > 0)
  {
		k = line;
    line += 8;
    infs->maph = ft_atoi(line);
    while (*line != ' ')
      line++;
    line++;
    infs->mapw = ft_atoi(line);
    ft_strdel(&k);
  }
}

void read_tet(t_infs *infs)
{
  char *line;
  int i;
  char *tetstr;

  i = 1;
  tetstr = "\0";
  if (get_next_line(0, &line) > 0)
  {
		tetstr = line;
    while (!ft_isdigit(*line))
      line++;
    infs->teth = ft_atoi(line);
    while (*line != ' ')
      line++;
    while (!ft_isdigit(*line))
      line++;
    infs->tetw = ft_atoi(line);
    ft_strdel(&tetstr);
  }
  while (i <= infs->teth && get_next_line(0, &line) > 0)
  {
    tetstr = ft_strjoin(tetstr, line);
    ft_strdel(&line);
    tetstr = ft_strjoin(tetstr, "H");
    i++;
  }
  infs->tet = ft_strsplit(tetstr, 'H');
  if (*tetstr)
    ft_strdel(&tetstr);
}

void read_map(t_infs *infs)
{
  char   *line;
  int   i;
  char  *mapstr;

  i = 1;
  mapstr = "\0";
  while (i <= infs->maph && get_next_line(0, &line) > 0)
  {
		if (!ft_isdigit(*(line + 4)))
		{
			mapstr = ft_strjoin(mapstr, (line + 4));
			ft_strdel(&line);
			mapstr = ft_strjoin(mapstr, "\n");
			i++;
		}
  }
  infs->map = ft_strsplit(mapstr, '\n');
	if (*mapstr)
	  ft_strdel(&mapstr);
}

void where_am_i(t_infs *in)
{
	int i;
	int j;

	i = 0;
	while (i < in->maph)
	{
		j = 0;
		while (j < in->mapw)
		{
			if (in->map[i][j] == in->mark || in->map[i][j] == ft_tolower(in->mark))
			{
				(in->loc).y = i;
				(in->loc).x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void where_to_spread(t_infs *infs)
{
	int d[4];
	int max;

	where_am_i(infs);
	d[0] = ABS((infs->loc).y);
	d[1] = ABS(infs->mapw - (infs->loc).x);
	d[2] = ABS(infs->maph - (infs->loc).y);
	d[3] = ABS((infs->loc).x);
	max = ft_max_nums(4, d[0], d[1], d[2], d[3]);
	if (d[0] == max)
		infs->direction = 0;
	else if (d[1] == max)
		infs->direction = 1;
	else if (d[2] == max)
		infs->direction = 2;
	else if (d[3] == max)
		infs->direction = 3;
	if (infs->direction == 0 || infs->direction == 2)
		infs->dirlen = infs->maph;
	if (infs->direction == 1 || infs->direction == 3)
		infs->dirlen = infs->mapw;
}

void read_map_tet(t_infs *infs)
{
  read_map(infs);
  read_tet(infs);
	if (infs->direction == -1)
		where_to_spread(infs);
}
