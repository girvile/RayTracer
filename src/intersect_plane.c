/*
** intersect_plane.c for intersect_plane in /home/virgile/bsraytracer1
** 
** Made by virgile
** Login   <virgile1.pion@epitech.eu>
** 
** Started on  Tue Feb  7 15:14:26 2017 virgile
** Last update Wed Mar 15 16:58:12 2017 virgile
*/

#include "my.h"

float	my_int_plan(sfVector3f eye_pos, sfVector3f obj, sfVector3f dir_vector)
{
  float	k;

  k = -1.0;
  eye_pos = my_vectorize(eye_pos, obj);
  if (dir_vector.z != 0)
    {
      k = -eye_pos.z / dir_vector.z;
    }
  if (k > 0)
    return (k);
  else
    return ((float)-1.0);
}
