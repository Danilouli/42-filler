/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_nums.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:38:50 by dsaadia           #+#    #+#             */
/*   Updated: 2018/03/07 17:39:10 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max_nums(int arg_count, ...)
{
	int		i;
	int		max;
	int		a;
	va_list ap;

	i = 1;
	va_start(ap, arg_count);
	max = va_arg(ap, int);
	while (i < arg_count)
	{
		if ((a = va_arg(ap, int)) > max)
			max = a;
		i++;
	}
	va_end(ap);
	return (max);
}
