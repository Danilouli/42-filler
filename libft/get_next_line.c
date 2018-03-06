/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 18:04:26 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/03 11:16:27 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	when_read_over(char **line, char **kp)
{
	char *tmp;
	char *pt;
	char next;

	if (*kp && (pt = ft_strchr(*kp, '\n')))
	{
		if ((next = *(pt + 1)))
			if (!(tmp = ft_strdup(pt + 1)))
				return (-1);
		*pt = 0;
		if (!(*line = ft_strdup(*kp)))
			return (-1);
		ft_strdel(kp);
		*kp = (next) ? tmp : 0;
		return (1);
	}
	else if (**kp != 0)
	{
		if (!(*line = ft_strdup(*kp)))
			return (-1);
		**kp = 0;
		return (1);
	}
	else
		return (0);
}

static int	read_when_line(char **line, char **kp, char *pt)
{
	char	*tmp;
	char	next;

	if ((next = *(pt + 1)))
	{
		if (!(tmp = ft_strdup(pt + 1)))
			return (-1);
	}
	*pt = 0;
	if (!(*line = ft_strdup(*kp)))
		return (-1);
	ft_strdel(kp);
	if (next)
		*kp = tmp;
	else
		*kp = 0;
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	char		*b;
	static char *kp[256] = {"\0"};
	char		*tmp;
	char		*pt;
	int			r;

	if (!(b = (char*)malloc(BUFF_SIZE + 1)) || fd < 0 || (read(fd, "", 0)) < 0)
		return (-1);
	kp[fd] = (kp[fd] == 0 || kp[fd][0] == 0) ? ft_strdup("\0") : kp[fd];
	while ((r = read(fd, b, BUFF_SIZE)))
	{
		b[r] = 0;
		tmp = kp[fd];
		if (!(kp[fd] = ft_strjoin(kp[fd], b)))
			return (-1);
		ft_strdel(&tmp);
		ft_strdel(&b);
		if ((pt = ft_strchr(kp[fd], '\n')))
			return (read_when_line(line, &(kp[fd]), pt));
		if (!(b = (char*)malloc(BUFF_SIZE + 1)))
			return (-1);
	}
	ft_strdel(&b);
	return (when_read_over(line, &(kp[fd])));
}
