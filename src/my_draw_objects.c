/*
** my_draw_objects.c for my_draw_objects in /home/virgile/raytracer1
** 
** Made by virgile
** Login   <virgile1.pion@epitech.eu>
** 
** Started on  Thu Feb  9 15:23:01 2017 virgile
** Last update Wed Mar 15 17:32:48 2017 virgile
*/

#include "my.h"
#include <stdio.h>

void                    my_draw_objects(t_data *d)
{
  d->screen_size.x = d->buffer->width;
  d->screen_size.y = d->buffer->height;
  d->screen_pos.y = 0;
  while (d->screen_pos.y < d->buffer->height)
    {
      d->screen_pos.x = 0;
      while (d->screen_pos.x < d->buffer->width)
	{
	  d->k_min = 10;
	  d->dir_vector = calc_dir_vector(M_FOV, d->screen_size, d->screen_pos);
	  d->color_obj = sfBlack;
	  if (d->nb_sphere > 0)
	    my_draw_sphere(d);
	  if (d->nb_plan > 0)
	  my_draw_plan(d);
	  if (d->nb_cone > 0)
	  my_draw_cone(d);
	  if (d->nb_cyl > 0)
	  my_draw_cyl(d);
	  my_put_pixel(d->buffer, d->screen_pos.x, d->screen_pos.y, d->color_obj);
	  d->screen_pos.x++;
	}
      d->screen_pos.y++;
    }
}
