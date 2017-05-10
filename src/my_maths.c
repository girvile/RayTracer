/*
** my_maths.c for my_maths in /home/virgile/raytracer1
** 
** Made by virgile
** Login   <virgile1.pion@epitech.eu>
** 
** Started on  Sat Feb 11 18:23:58 2017 virgile
** Last update Wed Mar 15 17:33:56 2017 virgile
*/

#include "my.h"

void		calcul_light(t_data *d)
{
  d->produit_scalaire = my_scalaire(d->lum_vector, d->normale);
  d->angle = acosf(d->produit_scalaire					\
		   / (my_norme(d->lum_vector) * my_norme(d->normale)));
  d->cos_angle = cosf(d->angle);
  if (d->cos_angle > d->coef_color)
    d->coef_color = d->cos_angle;
}

sfVector3f	get_point_form(sfVector3f eye_pos, sfVector3f dir_vector, float k)
{
  sfVector3f	point;

  point.x = eye_pos.x + k * dir_vector.x;
  point.y = eye_pos.y + k * dir_vector.y;
  point.z = eye_pos.z + k * dir_vector.z;
  return (point);
}

sfVector3f	my_vectorize(sfVector3f a, sfVector3f b)
{
  sfVector3f	c;

  c.x = a.x - b.x;
  c.y = a.y - b.y;
  c.z = a.z - b.z;
  return (c);
}

sfColor		multiply_color(sfColor color, float coef)
{
  color.a *= coef;
  color.r *= coef;
  color.g *= coef;
  color.b *= coef;
  return (color);
}
