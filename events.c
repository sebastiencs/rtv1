/*
** events.c for rtv in /home/chapui_s/rendu/MUL_2013_rtv1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Mar 10 18:32:03 2014 chapui_s
** Last update Mon Mar 10 18:38:35 2014 chapui_s
*/

#include <stdlib.h>
#include "mlx.h"
#include "rtv.h"

int		manage_expose(void *param)
{
  t_infos_mlx	*infos_mlx;

  infos_mlx = param;
  mlx_put_image_to_window(infos_mlx->mlx_ptr,
                          infos_mlx->win_ptr,
                          infos_mlx->img, 0, 0);
  return (0);
}

int		manage_key(int keycode, t_infos_mlx *infos_mlx)
{
  (void)infos_mlx;
  if (keycode == 65307)
    exit(EXIT_SUCCESS);
  return (0);
}
