/*
** translate.c for translate in /home/virgile/raytracer1
** 
** Made by virgile
** Login   <virgile1.pion@epitech.eu>
** 
** Started on  Sun Feb 26 20:47:40 2017 virgile
** Last update Sun Feb 26 20:48:58 2017 virgile
*/

#include "my.h"

sfVector3f	translate(sfVector3f to_translate, sfVector3f translations)
{
  to_translate.x += translations.x;
  to_translate.y += translations.y;
  to_translate.z += translations.z;
  return (to_translate);
}
