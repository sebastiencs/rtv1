/*
** main.c for rtv in /home/chapui_s/rendu/MUL_2013_rtv1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Mar 10 00:02:05 2014 chapui_s
** Last update Tue Mar 11 00:02:04 2014 chapui_s
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

unsigned int	get_color_obj(t_inter *inter)
{
  if (inter->sphere_one == -1 && inter->sphere_two == -1
      && inter->plan == -1)
    return (0xFFFFFF);
  if (inter->sphere_one != -1 && inter->plan == -1)
    return (0x0000FF);
  if (inter->plan != -1 && inter->sphere_one == -1)
    return (0xFF0000);
  if (inter->plan < inter->sphere_one && inter->plan < inter->sphere_two)
    return (0xFF0000);
  else
    return (0x0000FF);
}

unsigned int	calc_img(int x, int y, t_points *points)
{
  t_inter	inter;

  points->x_eye = -300;
  points->y_eye = 0;
  points->z_eye = 100;

  points->vect_x = DIST_EYE_TO_IMG;
  points->vect_y = (WIDTH / 2) - x;
  points->vect_z = (HEIGHT / 2) - y;

  rotate_z(points, DEG_TO_RAD(40));

  sphere(points, &inter);
  plan(points, &inter);
  return (get_color_obj(&inter));
}

int		make_graph(t_infos_mlx *infos_mlx, t_points *points)
{
  int		x;
  int		y;
  int		color;

  x = 0;
  my_putstr("loading... ");
  while (x < WIDTH)
  {
    y = 0;
    while (y < HEIGHT)
    {
      color = calc_img(x, y, points);
      my_pixel_put_to_image(x, y, color, infos_mlx);
      y += 1;
    }
    x += 1;
  }
  my_putstr("\n");
  return (0);
}

int		main(void)
{
  t_infos_mlx	*infos_mlx;
  t_points	points;

  if ((infos_mlx = init_infos_mlx()) == NULL)
    return (-1);
  make_graph(infos_mlx, &points);
  mlx_key_hook(infos_mlx->win_ptr, manage_key, infos_mlx);
  mlx_expose_hook(infos_mlx->win_ptr, manage_expose, infos_mlx);
  mlx_loop(infos_mlx->mlx_ptr);
  return (0);
}
