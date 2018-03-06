/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:32:41 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/06 19:03:34 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void init_infs(t_infs *infs)
{
  infs->pnum = 0;
  infs->maph = 0;
  infs->mapw = 0;
  infs->mark = 0;
  infs->enmark = 0;
  infs->map = 0;
  infs->teth = 0;
  infs->tetw = 0;
  infs->locx = 0;
  infs->locy = 0;
  infs->tet = 0;
}

int main(void)
{
  t_infs infs;
	char *l;

  init_infs(&infs);
  read_infos(&infs);
	while(get_next_line(0, &l) > 0)
	{
		read_map_tet(&infs);
		if(!play(&infs))
			return (0);
	}
	return (0);
}