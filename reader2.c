/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:49:02 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/19 10:36:50 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void safe_exit(char **line)
{
	if (*line)
		ft_strdel(line);
	exit(EXIT_FAILURE);
}

static void read_map_h_w(char **line, t_infs *infs)
{
	char *k;

	k = 0;
	k = *line;
	(*line) += 8;
	infs->maph = ft_atoi(*line);
	while (**line && **line != ' ')
		(*line)++;
	(*line)++;
	infs->mapw = ft_atoi(*line);
	ft_strdel(&k);
}

void	read_infos(t_infs *infs)
{
	char	*line;

	line = 0;
	if (get_next_line(0, &line) > 0 && ft_strlen(line) > 10)
	{
		infs->pnum = ft_atoi(line + 10);
		infs->mark = (infs->pnum == 1) ? 'O' : 'X';
		infs->enmark = (infs->pnum == 1) ? 'X' : 'O';
		ft_strdel(&line);
	}
	else
		safe_exit(&line);
	if (get_next_line(0, &line) > 0 && ft_strlen(line) > 8)
		read_map_h_w(&line, infs);
	else
		safe_exit(&line);
	if (!(infs->mapw) || !(infs->maph))
		exit(EXIT_FAILURE);
}

void	read_hw_tet(t_infs *infs)
{
	char	*line;
	char	*tmp;

	if (get_next_line(0, &line) > 0)
	{
		tmp = line;
		while (*line && !ft_isdigit(*line))
			line++;
		infs->teth = ft_atoi(line);
		while (*line && *line != ' ')
			line++;
		while (*line && !ft_isdigit(*line))
			line++;
		infs->tetw = ft_atoi(line);
		ft_strdel(&tmp);
	}
}

void	read_tet(t_infs *infs)
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
