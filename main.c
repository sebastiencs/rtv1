/*
** main.c for rtv in /home/chapui_s/rendu/MUL_2013_rtv1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Mar 10 00:02:05 2014 chapui_s
** Last update Sun Mar 16 13:12:37 2014 chapui_s
*/

#include <math.h>
#include <stdlib.h>
#include "mlx.h"
#include "rtv.h"

static t_infos_mlx	*init_infos_mlx(void)
{
  t_infos_mlx		*infos_mlx;

  if ((infos_mlx = (t_infos_mlx*)malloc(sizeof(*infos_mlx))) == NULL)
    return (puterror_null(ALLOC_ERROR));
  if ((infos_mlx->mlx_ptr = mlx_init()) == NULL)
    return (puterror_null(MLX_ERROR));
  if ((infos_mlx->win_ptr = mlx_new_window(infos_mlx->mlx_ptr,
					   WIDTH, HEIGHT,
					   WINDOW_TITLE)) == NULL)
    return (puterror_null(MLX_ERROR));
  if ((infos_mlx->img = mlx_new_image(infos_mlx->mlx_ptr,
				      WIDTH, HEIGHT)) == NULL)
    return (puterror_null(MLX_ERROR));
  infos_mlx->data = mlx_get_data_addr(infos_mlx->img,
				      &(infos_mlx->bpp),
				      &(infos_mlx->sizeline),
				      &(infos_mlx->endian));
  return (infos_mlx);
}

static unsigned int	calc_img(t_points *points, t_spot *spot)
{
  t_inter		inter;
  t_eye_virt		virt;

  sphere(points, &inter, &virt, 0);
  plan(points, &inter, &virt);
  cone(points, &inter, &virt);
  cylindre(points, &inter, &virt);
  return (get_color_pixel(&inter, spot, points));
}

static int	make_graph(t_infos_mlx *infos_mlx,
			   t_points *points,
			   t_spot *spot)
{
  int		x;
  int		y;
  double	color;

  x = 0;
  while (x < WIDTH)
  {
    y = 0;
    while (y < HEIGHT)
    {
      init_eye_spot(x, y, points, spot);
      color = calc_img(points, spot);
      my_pixel_put_to_image(x, y, color, infos_mlx);
      y += 1;
    }
    mlx_put_image_to_window(infos_mlx->mlx_ptr, infos_mlx->win_ptr,
			    infos_mlx->img, 0, 0);
    x += 1;
  }
  return (0);
}

static void	init_objs(t_points *points)
{
  init_sphere(points);
  init_cone(points);
  init_plan(points);
  init_cylindre(points);
}

int		main(void)
{
  t_infos_mlx	*infos_mlx;
  t_points	points;
  t_spot	spot;

  if ((infos_mlx = init_infos_mlx()) == NULL)
    return (-1);
  init_objs(&points);
  make_graph(infos_mlx, &points, &spot);
  mlx_key_hook(infos_mlx->win_ptr, manage_key, infos_mlx);
  mlx_expose_hook(infos_mlx->win_ptr, manage_expose, infos_mlx);
  mlx_loop(infos_mlx->mlx_ptr);
  return (0);
}
