/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:31:48 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/06 20:47:53 by dsaadia          ###   ########.fr       */
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
    free(line);
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
    free(k);
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
    infs->teth = ft_atoi(line + 6);
		line = line + 6;
    while (*line != ' ')
      line++;
    infs->tetw = ft_atoi(line + 1);
    free(tetstr);
  }
  while (i <= infs->teth && get_next_line(0, &line) > 0)
  {
    tetstr = ft_strjoin(tetstr, line);
    free(line);
    tetstr = ft_strjoin(tetstr, " ");
    i++;
  }
  infs->tet = ft_strsplit(tetstr, ' ');
  if (*tetstr)
    free(tetstr);
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
			free(line);
			mapstr = ft_strjoin(mapstr, " ");
			i++;
		}
  }
  infs->map = ft_strsplit(mapstr, ' ');
	if (*mapstr)
	  free(mapstr);
}

void read_map_tet(t_infs *infs)
{
  read_map(infs);
  read_tet(infs);
}
