/*
** event.c for event in /home/pion_b/courbe
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Fri Dec  2 21:34:15 2016 Virgile
** Last update Wed Mar 15 16:56:01 2017 virgile
*/

#include "my.h"

void			rotate_first(t_data *d)
{
   if (d->obj == 0)
  d->sphere[d->nb_obj].pos = rotate_xyz(d->sphere[d->nb_obj].pos,	\
					opposite_vector(d->sphere[d->nb_obj].rotation));
  if (d->obj == 1)
  d->plan[d->nb_obj].pos = rotate_xyz(d->plan[d->nb_obj].pos,	\
					opposite_vector(d->plan[d->nb_obj].rotation));
  if (d->obj == 2)
  d->cone[d->nb_obj].pos = rotate_xyz(d->cone[d->nb_obj].pos,	\
					opposite_vector(d->cone[d->nb_obj].rotation));
  if (d->obj == 3)
  d->cyl[d->nb_obj].pos = rotate_xyz(d->cyl[d->nb_obj].pos,	\
				     opposite_vector(d->cyl[d->nb_obj].rotation));
}

void			rotate_last(t_data *d)
{
  if (d->obj == 0)
    d->sphere[d->nb_obj].pos =						\
      rotate_zyx(d->sphere[d->nb_obj].pos, d->sphere[d->nb_obj].rotation);
  if (d->obj == 1)
    d->plan[d->nb_obj].pos =						\
      rotate_zyx(d->plan[d->nb_obj].pos, d->plan[d->nb_obj].rotation);
  if (d->obj == 2)
    d->cone[d->nb_obj].pos =						\
      rotate_zyx(d->cone[d->nb_obj].pos, d->cone[d->nb_obj].rotation);
  if (d->obj == 3)
    d->cyl[d->nb_obj].pos =						\
      rotate_zyx(d->cyl[d->nb_obj].pos, d->cyl[d->nb_obj].rotation);
}

void			move_forback(t_data *d, int x)
{
  rotate_first(d);
  if (d->obj == 0)
    d->sphere[d->nb_obj].pos.x += x;
  if (d->obj == 1)
    d->plan[d->nb_obj].pos.x += x;
  if (d->obj == 2)
    d->cone[d->nb_obj].pos.x += x;
  if (d->obj == 3)
    d->cyl[d->nb_obj].pos.x += x;
  rotate_last(d);
}

void			move_leftright(t_data *d, int x)
{
  rotate_first(d);
  if (d->obj == 0)
    d->sphere[d->nb_obj].pos.y += x;
  if (d->obj == 1)
    d->plan[d->nb_obj].pos.y += x;
  if (d->obj == 2)
    d->cone[d->nb_obj].pos.y += x;
  if (d->obj == 3)
    d->cyl[d->nb_obj].pos.y += x;
  rotate_last(d);
}

void			move_updown(t_data *d, int x)
{
  rotate_first(d);
  if (d->obj == 0)
    d->sphere[d->nb_obj].pos.z += x;
  if (d->obj == 1)
    d->plan[d->nb_obj].pos.z += x;
  if (d->obj == 2)
    d->cone[d->nb_obj].pos.z += x;
  if (d->obj == 3)
    d->cyl[d->nb_obj].pos.z += x;
  rotate_last(d);
}
