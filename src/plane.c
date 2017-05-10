/*
** plane.c for plane in /home/virgile/raytracer1
** 
** Made by virgile
** Login   <virgile1.pion@epitech.eu>
** 
** Started on  Mon Feb 27 11:10:34 2017 virgile
** Last update Wed Mar 15 17:00:15 2017 virgile
*/

#include "my.h"

sfVector3f	get_normal_plane(int upward)
{
  sfVector3f	up;
  sfVector3f	down;

  up.x = 0;
  up.y = 0;
  up.z = 100;
  down.x = 0;
  down.y = 0;
  down.z = -100;
  return ((upward == 1) ? (up) : (down));
}

float		plane_solver(float a, float b, float c)
{
  float		delta;
  float		k1;
  float		k2;

  delta = (b * b) - 4 * a * c;
  if (delta == 0)
    {
      k1 = -b / (2 * a);
      return ((k1 > 0) ? (k1) : (-1.0));
    }
  if (delta < 0)
    return (-1.0);
  if (delta > 0)
    {
      k1 = (-b + sqrtf(delta)) / (2 * a);
      k2 = (-b - sqrtf(delta)) / (2 * a);
      if (k1 > 0 && k2 > 0)
	return ((k1 < k2) ? (k1) : (k2));
      if (k1 > 0)
	return (k1);
      if (k2 > 0)
	return (k2);
      return (-1.0);
    }
  return (0);
}

float		intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector)
{
  float		k;

  k = -1.0;
  if (dir_vector.z != 0)
    k = -eye_pos.z / dir_vector.z;
  if (k > 0)
    return (k);
  else
    return ((float)-1.0);
}
