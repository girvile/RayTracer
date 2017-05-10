/*
** light.c for light in /home/virgile/raytracer1
** 
** Made by virgile
** Login   <virgile1.pion@epitech.eu>
** 
** Started on  Mon Feb 27 11:15:31 2017 virgile
** Last update Wed Mar 15 17:04:11 2017 virgile
*/

#include "my.h"

float           my_scal(sfVector3f va, sfVector3f vb)
{
  return (va.x * vb.x + va.y * vb.y + va.z * vb.z);
}

float		my_norm(sfVector3f vector)
{
  return (sqrtf(vector.x * vector.x		\
		+ vector.y * vector.y		\
		+ vector.z * vector.z));
}

float		get_light_coef(sfVector3f light_vector, sfVector3f normal_vector)
{
  float		scalaire;
  float		angle;
  float		normes;

  scalaire = my_scal(light_vector, normal_vector);
  normes = my_norm(light_vector) * my_norm(normal_vector);
  if (normes == 0)
    return (0);
  angle = scalaire / normes;
  if (angle < 0)
    angle = 0;
  return (angle);
}
