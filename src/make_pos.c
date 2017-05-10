/*
** make_pos.c for make_pos in /home/virgile/raytracer1
** 
** Made by virgile
** Login   <virgile1.pion@epitech.eu>
** 
** Started on  Thu Feb  9 20:25:50 2017 virgile
** Last update Thu Feb  9 20:29:03 2017 virgile
*/

#include "my.h"

sfVector3f	make_pos(float x, float y, float z)
{
  sfVector3f	pos;

  pos.x = x;
  pos.y = y;
  pos.z = z;
  return (pos);
}
