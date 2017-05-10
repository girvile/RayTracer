/*
** list_event.c for list_event in /home/virgile/raytracer1
** 
** Made by virgile
** Login   <virgile1.pion@epitech.eu>
** 
** Started on  Wed Mar 15 16:55:43 2017 virgile
** Last update Wed Mar 15 16:56:04 2017 virgile
*/

#include "my.h"

void                    events(t_data *d, sfRenderWindow *window)
{
  if (d->event.type == sfEvtClosed ||                   \
      sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
    sfRenderWindow_close(window);
  if (sfKeyboard_isKeyPressed(sfKeyRight))
    move_obj(d);
  if (sfKeyboard_isKeyPressed(sfKeyQ))
    move_leftright(d, -10);
  if (sfKeyboard_isKeyPressed(sfKeyD))
    move_leftright(d, 10);
  if (sfKeyboard_isKeyPressed(sfKeyZ))
    move_forback(d, 10);
  if (sfKeyboard_isKeyPressed(sfKeyS))
    move_forback(d, -10);
  if (sfKeyboard_isKeyPressed(sfKeyUp))
    move_updown(d, 10);
  if (sfKeyboard_isKeyPressed(sfKeyDown))
    move_updown(d, -10);
}
