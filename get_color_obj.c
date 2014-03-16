/*
** get_color_obj.c for rtv in /home/chapui_s/travaux/MUL_2013_rtv1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Fri Mar 14 20:53:42 2014 chapui_s
** Last update Sun Mar 16 11:52:34 2014 chapui_s
*/

#include "rtv.h"

unsigned int	get_color_pixel(t_inter *inter, t_spot *spot, t_points *pts)
{
  if (inter->cone_one > 0
      && (inter->cone_one < inter->plan || inter->plan == -1)
      && (inter->cone_one < inter->sphere_one || inter->sphere_one == -1)
      && (inter->cone_one < inter->cylindre_one || inter->cylindre_one == -1))
    return (luminosity(pts, inter, spot, CONE));
  if (inter->sphere_one > 0
      && (inter->sphere_one < inter->plan || inter->plan == -1)
      && (inter->sphere_one < inter->cone_one || inter->cone_one == -1)
      && (inter->sphere_one < inter->cylindre_one
	  || inter->cylindre_one == -1))
    return (luminosity(pts, inter, spot, SPHERE));
  if (inter->plan > 0
      && (inter->plan < inter->sphere_one || inter->sphere_one < 0)
      && (inter->plan < inter->cone_one || inter->cone_one < 0)
      && (inter->plan < inter->cylindre_one || inter->cylindre_one < 0))
    return (luminosity(pts, inter, spot, PLAN));
  if (inter->cylindre_one > 0
      && (inter->cylindre_one < inter->sphere_one || inter->sphere_one == -1)
      && (inter->cylindre_one < inter->cone_one || inter->cone_one == -1)
      && (inter->cylindre_one < inter->plan || inter->plan == -1))
    return (luminosity(pts, inter, spot, CYLINDRE));
  return (0);
}

unsigned int	get_color_obj(t_points *pts, int obj)
{
  unsigned int	color_obj;

  if (obj == SPHERE)
    color_obj = pts->color_sphere;
  else if (obj == PLAN)
    color_obj = pts->color_plan;
  else if (obj == CONE)
    color_obj = pts->color_cone;
  else if (obj == CYLINDRE)
    color_obj = pts->color_cylindre;
  return (color_obj);
}
