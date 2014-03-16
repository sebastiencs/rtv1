/*
** cone.c for rtv in /home/chapui_s/travaux/MUL_2013_rtv1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Fri Mar 14 11:10:03 2014 chapui_s
** Last update Sun Mar 16 13:10:11 2014 chapui_s
*/

#include <math.h>
#include "rtv.h"

static void	get_eye_virt_cone(t_points *pts, t_eye_virt *vrt)
{
  vrt->x_eye = pts->x_eye - pts->x_cone;
  vrt->y_eye = pts->y_eye - pts->y_cone;
  vrt->z_eye = pts->z_eye - pts->z_cone;
  rotate_x(&(vrt->x_eye), &(vrt->y_eye), &(vrt->z_eye),
	   -(pts->angle_x_cone));
  rotate_y(&(vrt->x_eye), &(vrt->y_eye), &(vrt->z_eye),
	   -(pts->angle_y_cone));
  rotate_z(&(vrt->x_eye), &(vrt->y_eye), &(vrt->z_eye),
	   -(pts->angle_z_cone));
  vrt->vect_x = pts->vect_x;
  vrt->vect_y = pts->vect_y;
  vrt->vect_z = pts->vect_z;
  rotate_x(&(vrt->vect_x), &(vrt->vect_y), &(vrt->vect_z),
	   -(pts->angle_x_cone));
  rotate_y(&(vrt->vect_x), &(vrt->vect_y), &(vrt->vect_z),
	   -(pts->angle_y_cone));
  rotate_z(&(vrt->vect_x), &(vrt->vect_y), &(vrt->vect_z),
	   -(pts->angle_z_cone));
}

static void	apply_characteristics_cone(t_inter *inter,
					   t_points *pts,
					   double *cone)
{
  inter->cone_point_x = pts->x_eye + *cone * pts->vect_x;
  inter->cone_point_y = pts->y_eye + *cone * pts->vect_y;
  inter->cone_point_z = pts->z_eye + *cone * pts->vect_z;
  inter->cone_normal_x = inter->cone_point_x - pts->x_cone;
  inter->cone_normal_y = inter->cone_point_y - pts->y_cone;
  inter->cone_normal_z = -(tan(pts->angle_cone * M_PI / 180))
    * inter->cone_point_z - pts->z_cone;
}

static void	get_inter_cone(t_inter *inter,
			       double delta,
			       double b,
			       double a)
{
  if (delta >= 0)
  {
    inter->cone_one = (-b - sqrt(delta)) / (2.0 * a);
    inter->cone_two = inter->cone_one;
  }
  if (delta > 0)
    inter->cone_two = (-b + sqrt(delta)) / (2.0 * a);
  if (inter->cone_two > 0 && inter->cone_two < inter->cone_one)
    inter->cone_one = inter->cone_two;
}

double		cone(t_points *pts,
		     t_inter *inter,
		     t_eye_virt *vrt)
{
  double	a;
  double	b;
  double	c;
  double	tmp;
  double	delta;

  get_eye_virt_cone(pts, vrt);
  inter->cone_one = -1;
  inter->cone_two = -1;
  tmp = tan((pts->angle_cone * (M_PI / 180)));
  a = (vrt->vect_x * vrt->vect_x) + (vrt->vect_y * vrt->vect_y)
    - ((vrt->vect_z * vrt->vect_z) * tmp);
  b = (2.0 * vrt->x_eye * vrt->vect_x)
    + (2.0 * vrt->y_eye * vrt->vect_y)
    - ((2.0 * vrt->z_eye * vrt->vect_z) * tmp);
  c = (vrt->x_eye * vrt->x_eye) + (vrt->y_eye * vrt->y_eye)
    - ((vrt->z_eye * vrt->z_eye) * tmp);
  if ((delta = (b * b) - (4.0 * a * c)) < 0)
    return (-1);
  get_inter_cone(inter, delta, b, a);
  apply_characteristics_cone(inter, pts, &(inter->cone_one));
  if (vrt->z_eye + inter->cone_one * vrt->vect_z < 0)
    inter->cone_one = -1;
  return (inter->cone_one);
}
