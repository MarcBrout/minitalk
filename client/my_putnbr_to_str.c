/*
** my_putnbr_to_str.c for minitalk
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Feb  8 14:46:46 2016 marc brout
** Last update Mon Feb  8 14:49:37 2016 marc brout
*/

#include <stdlib.h>

char		*put_nb_to_str(int nb)
{
  char		*str;
  int		unit;
  int		power;
  int		stock;

  power = 1;
  stock = nb;
  unit = 1;
  while ((nb / 10) > 0)
    {
      power = power * 10;
      nb = nb / 10;
      unit += 1;
    }
  if (!(str = malloc(unit + 1)) || (str[unit] = 0) || !(unit = -1))
    return (NULL);
  while ((++unit) >= 0 && (power / 10) > 0)
    {
      str[unit] = (stock / power) + 48;
      stock = stock - ((stock / power) * power);
      power = power / 10;
    }
  str[unit] = stock % 10 + 48;
  return (str);
}
