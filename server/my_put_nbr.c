/*
** my_put_nbr.c for my_put_nbr in ~/rendu/Piscine_C_J10
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Oct 12 19:37:45 2015 marc brout
** Last update Mon Feb  8 15:00:40 2016 marc brout
*/

#include <unistd.h>

int	my_put_nbr(int nb)
{
  int	power;
  int	stock;
  char	c;

  power = 1;
  stock = nb;
  while ((nb / 10) > 0)
    {
      power = power * 10;
      nb = nb / 10;
    }
  while ((power / 10) > 0)
    {
      c = (stock / power) + 48;
      write(1, &c, 1);
      stock = stock - ((stock / power) * power);
      power = power / 10;
    }
  c = (stock % 10) + 48;
  write(1, &c, 1);
  return (0);
}
