/*
** load_sphere.c for load_sphere in /home/virgile/raytracer1
** 
** Made by virgile
** Login   <virgile1.pion@epitech.eu>
** 
** Started on  Wed Mar 15 15:00:39 2017 virgile
** Last update Wed Mar 15 17:20:12 2017 virgile
*/

#include "my.h"
#include "get_next_line.h"

void		my_write_sphere(t_data *d, int fd, char *str, t_sphere *sphere)
{
  int		i;

  i = 0;
  while (i < d->nb_sphere)
    {
      sphere[i].pos = make_pos(0, 0, 0);
      sphere[i].color = edit_color(255, 255, 255, 255);
      sphere[i].rotation = make_pos(0, 0, 0);
      sphere[i].radius = 50;
      while (my_strncmp((str = get_next_line(fd)), "END", 3) == 0 && str != NULL)
	{
	  if (my_strncmp(str, "pos", 3))
	    sphere[i].pos = my_load_pos(str);
	  if (my_strncmp(str, "color", 5))
	    sphere[i].color = my_load_color(str);
	  if (my_strncmp(str, "rot", 3))
	    sphere[i].rotation = my_load_pos(str);
	  if (my_strncmp(str, "radius", 6))
	    sphere[i].radius = parse_nb(str);
	}
      i++;
    }
}

void            my_load_sphere(t_data *d, int fd)
{
  char		*str;
  t_sphere	*sphere;

  str = get_next_line(fd);
  d->nb_sphere = my_getnbr(str);
  if ((sphere = malloc(sizeof(*sphere) * d->nb_sphere + 1)) == NULL)
    sphere = NULL;
  my_write_sphere(d, fd, str, sphere);
  d->sphere = sphere;
}
