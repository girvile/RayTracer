/*
** my_math2.c for my_math2 in /home/virgile/raytracer1
** 
** Made by virgile
** Login   <virgile1.pion@epitech.eu>
** 
** Started on  Wed Mar 15 17:33:22 2017 virgile
** Last update Wed Mar 15 17:34:23 2017 virgile
*/

#include "my.h"

float		my_scalaire(sfVector3f va, sfVector3f vb)
{
  return (va.x * vb.x + va.y * vb.y + va.z * vb.z);
}

float		my_norme(sfVector3f vector)
{
  return (sqrtf(vector.x * vector.x             \
		                + vector.y * vector.y           \
		+ vector.z * vector.z));
}

sfVector3f	opposite_vector(sfVector3f vector)
{
  sfVector3f	opposite;

  opposite.x = -vector.x;
  opposite.y = -vector.y;
  opposite.z = -vector.z;
  return (opposite);
}

sfVector2i	makepoint(int x, int y)
{
  sfVector2i	point;

  point.x = x;
  point.y = y;
  return (point);
}
