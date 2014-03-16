/*
** main.c for rtv in /home/chapui_s/rendu/MUL_2013_rtv1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Mar 10 00:02:05 2014 chapui_s
** Last update Sun Mar 16 12:15:15 2014 chapui_s
*/

#include "rtv.h"

int		prepare_shadow_sphere(t_points *pts,
				      t_inter *inter,
				      t_spot *spot)
{
  t_points	points_shadow;

  points_shadow.x_eye = inter->sphere_point_x;
  points_shadow.y_eye = inter->sphere_point_y;
  points_shadow.z_eye = inter->sphere_point_z;
  points_shadow.angle_x_eye = pts->angle_x_eye;
  points_shadow.angle_y_eye = pts->angle_y_eye;
  points_shadow.angle_z_eye = pts->angle_z_eye;
  points_shadow.vect_x = spot->vect_l_x;
  points_shadow.vect_y = spot->vect_l_y;
  points_shadow.vect_z = spot->vect_l_z;
  if (is_shadow_with_cone(pts, &points_shadow) == 1
      || is_shadow_with_cylindre(pts, &points_shadow) == 1)
    return (1);
  return (0);
}

int		prepare_shadow_cone(t_points *pts,
				    t_inter *inter,
				    t_spot *spot)
{
  t_points	points_shadow;

  points_shadow.x_eye = inter->cone_point_x;
  points_shadow.y_eye = inter->cone_point_y;
  points_shadow.z_eye = inter->cone_point_z;
  points_shadow.angle_x_eye = pts->angle_x_eye;
  points_shadow.angle_y_eye = pts->angle_y_eye;
  points_shadow.angle_z_eye = pts->angle_z_eye;
  points_shadow.vect_x = spot->vect_l_x;
  points_shadow.vect_y = spot->vect_l_y;
  points_shadow.vect_z = spot->vect_l_z;
  if (is_shadow_with_sphere(pts, &points_shadow) == 1
      || is_shadow_with_cylindre(pts, &points_shadow) == 1)
    return (1);
  return (0);
}

int		prepare_shadow_cylindre(t_points *pts,
					t_inter *inter,
					t_spot *spot)
{
  t_points	points_shadow;

  points_shadow.x_eye = inter->cylindre_point_x;
  points_shadow.y_eye = inter->cylindre_point_y;
  points_shadow.z_eye = inter->cylindre_point_z;
  points_shadow.angle_x_eye = pts->angle_x_eye;
  points_shadow.angle_y_eye = pts->angle_y_eye;
  points_shadow.angle_z_eye = pts->angle_z_eye;
  points_shadow.vect_x = spot->vect_l_x;
  points_shadow.vect_y = spot->vect_l_y;
  points_shadow.vect_z = spot->vect_l_z;
  if (is_shadow_with_sphere(pts, &points_shadow) == 1
      || is_shadow_with_cone(pts, &points_shadow) == 1)
    return (1);
  return (0);
}

int		prepare_shadow_plan(t_points *pts,
				    t_inter *inter,
				    t_spot *spot)
{
  t_points	points_shadow;

  points_shadow.x_eye = inter->plan_point_x;
  points_shadow.y_eye = inter->plan_point_y;
  points_shadow.z_eye = inter->plan_point_z;
  points_shadow.angle_x_eye = pts->angle_x_eye;
  points_shadow.angle_y_eye = pts->angle_y_eye;
  points_shadow.angle_z_eye = pts->angle_z_eye;
  points_shadow.vect_x = spot->vect_l_x;
  points_shadow.vect_y = spot->vect_l_y;
  points_shadow.vect_z = spot->vect_l_z;
  if (is_shadow_with_sphere(pts, &points_shadow) == 1
      || is_shadow_with_cone(pts, &points_shadow) == 1
      || is_shadow_with_cylindre(pts, &points_shadow) == 1)
    return (1);
  return (0);
}
