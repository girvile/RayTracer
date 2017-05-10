/*
** draw_plan.c for  in /home/virgile/raytracer1
** 
** Made by virgile
** Login   <virgile1.pion@epitech.eu>
** 
** Started on  Wed Mar 15 13:05:52 2017 virgile
** Last update Wed Mar 15 17:31:53 2017 virgile
*/

#include "my.h"

void			my_calc_plan(t_data *d, int i, int j)
{
  d->k_min = d->plan[i].k;
  d->pos_min = get_point_form(d->eye_pos, d->dir_vector, d->plan[i].k);
  d->normale = get_normal_plane(1);
  d->lum_vector = my_vectorize(d->light[j].pos, d->pos_min);
  if (!is_on_light(d, i, 1))
    {
      d->cos_angle = get_light_coef(d->lum_vector, d->normale);
      if (d->cos_angle > d->coef_color)
	d->coef_color = d->cos_angle;
    }
}

void                    my_draw_plan(t_data *d)
{
  int                   i;
  int                   j;

  i = 0;
  while (i < d->nb_plan)
    {
      d->eye_pos = rotate_xyz(d->eye_pos, opposite_vector(d->plan[i].rotation));
      d->dir_vector = rotate_xyz(d->dir_vector,				\
				 opposite_vector(d->plan[i].rotation));
      d->plan[i].k = my_int_plan(d->eye_pos, d->plan[i].pos, d->dir_vector);
      d->eye_pos = rotate_zyx(d->eye_pos, d->plan[i].rotation);
      d->dir_vector = rotate_zyx(d->dir_vector, d->plan[i].rotation);
      if (d->plan[i].k > 0 && d->plan[i].k < d->k_min)
	{
	  d->coef_color = 0;
	  j = -1;
	  while (++j < d->nb_light)
	    my_calc_plan(d, i, j);
	  if (d->coef_color < d->ambient_light)
	    d->coef_color = d->ambient_light;
	  d->color_obj = multiply_color(d->plan[i].color, d->coef_color);
	}
      i++;
    }
}
