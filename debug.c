/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 21:01:38 by dsaadia           #+#    #+#             */
/*   Updated: 2018/03/06 21:02:09 by dsaadia          ###   ########.fr       */
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
