/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:30:47 by dsaadia           #+#    #+#             */
/*   Updated: 2018/02/24 17:00:48 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_in_array(int to_find, int *tab, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (tab[i] == to_find)
			return (1);
		i++;
	}
	return (0);
}
