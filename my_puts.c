/*
** my_puts.c for rtv in /home/chapui_s/rendu/MUL_2013_rtv1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Mar 10 18:23:40 2014 chapui_s
** Last update Mon Mar 10 18:24:35 2014 chapui_s
*/

#include <stdlib.h>
#include <unistd.h>

void		*puterror_null(char *str)
{
  while (str && *str)
    write(2, str++, 1);
  return (NULL);
}

int		puterror(char *str)
{
  while (str && *str)
    write(2, str++, 1);
  return (-1);
}

int		my_putstr(char *str)
{
  while (str && *str)
    write(1, str++, 1);
  return (0);
}
