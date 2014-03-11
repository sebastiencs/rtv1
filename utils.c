/*
** utils.c for rtv in /home/chapui_s/rendu/MUL_2013_rtv1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Mar 10 18:43:57 2014 chapui_s
** Last update Mon Mar 10 18:46:03 2014 chapui_s
*/

void		swap_int(int *a, int *b)
{
  int		tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

int		val_abs(int n)
{
  if (n < 0)
    return (-n);
  return (n);
}
