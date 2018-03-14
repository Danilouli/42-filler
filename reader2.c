/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:49:02 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/14 17:45:11 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void read_infos(t_infs *infs)
{
	char	*line;
	char	*k;

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

void read_hw_tet(t_infs *infs)
{
	char	*line;
	char	*tmp;

	if (get_next_line(0, &line) > 0)
	{
		tmp = line;
		while (!ft_isdigit(*line))
			line++;
		infs->teth = ft_atoi(line);
		while (*line != ' ')
			line++;
		while (!ft_isdigit(*line))
			line++;
		infs->tetw = ft_atoi(line);
		ft_strdel(&tmp);
	}
}

void read_tet(t_infs *infs)
{
	char	*line;
	int		i;
	char	*tetstr;

	i = 1;
	tetstr = ft_strdup("\0");
	read_hw_tet(infs);
	while (i <= infs->teth && get_next_line(0, &line) > 0)
	{
		tetstr = ft_strjoindelone(&tetstr, line);
		ft_strdel(&line);
		tetstr = ft_strjoindelone(&tetstr, "H");
		i++;
	}
	infs->tet = ft_strsplit(tetstr, 'H');
	ft_strdel(&tetstr);
}
