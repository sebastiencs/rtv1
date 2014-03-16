/*
** is_shadow.c for rtv in /home/chapui_s/travaux/MUL_2013_rtv1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Sat Mar 15 17:37:15 2014 chapui_s
** Last update Sat Mar 15 17:47:00 2014 chapui_s
*/

#include "rtv.h"

int		is_shadow_with_sphere(t_points *pts, t_points *pts_shadow)
{
  double	k;
  t_inter	inter_shadow;
  t_eye_virt	eye_vrt_shadow;

  pts_shadow->x_sphere = pts->x_sphere;
  pts_shadow->y_sphere = pts->y_sphere;
  pts_shadow->z_sphere = pts->z_sphere;
  pts_shadow->angle_x_sphere = pts->angle_x_sphere;
  pts_shadow->angle_y_sphere = pts->angle_y_sphere;
  pts_shadow->angle_z_sphere = pts->angle_z_sphere;
  pts_shadow->radius_sphere = pts->radius_sphere;
  k = sphere(pts_shadow, &inter_shadow, &eye_vrt_shadow, 0);
  if (k > 0 && k < 1.0001)
    return (1);
  return (0);
}

int		is_shadow_with_cone(t_points *pts, t_points *pts_shadow)
{
  double	k;
  t_inter	inter_shadow;
  t_eye_virt	eye_vrt_shadow;

  pts_shadow->x_cone = pts->x_cone;
  pts_shadow->y_cone = pts->y_cone;
  pts_shadow->z_cone = pts->z_cone;
  pts_shadow->angle_x_cone = pts->angle_x_cone;
  pts_shadow->angle_y_cone = pts->angle_y_cone;
  pts_shadow->angle_z_cone = pts->angle_z_cone;
  pts_shadow->angle_cone = pts->angle_cone;
  k = cone(pts_shadow, &inter_shadow, &eye_vrt_shadow);
  if (k > 0 && k < 1.0001)
    return (1);
  return (0);
}

int		is_shadow_with_cylindre(t_points *pts, t_points *pts_shadow)
{
  double	k;
  t_inter	inter_shadow;
  t_eye_virt	eye_vrt_shadow;

  pts_shadow->x_cylindre = pts->x_cylindre;
  pts_shadow->y_cylindre = pts->y_cylindre;
  pts_shadow->z_cylindre = pts->z_cylindre;
  pts_shadow->angle_x_cylindre = pts->angle_x_cylindre;
  pts_shadow->angle_y_cylindre = pts->angle_y_cylindre;
  pts_shadow->angle_z_cylindre = pts->angle_z_cylindre;
  pts_shadow->rayon_cylindre = pts->rayon_cylindre;
  k = cylindre(pts_shadow, &inter_shadow, &eye_vrt_shadow);
  if (k > 0 && k < 1.0001)
    return (1);
  return (0);
}
