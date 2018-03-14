/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoindel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 18:59:31 by dsaadia           #+#    #+#             */
/*   Updated: 2018/03/14 17:27:03 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoindel(char **s1, char **s2, int whodel)
{
	char	*str;

	if (!(*s1) && !(*s2))
		return (NULL);
	if (!(*s1))
		return (ft_strdup(*s2));
	if (!(*s2))
		return (ft_strdup((*s1)));
	if (!(str = ft_strnew(ft_strlen(*s1) + ft_strlen(*s2))))
		return (NULL);
	ft_strcpy(str, *s1);
	ft_strcat(str, *s2);
	if (whodel == 1 || whodel == 3)
		ft_strdel(s1);
	if (whodel == 2 || whodel == 3)
		ft_strdel(s2);
	return (str);
}
