/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:20:47 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/06 12:13:19 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/includes/libft.h"

typedef struct s_infs
{
  int   pnum;
  int   maph;
  int   mapw;
  char  mark;
  char  enmark;
  char  **map;
  int   teth;
  int   tetw;
  int   locx;
  int   locy;
  char  **tet;
}             t_infs;
