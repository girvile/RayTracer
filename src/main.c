/*
** main.c for main in /home/pion_b/graph
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Sun Nov 13 21:41:37 2016 Virgile
** Last update Sun Feb 26 03:30:39 2017 virgile
*/

#include "my.h"
#include <stdio.h>

sfColor			edit_color(int a, int r, int g, int b)
{
  sfColor		color;

  color.a = a;
  color.r = r;
  color.g = g;
  color.b = b;
  return (color);
}

void			full_buffer(t_my_framebuffer *framebuffer, sfColor color)
{
  int			i;
  int			max;

  max = framebuffer->width * framebuffer->height;
  i = 0;
  while (i < max)
    {
      framebuffer->pixels[i * 4] = color.r;
      framebuffer->pixels[i * 4 + 1] = color.g;
      framebuffer->pixels[i * 4 + 2] = color.b;
      framebuffer->pixels[i * 4 + 3] = color.a;
      i++;
    }
}

int			main(int ac, char **av)
{
  sfVideoMode		mode;
  sfRenderWindow	*window;
  t_data		*data;

  if ((data = malloc(sizeof(*data))) == NULL)
    return (84);
  if (av[1] == NULL)
    return (84);
  data->path = av[1];
  (void)ac;
  (void)av;
  mode.width = WTH;
  mode.height = HGT;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
  if (window == NULL)
    return (84);
  mainloop(window, data);
  sfRenderWindow_destroy(window);
  return (0);
}
