/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strtab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:03:32 by dsaadia           #+#    #+#             */
/*   Updated: 2018/03/09 11:59:18 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_strtab(char **strtab)
{
	int i;

	i = 0;
	while (strtab[i])
	{
		ft_strdel(&(strtab[i]));
		i++;
	}
	free(strtab);
}
