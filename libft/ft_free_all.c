/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:15:22 by dsaadia           #+#    #+#             */
/*   Updated: 2018/03/03 11:12:20 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free_all(int nbpt, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	va_start(ap, nbpt);
	while (i < nbpt)
	{
		free(va_arg(ap, void*));
		i++;
	}
	va_end(ap);
	return (1);
}
