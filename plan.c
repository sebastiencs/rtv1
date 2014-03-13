/*
** plan.c for rtv in /home/chapui_s/rendu/MUL_2013_rtv1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Mar 10 20:13:30 2014 chapui_s
** Last update Wed Mar 12 23:05:51 2014 chapui_s
*/

#include "rtv.h"

void		get_eye_virt_plan(t_points *pts, t_eye_virt *vrt)
{
  vrt->x_eye = pts->x_eye - pts->x_plan;
  vrt->y_eye = pts->y_eye - pts->y_plan;
  vrt->z_eye = pts->z_eye - pts->z_plan;
  rotate_x(&(vrt->x_eye), &(vrt->y_eye), &(vrt->z_eye),
	   -(pts->angle_x_plan));
  rotate_y(&(vrt->x_eye), &(vrt->y_eye), &(vrt->z_eye),
	   -(pts->angle_y_plan));
  rotate_z(&(vrt->x_eye), &(vrt->y_eye), &(vrt->z_eye),
	   -(pts->angle_z_plan));
  vrt->vect_x = pts->vect_x;
  vrt->vect_y = pts->vect_y;
  vrt->vect_z = pts->vect_z;
  rotate_x(&(vrt->vect_x), &(vrt->vect_y), &(vrt->vect_z),
	   -(pts->angle_x_plan));
  rotate_y(&(vrt->vect_x), &(vrt->vect_y), &(vrt->vect_z),
	   -(pts->angle_y_plan));
  rotate_z(&(vrt->vect_x), &(vrt->vect_y), &(vrt->vect_z),
	   -(pts->angle_z_plan));
}

double		plan(t_points *pts, t_inter *inter, t_eye_virt *vrt)
{
  double	k;

  get_eye_virt_plan(pts, vrt);
  inter->plan = -1;
  if (vrt->vect_z == 0)
    return (0);
  k = ((double)(vrt->z_eye) / (double)(vrt->vect_z));
  k = -k;
  if (k < 0)
    return (0);
  inter->plan = k;
  return (0);
}
