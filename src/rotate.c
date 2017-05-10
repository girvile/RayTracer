/*
** rotate.c for rotate in /home/virgile/raytracer1
** 
** Made by virgile
** Login   <virgile1.pion@epitech.eu>
** 
** Started on  Mon Feb 13 23:24:40 2017 virgile
** Last update Thu Mar  2 17:03:04 2017 virgile
*/

#include "my.h"

sfVector3f	rotate_x(sfVector3f to_rotate, float angle)
{
  sfVector3f	new;

  new.x = to_rotate.x;
  new.y = to_rotate.y * cos(angle) + to_rotate.z * -sin(angle);
  new.z = to_rotate.y * sin(angle) + to_rotate.z * cos(angle);
  return (new);
}

sfVector3f	rotate_y(sfVector3f to_rotate, float angle)
{
  sfVector3f	new;

  new.x = to_rotate.x * cos(angle) + to_rotate.z * sin(angle);
  new.y = to_rotate.y;
  new.z = to_rotate.x * -sin(angle) + to_rotate.z * cos(angle);
  return (new);
}

sfVector3f	rotate_z(sfVector3f to_rotate, float angle)
{
  sfVector3f	new;

  new.x = cos(angle) * to_rotate.x + -sin(angle) * to_rotate.y;
  new.y = sin(angle) * to_rotate.x + cos(angle) * to_rotate.y;
  new.z = to_rotate.z;
  return (new);
}

sfVector3f	rotate_xyz(sfVector3f to_rotate, sfVector3f angles)
{
  sfVector3f	new;

  angles.x = angles.x * M_PI / 180;
  angles.y = angles.y * M_PI / 180;
  angles.z = angles.z * M_PI / 180;
  new = rotate_x(to_rotate, angles.x);
  new = rotate_y(new, angles.y);
  new = rotate_z(new, angles.z);
  return (new);
}

sfVector3f	rotate_zyx(sfVector3f to_rotate, sfVector3f angles)
{
  sfVector3f	new;

  angles.x = angles.x * M_PI / 180;
  angles.y = angles.y * M_PI / 180;
  angles.z = angles.z * M_PI / 180;
  new = rotate_z(to_rotate, angles.z);
  new = rotate_y(new, angles.y);
  new = rotate_x(new, angles.x);
  return (new);
}
