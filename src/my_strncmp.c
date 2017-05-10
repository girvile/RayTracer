/*
** my_strncmp.c for my_strncmp in /home/virgile/raytracer1
** 
** Made by virgile
** Login   <virgile1.pion@epitech.eu>
** 
** Started on  Tue Feb 14 13:18:48 2017 virgile
** Last update Tue Feb 14 13:21:33 2017 virgile
*/

#include "my.h"

int	my_strncmp(char *str, char *str2, int n)
{
  int	i;

  i = 0;
  if (str == NULL || str2 == NULL)
    return (0);
  while (str[i] && i < n)
    {
      if (str[i] != str2[i])
	return (0);
      i++;
    }
  return (1);
}
