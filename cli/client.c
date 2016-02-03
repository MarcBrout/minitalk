/*
** client.c for minitalk
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Jan 29 20:37:18 2016 marc brout
** Last update Mon Feb  1 11:42:32 2016 marc brout
*/

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "minitalk.h"
#include "my.h"

void		read_str(char *str)
{
  int		i;
  int		c;

  i = -1;
  while (str[i])
    {
      c = -1;
      while (++c < 8)
	if (str[i] & (1u << c))
	  kill(nb, SIGUSR1);
	else
	  kill(nb, SIGUSR2);
    }
}

char		check_args(int ac, char **ae)
{
  if (ac != 3)
    {
      write(2, "Usage: Client [server pid] [message].\n", 39);
      return (1);
    }
  if (!(ae))
    {
      write(2, "Missing environnement variables.\n", 34);
      return (1);
    }
  return (0);
}

int		main(int ac, char **av, char **ae)
{
  int		nb;

  if (check_args(ac, ae))
    return (1);
  if ((nb = my_getnbr(av[1])) > 1)
    {
      read_str(av[2]);
    }
  return (0);
}
