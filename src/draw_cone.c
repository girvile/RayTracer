/*
** draw_cone.c for draw_cone in /home/virgile/raytracer1
** 
** Made by virgile
** Login   <virgile1.pion@epitech.eu>
** 
** Started on  Wed Mar 15 13:08:15 2017 virgile
** Last update Wed Mar 15 16:54:53 2017 virgile
*/

#include "my.h"

void			my_calc_cone(t_data *d, int i, int j)
{
  d->k_min = d->cone[i].k;
  d->pos_min = get_point_form(d->eye_pos, d->dir_vector, d->cone[i].k);
  d->normale = get_normal_cone(d->pos_min, d->cone[i].angle);
  d->lum_vector = my_vectorize(d->light[j].pos, d->pos_min);
  if (!is_on_light(d, i, 2))
    {
      d->cos_angle = get_light_coef(d->lum_vector, d->normale);
      if (d->cos_angle > d->coef_color)
	d->coef_color = d->cos_angle;
    }
}

void			my_calc_cone2(t_data *d, int i)
{
  d->eye_pos = rotate_xyz(d->eye_pos,				\
			  opposite_vector(d->cone[i].rotation));
  d->dir_vector = rotate_xyz(d->dir_vector,				\
			     opposite_vector(d->cone[i].rotation));
  d->cone[i].k = my_int_cone(d->eye_pos, d->cone[i].pos,		\
			     d->dir_vector, d->cone[i].angle);
  d->eye_pos = rotate_zyx(d->eye_pos,		\
			  d->cone[i].rotation);
  d->dir_vector = rotate_zyx(d->dir_vector,		\
			     d->cone[i].rotation);
}

void			my_draw_cone(t_data *d)
{
  int			i;
  int			j;

  j = 0;
  i = 0;
  while (i < d->nb_cone)
    {
      my_calc_cone2(d, i);
      if (d->cone[i].k > 0 && d->cone[i].k < d->k_min)
	{
	  d->coef_color = 0;
	  j = -1;
	  while (++j < d->nb_light)
	    my_calc_cone(d, i, j);
	  if (d->coef_color < d->ambient_light)
	    d->coef_color = d->ambient_light;
	  d->color_obj = multiply_color(d->cone[i].color, d->coef_color);
	}
      i++;
    }
}
