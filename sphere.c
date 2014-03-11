/*
** sphere.c for rtv in /home/chapui_s/rendu/MUL_2013_rtv1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Mar 10 19:32:25 2014 chapui_s
** Last update Mon Mar 10 20:52:16 2014 chapui_s
*/

#include <math.h>
#include "rtv.h"

double		sphere(t_points *pts, t_inter *inter)
{
  double	delta;
  double	a;
  double	b;
  double	c;

  a = (double)((pts->vect_x * pts->vect_x)
	       + (pts->vect_y * pts->vect_y)
	       + (pts->vect_z * pts->vect_z));
  b = ((double)(pts->x_eye * pts->vect_x)
       + (double)(pts->y_eye * pts->vect_y)
       + (double)(pts->z_eye * pts->vect_z)) * 2.0;
  c = (double)((pts->x_eye * pts->x_eye)
	       + (pts->y_eye * pts->y_eye)
	       + (pts->z_eye * pts->z_eye)) - (100 * 100);
  delta = (b * b) - (4.0 * a * c);
  inter->sphere_one = -1;
  inter->sphere_two = -1;
  if (delta >= 0)
  {
    inter->sphere_one = (-b - sqrt(delta)) / (2.0 * a);
    inter->sphere_two = inter->sphere_one;
  }
  if (delta > 0)
    inter->sphere_two = (-b + sqrt(delta)) / (2.0 * a);
  return (0);
}
