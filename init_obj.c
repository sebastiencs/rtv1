/*
** main.c for rtv in /home/chapui_s/rendu/MUL_2013_rtv1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Mar 10 00:02:05 2014 chapui_s
** Last update Sun Mar 16 12:37:57 2014 chapui_s
*/

#include <math.h>
#include <stdlib.h>
#include "rtv.h"

void		init_eye_spot(int x, int y, t_points *points, t_spot *spot)
{
  points->x_eye = -300;
  points->y_eye = 110;
  points->z_eye = 50;
  points->angle_x_eye = -5;
  points->angle_y_eye = -10;
  points->angle_z_eye = 10;
  points->vect_x = DIST_EYE_TO_IMG;
  points->vect_y = (WIDTH / 2.0) - x;
  points->vect_z = (HEIGHT / 2.0) - y;
  rotate_x(&(points->vect_x), &(points->vect_y), &(points->vect_z),
	   points->angle_x_eye);
  rotate_y(&(points->vect_x), &(points->vect_y), &(points->vect_z),
	   points->angle_y_eye);
  rotate_z(&(points->vect_x), &(points->vect_y), &(points->vect_z),
	   points->angle_z_eye);
  spot->x_spot = -300;
  spot->y_spot = 400;
  spot->z_spot = 500;
  spot->color_spot = 0xFFFFFF;
}

void		init_sphere(t_points *points)
{
  points->x_sphere = -50;
  points->y_sphere = 220;
  points->z_sphere = 100;
  points->angle_x_sphere = 0;
  points->angle_y_sphere = 0;
  points->angle_z_sphere = 0;
  points->radius_sphere = 70;
  points->shine_sphere = 0.5;
  points->color_sphere = 0x0000FF;
}

void		init_plan(t_points *points)
{
  points->x_plan = 0;
  points->y_plan = 0;
  points->z_plan = -50;
  points->angle_x_plan = 0;
  points->angle_y_plan = 0;
  points->angle_z_plan = 0;
  points->shine_plan = 0.5;
  points->color_plan = 0xFF0000;
}

void		init_cone(t_points *points)
{
  points->x_cone = 0;
  points->y_cone = 450;
  points->z_cone = -40;
  points->angle_x_cone = 0;
  points->angle_y_cone = 2;
  points->angle_z_cone = 0;
  points->angle_cone = 5;
  points->shine_cone = 0.5;
  points->color_cone = 0x00FF00;
}

void		init_cylindre(t_points *points)
{
  points->x_cylindre = 0;
  points->y_cylindre = -50;
  points->z_cylindre = 0;
  points->angle_x_cylindre = -40;
  points->angle_y_cylindre = 0;
  points->angle_z_cylindre = 0;
  points->rayon_cylindre = 50;
  points->shine_cylindre = 0.5;
  points->color_cylindre = 0x707070;
}
