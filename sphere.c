/*
** sphere.c for rtv in /home/chapui_s/rendu/MUL_2013_rtv1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Mar 10 19:32:25 2014 chapui_s
** Last update Thu Mar 13 20:22:33 2014 chapui_s
*/

#include <math.h>
#include "rtv.h"

void		get_eye_virt(t_points *pts, t_eye_virt *vrt, int a)
{
  vrt->x_eye = pts->x_eye - pts->x_sphere;
  vrt->y_eye = pts->y_eye - pts->y_sphere;
  vrt->z_eye = pts->z_eye - pts->z_sphere;
  rotate_x(&(vrt->x_eye), &(vrt->y_eye), &(vrt->z_eye),
	   -(pts->angle_x_sphere));
  rotate_y(&(vrt->x_eye), &(vrt->y_eye), &(vrt->z_eye),
	   -(pts->angle_y_sphere));
  rotate_z(&(vrt->x_eye), &(vrt->y_eye), &(vrt->z_eye),
	   -(pts->angle_z_sphere));
  vrt->vect_x = pts->vect_x;
  vrt->vect_y = pts->vect_y;
  vrt->vect_z = pts->vect_z;
  rotate_x(&(vrt->vect_x), &(vrt->vect_y), &(vrt->vect_z),
  	   -(pts->angle_x_sphere));
  rotate_y(&(vrt->vect_x), &(vrt->vect_y), &(vrt->vect_z),
  	   -(pts->angle_y_sphere));
  rotate_z(&(vrt->vect_x), &(vrt->vect_y), &(vrt->vect_z),
  	   -(pts->angle_z_sphere));
}

void		apply_charactestics(t_inter *inter,
				    t_points *pts,
				    double *sphere)
{
  inter->sphere_point_x = pts->x_eye + *sphere * pts->vect_x;
  inter->sphere_point_y = pts->y_eye + *sphere * pts->vect_y;
  inter->sphere_point_z = pts->z_eye + *sphere * pts->vect_z;
  inter->sphere_normal_x = inter->sphere_point_x - pts->x_sphere;
  inter->sphere_normal_y = inter->sphere_point_y - pts->y_sphere;
  inter->sphere_normal_z = inter->sphere_point_z - pts->z_sphere;
}

void		sphere(t_points *pts,
		       t_inter *inter,
		       t_eye_virt *vrt,
		       double delta)
{
  double	a;
  double	b;
  double	c;

  get_eye_virt(pts, vrt, 0);
  a = (double)((vrt->vect_x * vrt->vect_x) + (vrt->vect_y * vrt->vect_y)
	       + (vrt->vect_z * vrt->vect_z));
  b = ((double)(vrt->x_eye * vrt->vect_x) + ((double)vrt->y_eye * vrt->vect_y)
       + ((double)vrt->z_eye * vrt->vect_z)) * 2.0;
  c = (double)((vrt->x_eye * vrt->x_eye) + (vrt->y_eye * vrt->y_eye)
	       + (vrt->z_eye * vrt->z_eye))
    - (double)(pts->radius_sphere * pts->radius_sphere);
  delta = (b * b) - (4.0 * a * c);
  inter->sphere_one = -1;
  inter->sphere_two = -1;
  if (delta >= 0)
  {
    inter->sphere_one = (-b - sqrt(delta)) / (2.0 * a);
    apply_charactestics(inter, pts, &(inter->sphere_one));
    inter->sphere_two = inter->sphere_one;
  }
  if (delta > 0)
    inter->sphere_two = (-b + sqrt(delta)) / (2.0 * a);
  if (inter->sphere_two < inter->sphere_one)
    apply_charactestics(inter, pts, &(inter->sphere_two));
}
