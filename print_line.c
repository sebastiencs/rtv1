/*
** print_line.c for rtv in /home/chapui_s/rendu/MUL_2013_rtv1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Mar 10 18:41:49 2014 chapui_s
** Last update Sun Mar 16 12:42:03 2014 chapui_s
*/

#include <stddef.h>
#include "mlx.h"
#include "rtv.h"

void		my_pixel_put_to_image(int x, int y,
				      unsigned int color,
				      t_infos_mlx *infos_mlx)
{
  void		*mlx_ptr;
  size_t	pixel_ptr;

  mlx_ptr = infos_mlx->mlx_ptr;
  if (y <= HEIGHT && y >= 0 && x >= 0 && x <= WIDTH)
  {
    pixel_ptr = ((WIDTH * y) + x) * (infos_mlx->bpp / 8);
    color = mlx_get_color_value(mlx_ptr, color);
    if (infos_mlx->endian == 0)
    {
      (infos_mlx->data + pixel_ptr)[2] = color >> 16;
      (infos_mlx->data + pixel_ptr)[1] = (color & 0x00FF00) >> 8;
      (infos_mlx->data + pixel_ptr)[0] = color & 0x0000FF;
    }
    else
    {
      (infos_mlx->data + pixel_ptr)[0] = color >> 16;
      (infos_mlx->data + pixel_ptr)[1] = (color & 0x00FF00) >> 8;
      (infos_mlx->data + pixel_ptr)[2] = color & 0x0000FF;
    }
  }
}
