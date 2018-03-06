/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 01:33:30 by schmurz           #+#    #+#             */
/*   Updated: 2018/01/28 10:19:29 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	i;

	i = -1;
	if (s == 0)
		return (0);
	if (!(r = (char*)malloc(len + 1)))
		return (0);
	while (++i < len)
		r[i] = s[start + i];
	r[i] = 0;
	return (r);
}
