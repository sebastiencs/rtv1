/*
** cylindre.c for rtv in /home/chapui_s/travaux/MUL_2013_rtv1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Fri Mar 14 19:50:49 2014 chapui_s
** Last update Sun Mar 16 13:01:35 2014 chapui_s
*/

#include <math.h>
#include "rtv.h"

static void	get_eye_virt_cylindre(t_points *pts, t_eye_virt *vrt)
{
  vrt->x_eye = pts->x_eye - pts->x_cylindre;
  vrt->y_eye = pts->y_eye - pts->y_cylindre;
  vrt->z_eye = pts->z_eye - pts->z_cylindre;
  rotate_x(&(vrt->x_eye), &(vrt->y_eye), &(vrt->z_eye),
	   -(pts->angle_x_cylindre));
  rotate_y(&(vrt->x_eye), &(vrt->y_eye), &(vrt->z_eye),
	   -(pts->angle_y_cylindre));
  rotate_z(&(vrt->x_eye), &(vrt->y_eye), &(vrt->z_eye),
	   -(pts->angle_z_cylindre));
  vrt->vect_x = pts->vect_x;
  vrt->vect_y = pts->vect_y;
  vrt->vect_z = pts->vect_z;
  rotate_x(&(vrt->vect_x), &(vrt->vect_y), &(vrt->vect_z),
	   -(pts->angle_x_cylindre));
  rotate_y(&(vrt->vect_x), &(vrt->vect_y), &(vrt->vect_z),
	   -(pts->angle_y_cylindre));
  rotate_z(&(vrt->vect_x), &(vrt->vect_y), &(vrt->vect_z),
	   -(pts->angle_z_cylindre));
}

static int	apply_characteristics_cylindre(t_inter *inter,
					       t_points *pts,
					       double *cylindre)
{
  inter->cylindre_point_x = pts->x_eye + *cylindre * pts->vect_x;
  inter->cylindre_point_y = pts->y_eye + *cylindre * pts->vect_y;
  inter->cylindre_point_z = pts->z_eye + *cylindre * pts->vect_z;
  inter->cylindre_normal_x = inter->cylindre_point_x - pts->x_cylindre;
  inter->cylindre_normal_y = inter->cylindre_point_y - pts->y_cylindre;
  inter->cylindre_normal_z = 0;
  return (0);
}

static void	get_inter_cylindre(t_inter *inter,
				   double delta,
				   double b,
				   double a)
{
  if (delta >= 0)
  {
    inter->cylindre_one = (-b - sqrt(delta)) / (2.0 * a);
    inter->cylindre_two = inter->cylindre_one;
  }
  if (delta > 0)
    inter->cylindre_two = (-b + sqrt(delta)) / (2.0 * a);
  if (inter->cylindre_two < inter->cylindre_one || inter->cylindre_one < 0)
    inter->cylindre_one = inter->cylindre_two;
}

double		cylindre(t_points *pts,
			 t_inter *inter,
			 t_eye_virt *vrt)
{
  double	delta;
  double	a;
  double	b;
  double	c;

  get_eye_virt_cylindre(pts, vrt);
  a = (vrt->vect_x * vrt->vect_x) + (vrt->vect_y * vrt->vect_y);
  b = (2.0 * vrt->x_eye * vrt->vect_x)
    + (2.0 * vrt->y_eye * vrt->vect_y);
  c = (vrt->x_eye * vrt->x_eye) + (vrt->y_eye * vrt->y_eye)
    - (pts->rayon_cylindre * pts->rayon_cylindre);
  inter->cylindre_one = -1;
  inter->cylindre_two = -1;
  if ((delta = (b * b) - (4.0 * a * c)) < 0)
    return (-1);
  get_inter_cylindre(inter, delta, b, a);
  apply_characteristics_cylindre(inter, pts, &(inter->cylindre_one));
  return (inter->cylindre_one);
}
