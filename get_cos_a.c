/*
** main.c for rtv in /home/chapui_s/rendu/MUL_2013_rtv1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Mar 10 00:02:05 2014 chapui_s
** Last update Sat Mar 15 20:15:25 2014 chapui_s
*/

#include <math.h>
#include "rtv.h"

double		get_cos_a_sphere(t_spot *spot, t_inter *inter)
{
  double	cos_a;
  double	prod_scal;

  spot->vect_l_x = spot->x_spot - inter->sphere_point_x;
  spot->vect_l_y = spot->y_spot - inter->sphere_point_y;
  spot->vect_l_z = spot->z_spot - inter->sphere_point_z;
  prod_scal = spot->vect_l_x * inter->sphere_normal_x;
  prod_scal += spot->vect_l_y * inter->sphere_normal_y;
  prod_scal += spot->vect_l_z * inter->sphere_normal_z;
  spot->norme_l = sqrt((spot->vect_l_x * spot->vect_l_x)
		       + (spot->vect_l_y * spot->vect_l_y)
		       + (spot->vect_l_z * spot->vect_l_z));
  spot->norme_obj = sqrt((inter->sphere_normal_x * inter->sphere_normal_x)
			 + (inter->sphere_normal_y * inter->sphere_normal_y)
			 + (inter->sphere_normal_z * inter->sphere_normal_z));
  cos_a = -1;
  if (spot->norme_l * spot->norme_obj != 0)
    cos_a = (prod_scal / (spot->norme_l * spot->norme_obj));
  return (cos_a);
}

double		get_cos_a_cone(t_spot *spot, t_inter *inter)
{
  double	cos_a;
  double	prod_scal;

  spot->vect_l_x = spot->x_spot - inter->cone_point_x;
  spot->vect_l_y = spot->y_spot - inter->cone_point_y;
  spot->vect_l_z = spot->z_spot - inter->cone_point_z;
  prod_scal = spot->vect_l_x * inter->cone_normal_x;
  prod_scal += spot->vect_l_y * inter->cone_normal_y;
  prod_scal += spot->vect_l_z * inter->cone_normal_z;
  spot->norme_l = sqrt((spot->vect_l_x * spot->vect_l_x)
		       + (spot->vect_l_y * spot->vect_l_y)
		       + (spot->vect_l_z * spot->vect_l_z));
  spot->norme_obj = sqrt((inter->cone_normal_x * inter->cone_normal_x)
			 + (inter->cone_normal_y * inter->cone_normal_y)
			 + (inter->cone_normal_z * inter->cone_normal_z));
  cos_a = -1;
  if (spot->norme_l * spot->norme_obj != 0)
    cos_a = (prod_scal / (spot->norme_l * spot->norme_obj));
  return (cos_a);
}

double		get_cos_a_cylindre(t_spot *spot, t_inter *inter)
{
  double	cos_a;
  double	prod_scal;

  spot->vect_l_x = spot->x_spot - inter->cylindre_point_x;
  spot->vect_l_y = spot->y_spot - inter->cylindre_point_y;
  spot->vect_l_z = spot->z_spot - inter->cylindre_point_z;
  prod_scal = spot->vect_l_x * inter->cylindre_normal_x;
  prod_scal += spot->vect_l_y * inter->cylindre_normal_y;
  prod_scal += spot->vect_l_z * inter->cylindre_normal_z;
  spot->norme_l = sqrt((spot->vect_l_x * spot->vect_l_x)
		       + (spot->vect_l_y * spot->vect_l_y)
		       + (spot->vect_l_z * spot->vect_l_z));
  spot->norme_obj = sqrt((inter->cylindre_normal_x * inter->cylindre_normal_x)
			 + (inter->cylindre_normal_y * inter->cylindre_normal_y)
			 + (inter->cylindre_normal_z * inter->cylindre_normal_z));
  cos_a = -1;
  if (spot->norme_l * spot->norme_obj != 0)
    cos_a = (prod_scal / (spot->norme_l * spot->norme_obj));
  return (cos_a);
}

double		get_cos_a_plan(t_spot *spot, t_inter *inter)
{
  double	cos_a;
  double	prod_scal;

  spot->vect_l_x = spot->x_spot - inter->plan_point_x;
  spot->vect_l_y = spot->y_spot - inter->plan_point_y;
  spot->vect_l_z = spot->z_spot - inter->plan_point_z;
  prod_scal = spot->vect_l_x * inter->plan_normal_x;
  prod_scal += spot->vect_l_y * inter->plan_normal_y;
  prod_scal += spot->vect_l_z * inter->plan_normal_z;
  spot->norme_l = sqrt((spot->vect_l_x * spot->vect_l_x)
		       + (spot->vect_l_y * spot->vect_l_y)
		       + (spot->vect_l_z * spot->vect_l_z));
  spot->norme_obj = sqrt((inter->plan_normal_x * inter->plan_normal_x)
			 + (inter->plan_normal_y * inter->plan_normal_y)
			 + (inter->plan_normal_z * inter->plan_normal_z));
  cos_a = -1;
  if (spot->norme_l * spot->norme_obj != 0)
    cos_a = (prod_scal / (spot->norme_l * spot->norme_obj));
  return (cos_a);
}

double		get_cos_a(t_spot *spot, t_inter *inter, int obj)
{
  double	cos_a;

  cos_a = -1;
  if (obj == SPHERE)
    cos_a = get_cos_a_sphere(spot, inter);
  else if (obj == PLAN)
    cos_a = get_cos_a_plan(spot, inter);
  else if (obj == CONE)
    cos_a = get_cos_a_cone(spot, inter);
  else if (obj == CYLINDRE)
    cos_a = get_cos_a_cylindre(spot, inter);
  return (cos_a);
}
