/*
** main.c for rtv in /home/chapui_s/rendu/MUL_2013_rtv1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Mar 10 00:02:05 2014 chapui_s
** Last update Thu Mar 13 20:24:56 2014 chapui_s
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

unsigned int	luminosite(t_inter *inter)
{
  double	x_spot;
  double	y_spot;
  double	z_spot;
  double	vect_l_x;
  double	vect_l_y;
  double	vect_l_z;
  double	norme_l;
  double	norme_two;
  double	prod_scal;
  double	cos_a;
  unsigned int	r;
  unsigned int	g;
  unsigned int	b;
  unsigned int	color_final;
  unsigned int	color;

  x_spot = -300;
  y_spot = 500;
  z_spot = 500;

  vect_l_x = x_spot - inter->sphere_point_x;
  vect_l_y = y_spot - inter->sphere_point_y;
  vect_l_z = z_spot - inter->sphere_point_z;
  prod_scal = vect_l_x * inter->sphere_normal_x;
  prod_scal += vect_l_y * inter->sphere_normal_y;
  prod_scal += vect_l_z * inter->sphere_normal_z;
  //CHECK A CET ENDROIT
  norme_l = sqrt((vect_l_x * vect_l_x) + (vect_l_y * vect_l_y) + (vect_l_z * vect_l_z));
  norme_two = sqrt((inter->sphere_normal_x * inter->sphere_normal_x) + (inter->sphere_normal_y * inter->sphere_normal_y) + (inter->sphere_normal_z * inter->sphere_normal_z));
  cos_a = (prod_scal / (norme_l * norme_two));
  if (cos_a < 0)
    return (0x0000FF);

  /* color = 0x0000FF; */
  /* r = (color / 0x10000) * cos_a; */
  /* color = color % 0x10000; */
  /* g = (color / 0x100) * cos_a; */
  /* color = color % 0x100; */
  /* b = color * cos_a; */
  /* color_final = (r * 0x10000) + (g * 0x100) + b; */
  /* return (color_final); */
  r = 0x0 * cos_a;
  g = 0x0 * cos_a;
  b = 0xFF * cos_a;
  color_final = b;
  color_final += g << 8;
  color_final += r << 16;
  return (color_final);
  /* if (0x0000FF * cos_a > 0x0000FF) */
  /*   cos_a = 1; */
}

unsigned int	get_color_obj(t_inter *inter)
{
  if (inter->sphere_one == -1 && inter->sphere_two == -1
      && inter->plan == -1)
    return (0xFFFFFF);
  if (inter->sphere_one != -1 && inter->plan == -1)
    return (luminosite(inter));
  if (inter->plan != -1 && inter->sphere_one == -1)
    return (0xFF0000);
  if (inter->plan < inter->sphere_one && inter->plan < inter->sphere_two)
    return (0xFF0000);
  else
    return (luminosite(inter));
}

unsigned int	calc_img(int x, int y, t_points *points)
{
  t_inter	inter;
  t_eye_virt	virt;

  points->x_eye = -300;
  points->y_eye = 110;
  points->z_eye = 50;
  points->angle_x_eye = 0;
  points->angle_y_eye = 0;
  points->angle_z_eye = 0;
  points->vect_x = DIST_EYE_TO_IMG;
  points->vect_y = (WIDTH / 2) - x;
  points->vect_z = (HEIGHT / 2) - y;

  points->x_sphere = 0;
  points->y_sphere = 0;
  points->z_sphere = 0;
  points->angle_x_sphere = 0;
  points->angle_y_sphere = 0;
  points->angle_z_sphere = 0;
  points->radius_sphere = 100;

  points->x_plan = 0;
  points->y_plan = 0;
  points->z_plan = -50;
  points->angle_x_plan = 0;
  points->angle_y_plan = 0;
  points->angle_z_plan = 20;


  /* points->vect_x = points->vect_x - points->x_eye; */
  /* points->vect_y = points->vect_y - points->y_eye; */
  /* points->vect_z = points->vect_z - points->z_eye; */

  sphere(points, &inter, &virt, 0);
  if (x == 500 && y == 400 && inter.sphere_one != -1)
  {
    printf("x = %d y = %d\n", x, y);
    printf("x_sphere = %lf y_sphere = %lf z_sphere = %lf\n", inter.sphere_point_x,
	   inter.sphere_point_y, inter.sphere_point_z);
    printf("vrt->vect_x = %lf vrt->vect_y = %lf vrt->vect_z = %lf\n", virt.vect_x, virt.vect_y,
	   virt.vect_z);
    printf("norme_x = %lf norme_y = %lf norme_z = %lf\n", inter.sphere_normal_x,
	   inter.sphere_normal_y, inter.sphere_normal_z);
  }
  plan(points, &inter, &virt);
  return (get_color_obj(&inter));
}

int		make_graph(t_infos_mlx *infos_mlx, t_points *points)
{
  int		x;
  int		x2;
  int		y;
  int		color;

  x = 0;
  x2 = WIDTH - 1;
  my_putstr("loading... ");
  /* while (x < x2) */
  /* { */
  /*   y = 0; */
  /*   while (y < HEIGHT) */
  /*   { */
  /*     color = calc_img(x, y, points); */
  /*     my_pixel_put_to_image(x, y, color, infos_mlx); */
  /*     y += 1; */
  /*   } */
  /*   mlx_put_image_to_window(infos_mlx->mlx_ptr, infos_mlx->win_ptr, */
  /* 			    infos_mlx->img, 0, 0); */
  /*   y = 0; */
  /*   while (y < HEIGHT) */
  /*   { */
  /*     color = calc_img(x2, y, points); */
  /*     my_pixel_put_to_image(x2, y, color, infos_mlx); */
  /*     y += 1; */
  /*   } */
  /*   mlx_put_image_to_window(infos_mlx->mlx_ptr, infos_mlx->win_ptr, */
  /* 			    infos_mlx->img, 0, 0); */
  /*   x2 -= 1; */
  /*   x += 1; */
  /* } */
  while (x < WIDTH)
  {
    y = 0;
    while (y < HEIGHT)
    {
      color = calc_img(x, y, points);
      my_pixel_put_to_image(x, y, color, infos_mlx);
      y += 1;
    }
      mlx_put_image_to_window(infos_mlx->mlx_ptr, infos_mlx->win_ptr,
  			      infos_mlx->img, 0, 0);
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
