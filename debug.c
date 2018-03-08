/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 21:01:38 by dsaadia           #+#    #+#             */
/*   Updated: 2018/03/08 14:44:05 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void print_infs(t_infs *infs)
{
	int i = 0;
	int j = 0;
	while (i <infs->teth)
	{
		j = 0;
		while (j < infs->tetw)
		{
			ft_fprintf(2, "%c",infs->tet[i][j]);
			j++;
		}
		ft_fprintf(2,"\n");
		i++;
	}
	i = 0;
	j = 0;
	while (i <infs->maph)
	{
		j = 0;
		while (j < infs->mapw)
		{
			ft_fprintf(2, "%c",infs->map[i][j]);
			j++;
		}
		ft_fprintf(2,"\n");
		i++;
	}
}

void print_tout(t_infs *infs, int y, int x)
{
	int i = 0;
	int j;

	ft_fprintf(2,"map\n");
	while (i < infs->maph)
	{
		j = 0;
		while (j < infs->mapw)
		{
			ft_fprintf(2,"%c",infs->map[i][j]);
			j++;
		}
		ft_fprintf(2,"\n");
		i++;
	}
	i = 0;
	ft_fprintf(2,"tet touch one a (%d,%d)\n",y,x);
	while (i < infs->teth)
	{
		j = 0;
		while (j < infs->tetw)
		{
			ft_fprintf(2,"%c",infs->tet[i][j]);
			j++;
		}
		ft_fprintf(2,"\n");
		i++;
	}
	i = 0;
	ft_fprintf(2,"map sur tet a (%d,%d)\n",y,x);
	while (i < infs->teth)
	{
		j = 0;
		while (j < infs->tetw)
		{
			ft_fprintf(2,"%c",(infs->map)[y + i][x + j]);
			j++;
		}
		ft_fprintf(2,"\n");
		i++;
	}
}
