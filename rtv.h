/*
** rtv.h for rtv in /home/chapui_s/rendu/MUL_2013_rtv1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Sun Mar  9 23:59:55 2014 chapui_s
** Last update Sun Mar 16 12:43:35 2014 chapui_s
*/

#ifndef RTV_H_
# define RTV_H_

# include <math.h>

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
  double		shine_sphere;
  unsigned int		color_sphere;
  double		x_plan;
  double		y_plan;
  double		z_plan;
  double		angle_x_plan;
  double		angle_y_plan;
  double		angle_z_plan;
  double		shine_plan;
  unsigned int		color_plan;
  double		x_cone;
  double		y_cone;
  double		z_cone;
  double		angle_x_cone;
  double		angle_y_cone;
  double		angle_z_cone;
  double		angle_cone;
  double		shine_cone;
  unsigned int		color_cone;
  double		x_cylindre;
  double		y_cylindre;
  double		z_cylindre;
  double		angle_x_cylindre;
  double		angle_y_cylindre;
  double		angle_z_cylindre;
  double		rayon_cylindre;
  double		shine_cylindre;
  unsigned int		color_cylindre;
}			t_points;

typedef struct		s_spot
{
  double		x_spot;
  double		y_spot;
  double		z_spot;
  double		vect_l_x;
  double		vect_l_y;
  double		vect_l_z;
  double		norme_l;
  double		norme_obj;
  double		prod_scal;
  unsigned int		color_spot;
}			t_spot;

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
  double		plan_point_x;
  double		plan_point_y;
  double		plan_point_z;
  double		plan_normal_x;
  double		plan_normal_y;
  double		plan_normal_z;
  double		cone_one;
  double		cone_two;
  double		cone_point_x;
  double		cone_point_y;
  double		cone_point_z;
  double		cone_normal_x;
  double		cone_normal_y;
  double		cone_normal_z;
  double		cylindre_one;
  double		cylindre_two;
  double		cylindre_point_x;
  double		cylindre_point_y;
  double		cylindre_point_z;
  double		cylindre_normal_x;
  double		cylindre_normal_y;
  double		cylindre_normal_z;
}			t_inter;

# define HEIGHT			(600)
# define WIDTH			(800)
# define DIST_EYE_TO_IMG	300
# define SPHERE			1
# define PLAN			2
# define CONE			3
# define CYLINDRE		4
# define DEG_TO_RAD(x)		(x * (M_PI/180))
# define ALLOC_ERROR		"error: could not alloc\n"
# define MLX_ERROR		"error: could not open window\n"
# define WINDOW_TITLE		"RTV1"

void		*puterror_null(char *str);
int		manage_expose(void *param);
int		manage_key(int keycode, t_infos_mlx *infos_mlx);
int		val_abs(int n);
void		my_pixel_put_to_image(int x, int y,
				      unsigned int color,
				      t_infos_mlx *infos_mlx);
int		my_putstr(char *str);
double		sphere(t_points *pts,
		       t_inter *inter,
		       t_eye_virt *virt,
		       double delta);
double		cylindre(t_points *pts,
			 t_inter *inter,
			 t_eye_virt *virt);
double		cone(t_points *pts,
		     t_inter *inter,
		     t_eye_virt *virt);
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
double		get_cos_a_sphere(t_spot *spot, t_inter *inter);
double		get_cos_a_plan(t_spot *spot, t_inter *inter);
double		get_cos_a_cone(t_spot *spot, t_inter *inter);
double		get_cos_a_cylindre(t_spot *spot, t_inter *inter);
unsigned int	get_color_pixel(t_inter *inter,
				t_spot *spot,
				t_points *pts);
unsigned int	luminosite(t_points *pts,
			   t_inter *inter,
			   t_spot *spot,
			   int obj);
void		init_eye_spot(int x, int y, t_points *points, t_spot *spot);
void		init_sphere(t_points *points);
void		init_plan(t_points *points);
void		init_cone(t_points *points);
void		init_cylindre(t_points *points);
int		is_shadow_with_sphere(t_points *pts, t_points *pts_shadow);
int		is_shadow_with_cone(t_points *pts, t_points *pts_shadow);
int		is_shadow_with_cylindre(t_points *pts, t_points *pts_shadow);
int		prepare_shadow_cylindre(t_points *pts,
					t_inter *inter,
					t_spot *spot);
int		prepare_shadow_plan(t_points *pts,
				    t_inter *inter,
				    t_spot *spot);
int		prepare_shadow_cone(t_points *pts,
				    t_inter *inter,
				    t_spot *spot);
int		prepare_shadow_sphere(t_points *pts,
				      t_inter *inter,
				      t_spot *spot);
double		get_cos_a(t_spot *spot, t_inter *inter, int obj);
unsigned int	get_color_obj(t_points *pts, int obj);
unsigned int	luminosity(t_points *pts,
			   t_inter *inter,
			   t_spot *spot,
			   int obj);
int		shadow(t_points *pts,
		       t_inter *inter,
		       t_spot *spot,
		       int obj);

#endif /* !RTV_H_ */
