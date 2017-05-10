/*
** my_parse_nb.c for pase_nb in /home/virgile/raytracer1
** 
** Made by virgile
** Login   <virgile1.pion@epitech.eu>
** 
** Started on  Tue Feb 14 14:32:50 2017 virgile
** Last update Tue Feb 14 14:40:25 2017 virgile
*/

#include "my.h"

int	parse_nb(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str[i] != '-' &&		\
	 str[i] != '+' && (str[i] < '0' || str[i] > '9'))
    i++;
  return (my_getnbr(&str[i]));
}
