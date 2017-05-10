/*
** my_load_pos.c for my_load_pos in /home/virgile/raytracer1
** 
** Made by virgile
** Login   <virgile1.pion@epitech.eu>
** 
** Started on  Sun Feb 12 02:47:29 2017 virgile
** Last update Wed Mar 15 12:41:38 2017 virgile
*/

#include <stdio.h>
#include "my.h"
#include "get_next_line.h"

sfVector3f	my_load_pos2(char *str, int i, sfVector3f pos)
{
  if (str[i] == '\0')
    return (make_pos(0, 0, 0));
  pos.y = my_getnbr(&str[i]);
  while ((str[i] >= '0' && str[i] <= '9') ||	\
	 str[i] == '+' || str[i] == '-')
    i++;
  while ((str[i] < '0' || str[i] > '9') && str[i] != '\0'	\
	 && str[i] != '-' && str[i] != '+')
    i++;
  if (str[i] == '\0')
    return (make_pos(0, 0, 0));
  pos.z = my_getnbr(&str[i]);
  return (pos);
}

sfVector3f	my_load_pos(char *str)
{
  int		i;
  sfVector3f	pos;

  i = 0;
  while ((str[i] < '0' || str[i] > '9') &&			\
	 str[i] != '\0' && str[i] != '-' && str[i] != '+')
    i++;
  if (str[i] == '\0')
    return (make_pos(0, 0, 0));
  pos.x = my_getnbr(&str[i]);
  while ((str[i] >= '0' && str[i] <= '9') ||	\
	 str[i] == '+' || str[i] == '+')
    i++;
  while ((str[i] < '0' || str[i] > '9') && str[i] != '\0'	\
	 && str[i] != '-' && str[i] != '+')
    i++;
  return (my_load_pos2(str, i, pos));
}

sfColor		my_load_color2(char *str, int i, sfColor color)
{
  color.r = my_getnbr(&str[i]);
  while (str[i] >= '0' && str[i] <= '9')
    i++;
  while ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
    i++;
  if (str[i] == '\0')
    return (edit_color(255, 255, 255, 0));
  color.g = my_getnbr(&str[i]);
  while (str[i] >= '0' && str[i] <= '9')
    i++;
  while ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
    i++;
  if (str[i] == '\0')
    return (edit_color(255, 255, 255, 0));
  color.b = my_getnbr(&str[i]);
  return (color);
}

sfColor		my_load_color(char *str)
{
  int		i;
  sfColor	color;

  i = 0;
  while ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
    i++;
  if (str[i] == '\0')
    return (edit_color(255, 255, 255, 0));
  color.a = my_getnbr(&str[i]);
  while (str[i] >= '0' && str[i] <= '9')
    i++;
  while ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
    i++;
  if (str[i] == '\0')
    return (edit_color(255, 255, 255, 0));
  return (my_load_color2(str, i, color));
}
