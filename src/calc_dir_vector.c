/*
** calc_dir_vector.c for calc_dir_vector in /home/virgile/bsraytracer1
** 
** Made by virgile
** Login   <virgile1.pion@epitech.eu>
** 
** Started on  Tue Feb  7 13:50:20 2017 virgile
** Last update Wed Mar 15 17:03:01 2017 virgile
*/

#include "my.h"

sfVector3f		calc_dir_vector(float dist_to_plane,	\
					sfVector2i screen_size,	\
					sfVector2i screen_pos)
{
  sfVector3f		direction;

  direction.x = dist_to_plane;
  direction.y = (screen_size.x / 2) - screen_pos.x;
  direction.z = (screen_size.y / 2) - screen_pos.y;
  return (direction);
}
