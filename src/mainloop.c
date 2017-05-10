/*
** mainloop.c for mainloop in /home/pion_b/courbe
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Fri Dec  2 21:28:36 2016 Virgile
** Last update Wed Mar 15 17:33:09 2017 virgile
*/

#include "my.h"

void                    init_loop(t_data *d)
{
  my_load_map(d);
  d->buffer = my_framebuffer_create(WTH, HGT);
  d->color = sfWhite;
  d->background = sfBlack;
  d->sprite = sfSprite_create();
  d->texture = sfTexture_create(WTH, HGT);
  d->eye_pos.x = -200;
  d->eye_pos.y = 0;
  d->eye_pos.z = 0;
  d->nb_obj = 0;
  if (d->light == NULL)
    d->light = make_default_light(0, 0, 600);
  if (d->nb_sphere > 0)
    d->obj = 0;
  else if (d->nb_plan > 0)
    d->obj = 1;
  else if (d->nb_cone > 0)
    d->obj = 2;
  else if (d->nb_cyl > 0)
    d->obj = 3;
}

void                    my_refresh(t_data *d, sfRenderWindow *window)
{
  full_buffer(d->buffer, d->background);
  my_draw_objects(d);
  sfTexture_updateFromPixels(d->texture, d->buffer->pixels, WTH, HGT, 0, 0);
  sfSprite_setTexture(d->sprite, d->texture, sfTrue);
  sfRenderWindow_drawSprite(window, d->sprite, NULL);
  sfRenderWindow_display(window);
  sfRenderWindow_clear(window, edit_color(255, 0, 0, 0));
}

void                    clean_objects(sfRenderWindow *window, t_data *d)
{
  (void)window;
  sfSprite_destroy(d->sprite);
  d->sprite = sfSprite_create();
  sfTexture_destroy(d->texture);
  d->texture = sfTexture_create(WTH, HGT);
  buffer_destroy(d->buffer);
  d->buffer = my_framebuffer_create(WTH, HGT);
}

sfVector3f		make_position(float x, float y, float z)
{
  sfVector3f		point;

  point.x = x;
  point.y = y;
  point.z = z;
  return (point);
}

int                     mainloop(sfRenderWindow *window, t_data *d)
{
  init_loop(d);
  sfRenderWindow_setFramerateLimit(window, 144);
  while  (sfRenderWindow_isOpen(window))
    {
      my_refresh(d, window);
      while (sfRenderWindow_pollEvent(window, &d->event))
	{
	  events(d, window);
	  my_refresh(d, window);
	  clean_objects(window, d);
	}
    }
  return (0);
}
