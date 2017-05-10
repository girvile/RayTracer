/*
** eq_solver.c for eq_solver in /home/virgile/raytracer1
** 
** Made by virgile
** Login   <virgile1.pion@epitech.eu>
** 
** Started on  Fri Feb 17 01:08:35 2017 virgile
** Last update Wed Mar 15 16:59:05 2017 virgile
*/

#include "my.h"

float		eq_solver(float a, float b, float c)
{
  float		k1;
  float		k2;

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
