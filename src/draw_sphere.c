/*
** draw_sphere.c for draw_sphere in /home/virgile/raytracer1
** 
** Made by virgile
** Login   <virgile1.pion@epitech.eu>
** 
** Started on  Wed Mar 15 13:02:32 2017 virgile
** Last update Wed Mar 15 13:05:22 2017 virgile
*/

#include "my.h"

void			my_calc_sphere(t_data *d, int i, int j)
{
  d->k_min = d->sphere[i].k;
  d->pos_min = get_point_form(d->eye_pos, d->dir_vector, d->sphere[i].k);
  d->normale = get_normal_sphere(d->pos_min);
  d->lum_vector = my_vectorize(d->light[j].pos, d->pos_min);
  if (!is_on_light(d, i, 0))
    {
      d->cos_angle = get_light_coef(d->lum_vector, d->normale);
      if (d->cos_angle > d->coef_color)
	d->coef_color = d->cos_angle;
    }
}

void			my_draw_sphere(t_data *d)
{
  int			i;
  int			j;

  i = 0;
  while (i < d->nb_sphere)
    {
      d->sphere[i].k = my_int_sphere(d->eye_pos, d->sphere[i].pos,
				     d->dir_vector, d->sphere[i].radius);
      if (d->sphere[i].k > 0 && d->sphere[i].k < d->k_min)
	{
	  d->coef_color = 0;
	  j = 0;
	  while (j < d->nb_light)
	    {
	      my_calc_sphere(d, i, j);
	      j++;
	    }
	  if (d->coef_color < d->ambient_light)
	    d->coef_color = d->ambient_light;
	  d->color_obj = multiply_color(d->sphere[i].color, d->coef_color);
	}
      i++;
    }
}
