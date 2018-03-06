/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intarr_ctint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:13:34 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/03 11:11:33 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intarr_ctint(int *tab, int len, int to_count)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (i < len)
	{
		if (tab[i] == to_count)
			res++;
		i++;
	}
	return (res);
}
