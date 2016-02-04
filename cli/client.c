/*
** client.c for minitalk
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Jan 29 20:37:18 2016 marc brout
** Last update Thu Feb  4 00:41:26 2016 marc brout
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
  pause();
  (ch.bits.one) ? kill(nb, SIGUSR1) : kill(nb, SIGUSR2);
  pause();
  (ch.bits.two) ? kill(nb, SIGUSR1) : kill(nb, SIGUSR2);
  pause();
  (ch.bits.tre) ? kill(nb, SIGUSR1) : kill(nb, SIGUSR2);
  pause();
  (ch.bits.fou) ? kill(nb, SIGUSR1) : kill(nb, SIGUSR2);
  pause();
  (ch.bits.fiv) ? kill(nb, SIGUSR1) : kill(nb, SIGUSR2);
  pause();
  (ch.bits.six) ? kill(nb, SIGUSR1) : kill(nb, SIGUSR2);
  pause();
  (ch.bits.sev) ? kill(nb, SIGUSR1) : kill(nb, SIGUSR2);
  pause();
  (ch.bits.eig) ? kill(nb, SIGUSR1) : kill(nb, SIGUSR2);
}

int		check_args(int ac, char **av, char **ae)
{
  int		nb;

  if (ac != 3)
    {
      write(2, "Usage: Client [server pid] [message].\n", 39);
      return (-1);
    }
  if (!(ae))
    {
      write(2, "Missing environnement variables.\n", 34);
      return (-1);
    }
  if ((nb = my_getnbr(av[1])) < 2)
    {
      write(2, "Wrong PID.\n", 12);
      return (-1);
    }
  return (nb);
}

void		ignore(int nb)
{
  if (nb == SIGUSR2)
    exit(0);
}

int		main(int ac, char **av, char **ae)
{
  int		nb;
  int		i;

  if ((nb = check_args(ac, av, ae)) < 0)
    return (1);
  i = -1;
  signal(SIGUSR1, &ignore);
  signal(SIGUSR2, &ignore);
  kill(nb, SIGUSR1);
  while (av[2][++i])
    read_str(av[2][i], nb);
  read_str(0, nb);
  return (0);
}
