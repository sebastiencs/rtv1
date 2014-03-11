/*
** plan.c for rtv in /home/chapui_s/rendu/MUL_2013_rtv1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Mar 10 20:13:30 2014 chapui_s
** Last update Mon Mar 10 21:13:08 2014 chapui_s
*/

#include "rtv.h"

double		plan(t_points *pts, t_inter *inter)
{
  double	k;

  inter->plan = -1;
  if (pts->vect_z == 0)
    return (0);
  k = ((double)(pts->z_eye) / (double)(pts->vect_z));
  k = -k;
  if (k < 0)
    return (0);
  inter->plan = k;
  return (0);
}
