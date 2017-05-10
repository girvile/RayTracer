/*
** load_cone.c for load_cone in /home/virgile/raytracer1
** 
** Made by virgile
** Login   <virgile1.pion@epitech.eu>
** 
** Started on  Wed Mar 15 15:24:59 2017 virgile
** Last update Wed Mar 15 17:22:45 2017 virgile
*/

#include "my.h"
#include "get_next_line.h"

void		my_write_cone(t_data *d, int fd, char *str, t_cone *cone)
{
  int		i;

  i = 0;
  while (i < d->nb_cone)
    {
      cone[i].pos = make_pos(0, 0, 0);
      cone[i].color = edit_color(255, 255, 255, 255);
      cone[i].rotation = make_pos(0, 0, 0);
      cone[i].angle = 50;
      while (my_strncmp((str = get_next_line(fd)), "END", 3) == 0 && str != NULL)
	{
	  if (my_strncmp(str, "pos", 3))
	    cone[i].pos = my_load_pos(str);
	  if (my_strncmp(str, "color", 5))
	    cone[i].color = my_load_color(str);
	  if (my_strncmp(str, "rot", 3))
	    {
	      cone[i].rotation = my_load_pos(str);
	    }
	  if (my_strncmp(str, "angle", 5))
	    cone[i].angle = parse_nb(str);
	}
      i++;
    }
}

void		my_load_cone(t_data *d, int fd)
{
  char		*str;
  t_cone	*cone;

  str = get_next_line(fd);
  d->nb_cone = my_getnbr(str);
  if ((cone = malloc(sizeof(*cone) * d->nb_cone + 1)) == NULL)
    cone = NULL;
  my_write_cone(d, fd, str, cone);
  d->cone = cone;
}
