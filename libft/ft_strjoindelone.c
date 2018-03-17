/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoindelone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 17:27:27 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/17 21:20:40 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoindelone(char **s1, char *s2)
{
	char	*str;

	if (!(*s1) && !s2)
		return (NULL);
	if (!(*s1))
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup((*s1)));
	if (!(str = ft_strnew(ft_strlen(*s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(str, *s1);
	ft_strcat(str, s2);
	ft_strdel(s1);
	return (str);
}
