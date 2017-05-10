/*
** load_plan.c for load_plan in /home/virgile/raytracer1
** 
** Made by virgile
** Login   <virgile1.pion@epitech.eu>
** 
** Started on  Wed Mar 15 13:19:18 2017 virgile
** Last update Wed Mar 15 17:31:34 2017 virgile
*/

#include "my.h"
#include "get_next_line.h"

void		my_write_plan(t_data *d, int fd, char *str, t_plan *plan)
{
  int		i;

  i = 0;
  while (i < d->nb_plan)
    {
      plan[i].pos = make_pos(0, 0, 0);
      plan[i].color = edit_color(255, 255, 255, 255);
      plan[i].rotation = make_pos(0, 0, 0);
      while (my_strncmp((str = get_next_line(fd)), "END", 3) == 0 && str != NULL)
	{
	  if (my_strncmp(str, "pos", 3))
	    plan[i].pos = my_load_pos(str);
	  if (my_strncmp(str, "color", 5))
	    plan[i].color = my_load_color(str);
	  if (my_strncmp(str, "rot", 3))
	    plan[i].rotation = my_load_pos(str);
	}
      i++;
    }
}

void		my_load_plan(t_data *d, int fd)
{
  char		*str;
  t_plan	*plan;

  str = get_next_line(fd);
  d->nb_plan = my_getnbr(str);
  if ((plan = malloc(sizeof(*plan) * d->nb_plan + 1)) == NULL)
    plan = NULL;
  my_write_plan(d, fd, str, plan);
  d->plan = plan;
}
