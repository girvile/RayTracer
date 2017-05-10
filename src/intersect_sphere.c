/*
** intersect_sphere.c for intersect_sphere in /home/virgile/bsraytracer1
** 
** Made by virgile
** Login   <virgile1.pion@epitech.eu>
** 
** Started on  Tue Feb  7 13:52:54 2017 virgile
** Last update Wed Mar 15 17:21:04 2017 virgile
*/

#include "my.h"

float		my_int_cyl(sfVector3f eye_pos, sfVector3f obj,	\
			   sfVector3f dir_vector, float radius)
{
  float		a;
  float		b;
  float		c;

  eye_pos = my_vectorize(eye_pos, obj);
  a = dir_vector.x * dir_vector.x + dir_vector.y * dir_vector.y;
  b = 2 * (eye_pos.x * dir_vector.x + eye_pos.y * dir_vector.y);
  c = eye_pos.x * eye_pos.x + eye_pos.y * eye_pos.y - radius * radius;
  return (eq_solver(a, b, c));
}

float		my_int_cone(sfVector3f eye_pos, sfVector3f obj,	\
			    sfVector3f dir_vector, float angle)
{
  float		a;
  float		b;
  float		c;

  angle = angle * M_PI / 180;
  eye_pos = my_vectorize(eye_pos, obj);
  a = dir_vector.x * dir_vector.x + dir_vector.y * dir_vector.y -	\
    (dir_vector.z * dir_vector.z * tan(angle) * tan(angle));
  b = 2 * (eye_pos.x * dir_vector.x + eye_pos.y * dir_vector.y -	\
	   eye_pos.z * dir_vector.z * tan(angle) * tan(angle));
  c = eye_pos.x * eye_pos.x + eye_pos.y * eye_pos.y -	\
    eye_pos.z * eye_pos.z * tan(angle) * tan(angle);
  return (eq_solver(a, b, c));
}

float           my_int_sphere(sfVector3f eye_pos, sfVector3f obj,	\
			      sfVector3f dir_vector, float radius)
{
  float         a;
  float         b;
  float         c;

  eye_pos = my_vectorize(eye_pos, obj);
  a = dir_vector.x * dir_vector.x					\
    + dir_vector.y * dir_vector.y + dir_vector.z * dir_vector.z;
  b = 2 * (eye_pos.x * dir_vector.x					\
	   + eye_pos.y * dir_vector.y + eye_pos.z * dir_vector.z);
  c = eye_pos.x * eye_pos.x						\
    + eye_pos.y * eye_pos.y + eye_pos.z * eye_pos.z - radius * radius;
  return (eq_solver(a, b, c));
}
