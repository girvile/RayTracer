/*
** is_on_light.c for is_on_light in /home/virgile/raytracer1
** 
** Made by virgile
** Login   <virgile1.pion@epitech.eu>
** 
** Started on  Sun Feb 12 12:17:51 2017 virgile
** Last update Wed Mar 15 12:43:58 2017 virgile
*/

#include "my.h"

int			is_sphere_on_light(t_sphere *sphere, sfVector3f lum_vector, \
					   sfVector3f P, sfVector2i val)
{
  int			i;
  int			is_shadow;
  float			k;
  int			nb_sphere;
  int			exception;

  nb_sphere = val.x;
  exception = val.y;
  is_shadow = 0;
  i = 0;
  while (i < nb_sphere)
    {
      P = rotate_xyz(P, opposite_vector(sphere[i].rotation));
      lum_vector = rotate_xyz(lum_vector, opposite_vector(sphere[i].rotation));
      k = -1;
      if (i != exception)
	k = my_int_sphere(P, sphere[i].pos, lum_vector, sphere[i].radius);
      if (k > 0 && k < 1)
	is_shadow = 1;
      P = rotate_zyx(P, sphere[i].rotation);
      lum_vector = rotate_zyx(lum_vector, sphere[i].rotation);
      i++;
    }
  return (is_shadow);
}

int			is_plan_on_light(t_plan *plan, sfVector3f lum_vector, \
					 sfVector3f P, sfVector2i val)
{
  int			i;
  int			is_shadow;
  float			k;
  int			nb_plan;
  int			exception;

  nb_plan = val.x;
  exception = val.y;
  is_shadow = 0;
  i = 0;
  while (i < nb_plan)
    {
      P = rotate_xyz(P, opposite_vector(plan[i].rotation));
      lum_vector = rotate_xyz(lum_vector, opposite_vector(plan[i].rotation));
      k = -1;
      if (i != exception)
	k = my_int_plan(P, plan[i].pos, lum_vector);
      if (k > 0 && k < 1)
	is_shadow = 1;
      P = rotate_zyx(P, plan[i].rotation);
      lum_vector = rotate_zyx(lum_vector, plan[i].rotation);
      i++;
    }
  return (is_shadow);
}

int			is_cone_on_light(t_cone *cone, sfVector3f lum_vector, \
					 sfVector3f P, sfVector2i val)
{
  int			i;
  int			is_shadow;
  float			k;
  int			nb_cone;
  int			exception;

  nb_cone = val.x;
  exception = val.y;
  is_shadow = 0;
  i = 0;
  while (i < nb_cone)
    {
       P = rotate_xyz(P, opposite_vector(cone[i].rotation));
      lum_vector = rotate_xyz(lum_vector, opposite_vector(cone[i].rotation));
      k = -1;
      if (i != exception)
	k = my_int_cone(P, cone[i].pos, lum_vector, cone[i].angle);
      if (k > 0 && k < 1)
	is_shadow = 1;
      P = rotate_zyx(P, cone[i].rotation);
      lum_vector = rotate_zyx(lum_vector, cone[i].rotation);
      i++;
    }
  return (is_shadow);
}

int			is_cyl_on_light(t_cyl *cyl, sfVector3f lum_vector, \
					sfVector3f P, sfVector2i val)
{
  int			i;
  int			is_shadow;
  float			k;
  int			nb_cyl;
  int			exception;

  nb_cyl = val.x;
  exception = val.y;
  is_shadow = 0;
  i = 0;
  while (i < nb_cyl)
    {
      P = rotate_xyz(P, opposite_vector(cyl[i].rotation));
      lum_vector = rotate_xyz(lum_vector, opposite_vector(cyl[i].rotation));
      k = -1;
      if (i != exception)
	k = my_int_cyl(P, cyl[i].pos, lum_vector, cyl[i].radius);
      if (k > 0 && k < 1)
	is_shadow = 1;
      P = rotate_zyx(P, cyl[i].rotation);
      lum_vector = rotate_zyx(lum_vector, cyl[i].rotation);
      i++;
    }
  return (is_shadow);
}

int			is_on_light(t_data *d, int i, int obj)
{

  if (is_sphere_on_light(d->sphere, d->lum_vector, d->pos_min,		\
			 makepoint(d->nb_sphere,			\
				   ((obj == 0) ? (i) : (-1)))) == 1 ||	\
      is_plan_on_light(d->plan, d->lum_vector, d->pos_min,		\
		       makepoint(d->nb_plan,				\
				 ((obj == 1) ? (i) : (-1)))) == 1 ||	\
      is_cone_on_light(d->cone, d->lum_vector, d->pos_min,		\
		       makepoint(d->nb_cone,				\
				 ((obj == 2) ? (i) : (-1)))) == 1 ||	\
      is_cyl_on_light(d->cyl, d->lum_vector, d->pos_min,		\
		      makepoint(d->nb_cyl,				\
				((obj == 3) ? (i) : (-1)))) == 1)
    return (1);
  else
    return (0);
}
