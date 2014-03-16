/*
** luminosity.c for rtv in /home/chapui_s/travaux/MUL_2013_rtv1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Sat Mar 15 18:14:52 2014 chapui_s
** Last update Sat Mar 15 20:28:06 2014 chapui_s
*/

#include "rtv.h"

unsigned int	luminosity(t_points *pts,
			   t_inter *inter,
			   t_spot *spot,
			   int obj)
{
  double	cos_a;
  unsigned int	color;
  unsigned int	r;
  unsigned int	g;
  unsigned int	b;

  if ((cos_a = get_cos_a(spot, inter, obj)) < 0)
    return (0);
  color = get_color_obj(pts, obj);
  r = (color / 0x10000) * cos_a;
  color = color % 0x10000;
  g = (color / 0x100) * cos_a;
  color = color % 0x100;
  b = color * cos_a;
  color = (r * 0x10000) + (g * 0x100) + b;
  if (shadow(pts, inter, spot, obj) == 1)
    return (0);
  return (color);
}
