/*
** client.c for minitalk
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Jan 29 20:37:18 2016 marc brout
** Last update Wed Feb  3 17:22:54 2016 marc brout
*/

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "minitalk.h"
#include "my.h"

void		read_str(char c, int nb)
{
  t_char	ch;

  ch.c = c;
  (ch.bits.one) ? kill(nb, SIGUSR1) : kill(nb, SIGUSR2);
  usleep(350);
  (ch.bits.two) ? kill(nb, SIGUSR1) : kill(nb, SIGUSR2);
  usleep(350);
  (ch.bits.tre) ? kill(nb, SIGUSR1) : kill(nb, SIGUSR2);
  usleep(350);
  (ch.bits.fou) ? kill(nb, SIGUSR1) : kill(nb, SIGUSR2);
  usleep(350);
  (ch.bits.fiv) ? kill(nb, SIGUSR1) : kill(nb, SIGUSR2);
  usleep(350);
  (ch.bits.six) ? kill(nb, SIGUSR1) : kill(nb, SIGUSR2);
  usleep(350);
  (ch.bits.sev) ? kill(nb, SIGUSR1) : kill(nb, SIGUSR2);
  usleep(350);
  (ch.bits.eig) ? kill(nb, SIGUSR1) : kill(nb, SIGUSR2);
  usleep(350);
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
  int		i;

  if (check_args(ac, ae))
    return (1);
  if ((nb = my_getnbr(av[1])) > 1)
    {
      i = -1;
      while (av[2][++i])
	read_str(av[2][i], nb);
    }
  return (0);
}
