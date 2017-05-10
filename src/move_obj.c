/*
** move_obj.c for move_obj in /home/virgile/raytracer1
** 
** Made by virgile
** Login   <virgile1.pion@epitech.eu>
** 
** Started on  Fri Feb 17 01:23:12 2017 virgile
** Last update Fri Feb 17 01:26:28 2017 virgile
*/

#include "my.h"

void			move_sphere(t_data *d)
{
      if (d->nb_obj + 1< d->nb_sphere)
	{
	  d->nb_obj++;
	}
      else
	{
	  d->nb_obj = 0;
	  if (d->nb_plan > 0)
	    d->obj = 1;
	  else if (d->nb_cone > 0)
	    d->obj = 2;
	  else if (d->nb_cyl > 0)
	    d->obj = 3;
	}
}

void			move_plan(t_data *d)
{
       if (d->nb_obj + 1 < d->nb_plan)
	{
	  d->nb_obj++;
	}
      else
	{
	  d->nb_obj = 0;
	  if (d->nb_cone > 0)
	    d->obj = 2;
	  else if (d->nb_cyl > 0)
	    d->obj = 3;
	  else if (d->nb_sphere > 0)
	    d->obj = 0;
	}
}

void			move_cone(t_data *d)
{
    if (d->nb_obj + 1 < d->nb_cone)
	{
	  d->nb_obj++;
	}
      else
	{
	  d->nb_obj = 0;
	  if (d->nb_cyl > 0)
	    d->obj = 3;
	  else if (d->nb_sphere > 0)
	    d->obj = 0;
	  else if (d->nb_plan > 0)
	    d->obj = 1;
	}
}

void			move_cyl(t_data *d)
{
       if (d->nb_obj + 1 < d->nb_cyl)
	{
	  d->nb_obj++;
	}
      else
	{
	  d->nb_obj = 0;
	  if (d->nb_sphere > 0)
	    d->obj = 0;
	  else if (d->nb_plan > 0)
	    d->obj = 1;
	  else if (d->nb_cone > 0)
	    d->obj = 2;
	}
}

void                    move_obj(t_data *d)
{
  if (d->obj == 0)
    move_sphere(d);
  else if (d->obj == 1)
    move_plan(d);
  else if (d->obj == 2)
    move_cone(d);
  else if (d->obj == 3)
    move_cyl(d);
}
