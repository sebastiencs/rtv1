/*
** shadow.c for rtv in /home/chapui_s/travaux/MUL_2013_rtv1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Sat Mar 15 18:16:43 2014 chapui_s
** Last update Sat Mar 15 18:54:36 2014 chapui_s
*/

#include "rtv.h"

int		shadow(t_points *pts, t_inter *inter, t_spot *spot, int obj)
{
  int		is_obj;

  is_obj = 0;
  if (obj == SPHERE)
    is_obj = prepare_shadow_sphere(pts, inter, spot);
  else if (obj == PLAN)
    is_obj = prepare_shadow_plan(pts, inter, spot);
  else if (obj == CONE)
    is_obj = prepare_shadow_cone(pts, inter, spot);
  else if (obj == CYLINDRE)
    is_obj = prepare_shadow_cylindre(pts, inter, spot);
  return (is_obj);
}
