/*
** load_cyl.c for load_cyl in /home/virgile/raytracer1
** 
** Made by virgile
** Login   <virgile1.pion@epitech.eu>
** 
** Started on  Wed Mar 15 15:32:27 2017 virgile
** Last update Wed Mar 15 16:40:53 2017 virgile
*/

#include "my.h"
#include "get_next_line.h"

void		my_write_cyl(t_data *d, int fd, char *str, t_cyl *cyl)
{
  int		i;

  i = 0;
  while (i < d->nb_cyl)
    {
      cyl[i].pos = make_pos(0, 0, 0);
      cyl[i].color = edit_color(255, 255, 255, 255);
      cyl[i].rotation = make_pos(0, 0, 0);
      cyl[i].radius = 50;
      while (my_strncmp((str = get_next_line(fd)), "END", 3) == 0 && str != NULL)
	{
	  if (my_strncmp(str, "pos", 3))
	    cyl[i].pos = my_load_pos(str);
	  if (my_strncmp(str, "color", 5))
	    cyl[i].color = my_load_color(str);
	  if (my_strncmp(str, "rot", 3))
	    cyl[i].rotation = my_load_pos(str);
	  if (my_strncmp(str, "radius", 6))
	    cyl[i].radius = parse_nb(str);
	}
      i++;
    }
}

void            my_load_cyl(t_data *d, int fd)
{
  char          *str;
  t_cyl         *cyl;

  str = get_next_line(fd);
  d->nb_cyl = my_getnbr(str);
  if ((cyl = malloc(sizeof(*cyl) * d->nb_cyl + 1)) == NULL)
    cyl = NULL;
  my_write_cyl(d, fd, str, cyl);
  d->cyl = cyl;
}
