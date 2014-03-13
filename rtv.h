/*
** rtv.h for rtv in /home/chapui_s/rendu/MUL_2013_rtv1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Sun Mar  9 23:59:55 2014 chapui_s
** Last update Thu Mar 13 20:23:05 2014 chapui_s
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
  double		x_eye;
  double		y_eye;
  double		z_eye;
  double		angle_x_eye;
  double		angle_y_eye;
  double		angle_z_eye;
  double		vect_x;
  double		vect_y;
  double		vect_z;
  double		x_sphere;
  double		y_sphere;
  double		z_sphere;
  double		angle_x_sphere;
  double		angle_y_sphere;
  double		angle_z_sphere;
  double		radius_sphere;
  double		x_plan;
  double		y_plan;
  double		z_plan;
  double		angle_x_plan;
  double		angle_y_plan;
  double		angle_z_plan;
}			t_points;

typedef struct		s_eye_virt
{
  double		x_eye;
  double		y_eye;
  double		z_eye;
  double		angle_x_eye;
  double		angle_y_eye;
  double		angle_z_eye;
  double		vect_x;
  double		vect_y;
  double		vect_z;
}			t_eye_virt;

typedef struct		s_inter
{
  double		sphere_one;
  double		sphere_two;
  double		sphere_point_x;
  double		sphere_point_y;
  double		sphere_point_z;
  double		sphere_normal_x;
  double		sphere_normal_y;
  double		sphere_normal_z;
  double		plan;
}			t_inter;

# define HEIGHT			(600)
# define WIDTH			(800)
# define DIST_EYE_TO_IMG	300
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
void		sphere(t_points *pts,
		       t_inter *inter,
		       t_eye_virt *virt,
		       double delta);
double		plan(t_points *pts, t_inter *inter, t_eye_virt *vrt);
void		rotate_x(double *x,
			 double *y,
			 double *z,
			 double angle);
void		rotate_y(double *x,
			 double *y,
			 double *z,
			 double angle);
void		rotate_z(double *x,
			 double *y,
			 double *z,
			 double angle);

#endif /* !RTV_H_ */
