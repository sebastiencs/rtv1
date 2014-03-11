/*
** rotate.c for rtv in /home/chapui_s/rendu/MUL_2013_rtv1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Mar 10 22:55:21 2014 chapui_s
** Last update Tue Mar 11 00:01:28 2014 chapui_s
*/

#include <math.h>
#include "rtv.h"

void		rotate_z(t_points *pts, double angle)
{
  double	x_tmp;
  double	y_tmp;

  x_tmp = pts->vect_x;
  y_tmp = pts->vect_y;
  pts->vect_x = x_tmp * cos(angle) - y_tmp * sin(angle);
  pts->vect_y = x_tmp * sin(angle) + y_tmp * cos(angle);
}

void		rotate_x(t_points *pts, double angle)
{
  double	y_tmp;
  double	z_tmp;

  y_tmp = pts->vect_y;
  z_tmp = pts->vect_z;
  pts->vect_y = y_tmp * cos(angle) - z_tmp * sin(angle);
  pts->vect_z = y_tmp * sin(angle) + z_tmp * cos(angle);
}

void		rotate_y(t_points *pts, double angle)
{
  double	x_tmp;
  double	z_tmp;

  x_tmp = pts->vect_x;
  z_tmp = pts->vect_z;
  pts->vect_z = z_tmp * cos(angle) - x_tmp * sin(angle);
  pts->vect_x = z_tmp * sin(angle) + x_tmp * cos(angle);
}
