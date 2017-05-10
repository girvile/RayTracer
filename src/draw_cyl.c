/*
** draw_cyl.c for draw_cyl in /home/virgile/raytracer1
** 
** Made by virgile
** Login   <virgile1.pion@epitech.eu>
** 
** Started on  Wed Mar 15 13:10:51 2017 virgile
** Last update Wed Mar 15 17:02:47 2017 virgile
*/

#include "my.h"

void			my_calc_cyl(t_data *d, int i, int j)
{
  d->pos_min = get_point_form(d->eye_pos, d->dir_vector, d->cyl[i].k);
  d->k_min = d->cyl[i].k;
  d->lum_vector = my_vectorize(d->light[j].pos, d->pos_min);
  d->normale = get_normal_cylinder(d->pos_min);
  d->cos_angle = get_light_coef(opposite_vector(d->lum_vector),	\
				opposite_vector(d->normale));
  if (d->cos_angle > d->coef_color)
    d->coef_color = d->cos_angle;
}

void			my_draw_cyl(t_data *d)
{
  int			i;
  int			j;

  i = 0;
  while (i < d->nb_cyl)
    {
      d->eye_pos = rotate_xyz(d->eye_pos, opposite_vector(d->cyl[i].rotation));
      d->dir_vector = rotate_xyz(d->dir_vector,				\
				 opposite_vector(d->cyl[i].rotation));
      d->cyl[i].k = my_int_cyl(d->eye_pos, d->cyl[i].pos,		\
			       d->dir_vector, d->cyl[i].radius);
      d->eye_pos = rotate_zyx(d->eye_pos, d->cyl[i].rotation);
      d->dir_vector = rotate_zyx(d->dir_vector, d->cyl[i].rotation);
      if (d->cyl[i].k > 0 && d->cyl[i].k < d->k_min)
	{
	  j = -1;
	  d->coef_color = 0;
	  while (++j < d->nb_light)
	    my_calc_cyl(d, i, j);
	  if (d->coef_color < d->ambient_light)
	    d->coef_color = d->ambient_light;
	  d->color_obj = multiply_color(d->cyl[i].color, d->coef_color);
	}
      i++;
    }
}
