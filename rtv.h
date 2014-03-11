/*
** rtv.h for rtv in /home/chapui_s/rendu/MUL_2013_rtv1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Sun Mar  9 23:59:55 2014 chapui_s
** Last update Mon Mar 10 23:23:15 2014 chapui_s
*/

#ifndef RTV_H_
# define RTV_H_

# include <math.h>

typedef struct		s_line
{
  int			x1;
  int			x2;
  int			y1;
  int			y2;
}			t_line;

typedef struct		s_infos_mlx
{
  void			*mlx_ptr;
  void			*win_ptr;
  void			*img;
  char			*data;
  int			bpp;
  int			sizeline;
  int			endian;
}			t_infos_mlx;

typedef struct		s_points
{
  int			x_eye;
  int			y_eye;
  int			z_eye;
  int			vect_x;
  int			vect_y;
  int			vect_z;
  double		rot_x;
  double		rot_y;
  double		rot_z;
}			t_points;

typedef struct		s_inter
{
  double		sphere_one;
  double		sphere_two;
  double		plan;
}			t_inter;

# define HEIGHT			(600)
# define WIDTH			(800)
# define DIST_EYE_TO_IMG	100
# define DEG_TO_RAD(x)		(x * (M_PI/180))
# define ALLOC_ERROR		"error: could not alloc\n"
# define MLX_ERROR		"error: could not open window\n"
# define WINDOW_TITLE		"RTV1"

void		*puterror_null(char *str);
int		manage_expose(void *param);
int		manage_key(int keycode, t_infos_mlx *infos_mlx);
void		swap_int(int *a, int *b);
int		val_abs(int n);
void		my_pixel_put_to_image(int x, int y,
				      unsigned int color,
				      t_infos_mlx *infos_mlx);
int		my_putstr(char *str);
double		sphere(t_points *pts, t_inter *inter);
double		plan(t_points *pts, t_inter *inter);
void		rotate_z(t_points *pts, double angle);
void		rotate_x(t_points *pts, double angle);
void		rotate_y(t_points *pts, double angle);

#endif /* !RTV_H_ */
