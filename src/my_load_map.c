/*
** my_load_map.c for my_load_map in /home/virgile/raytracer1
** 
** Made by virgile
** Login   <virgile1.pion@epitech.eu>
** 
** Started on  Wed Feb  8 15:54:00 2017 virgile
** Last update Wed Mar 15 12:55:20 2017 virgile
*/

#include <stdio.h>
#include "my.h"
#include "get_next_line.h"

int		my_strcmp(char *str, char *str2)
{
  int		i;

  i = 0;
  if (str == NULL || str2 == NULL)
    return (1);
  while (str[i])
    {
      if (str[i] != str2[i])
	return (0);
      i++;
    }
  if (str[i] != str2[i])
    return (0);
  return (1);
}

void		my_load_light(t_data *d, int fd)
{
  char	       	*str;
  t_light      	*light;
  int		i;
  int		nb_light;

  i = 0;
  str = get_next_line(fd);
  nb_light = my_getnbr(str);
  if ((light = malloc(sizeof(*light) * nb_light + 1)) == NULL)
    return;
  d->nb_light = nb_light;
  while (i < nb_light)
    {
      light[i].pos = make_pos(1000, 0, -10);
      while (my_strncmp((str = get_next_line(fd)), "END", 3) == 0 && str != NULL)
	{
	  if (my_strncmp(str, "pos", 3))
	    light[i].pos = my_load_pos(str);
	}
      i++;
    }
  d->light = light;
}

void		my_load_ambient_light(t_data *d, int fd)
{
  char	       	*str;

  while (my_strncmp((str = get_next_line(fd)), "END", 3) == 0 && str != NULL)
    {
      d->ambient_light = (float)my_getnbr(str) / 100.0;
    }
}

void		my_load_map(t_data *d)
{
  int		fd;
  char		*str;

  fd = -1;
  if ((fd = open(d->path, O_RDONLY)) == -1)
    return;
  d->ambient_light = 0;
  while ((str = get_next_line(fd)) != NULL)
    {
      if (my_strcmp(str, "sphere"))
	my_load_sphere(d, fd);
      if (my_strcmp(str, "plan"))
	my_load_plan(d, fd);
      if (my_strcmp(str, "cone"))
	my_load_cone(d, fd);
      if (my_strcmp(str, "cylinder"))
	my_load_cyl(d, fd);
      if (my_strcmp(str, "light"))
	my_load_light(d, fd);
      if (my_strcmp(str, "ambient light"))
	my_load_ambient_light(d, fd);
    }
}
