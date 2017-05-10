/*
** sphere.c for sphere in /home/virgile/raytracer1
** 
** Made by virgile
** Login   <virgile1.pion@epitech.eu>
** 
** Started on  Mon Feb 27 10:19:45 2017 virgile
** Last update Wed Mar 15 12:53:46 2017 virgile
*/

#include "my.h"

sfVector3f	get_normal_sphere(sfVector3f intersection_point)
{
  return (intersection_point);
}

float		sphere_solver(float a, float b, float c)
{
  float         k1;
  float         k2;

  if (((b * b) - 4 * a * c) == 0)
    {
      k1 = -b / (2 * a);
      return ((k1 > 0) ? (k1) : (-1.0));
    }
  if (((b * b) - 4 * a * c) < 0)
    return (-1.0);
  if (((b * b) - 4 * a * c) > 0)
    {
      k1 = (-b + sqrtf(((b * b) - 4 * a * c))) / (2 * a);
      k2 = (-b - sqrtf(((b * b) - 4 * a * c))) / (2 * a);
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

float           intersect_sphere(sfVector3f eye_pos,
				 sfVector3f dir_vector, float radius)
{
  float         a;
  float         b;
  float         c;

  a = dir_vector.x * dir_vector.x + dir_vector.y * dir_vector.y	\
    + dir_vector.z * dir_vector.z;
  b = 2 * (eye_pos.x * dir_vector.x + eye_pos.y * dir_vector.y	\
	   + eye_pos.z * dir_vector.z);
  c = eye_pos.x * eye_pos.x + eye_pos.y * eye_pos.y	\
    + eye_pos.z * eye_pos.z - radius * radius;
  return (sphere_solver(a, b, c));
}
