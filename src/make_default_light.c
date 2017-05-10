/*
** make_default_light.c for make_default_light in /home/virgile/raytracer1
** 
** Made by virgile
** Login   <virgile1.pion@epitech.eu>
** 
** Started on  Fri Feb 10 14:32:06 2017 virgile
** Last update Fri Feb 10 14:37:55 2017 virgile
*/

#include "my.h"

t_light		*make_default_light(float x, float y, float z)
{
  t_light	*light;

  if ((light = malloc(sizeof(*light))) != NULL)
    {
      light[0].pos.x = x;
      light[0].pos.y = y;
      light[0].pos.z = z;
    }
  return (light);
}
