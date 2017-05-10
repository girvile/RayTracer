/*
** my_line.c for my_line in /home/pion_b/wireframe
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Wed Nov 23 00:19:48 2016 Virgile
** Last update Wed Mar 15 17:29:29 2017 virgile
*/

#include "my.h"

void		my_pline(t_my_framebuffer *framebuffer,			\
			 sfVector2i from, sfVector2i to, sfColor color)
{
  sfVector2i	tmp;
  float		coef;

  tmp.x = from.x;
  tmp.y = from.y;
  coef = get_coef(from.x, to.x, from.y, to.y);
  while ((tmp.x++ < to.x && coef < 1 && coef >= 0)       \
         ||(tmp.x < to.x && coef < 0 && coef > -1))
    {
      tmp.y = to.y + ((tmp.x - to.x) * coef);
      my_pixel(framebuffer, tmp.x, tmp.y, color);
      (coef <= 0) ? (my_pixel(framebuffer, tmp.x, tmp.y - 1, color)) :	\
	(my_pixel(framebuffer, tmp.x, tmp.y + 1, color));
    }
  while ((tmp.y++ < to.y && coef >= 1 && coef != 0) ||	\
	 (tmp.y > to.y && coef <= -1 && coef != 0))
    {
      tmp.x = to.x + ((tmp.y - to.y) / coef);
      my_pixel(framebuffer, tmp.x, tmp.y, color);
      if (tmp.y < to.y)
	my_pixel(framebuffer, tmp.x - 1, tmp.y, color);
    }
}

void		my_line(t_my_framebuffer *framebuffer, sfVector2i from, \
		sfVector2i to, sfColor color)
{
  sfVector2i	tmp;

  if (to.x < from.x)
    {
      tmp.x = to.x;
      to.x = from.x;
      from.x = tmp.x;
      tmp.y = to.y;
      to.y = from.y;
      from.y = tmp.y;
    }
  my_pline(framebuffer, from, to, color);
}
