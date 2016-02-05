/*
** client.c for minitalk
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Jan 29 20:37:18 2016 marc brout
** Last update Thu Feb  4 18:42:31 2016 marc brout
*/

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "minitalk.h"
#include "my.h"

char		g_bool;

void		read_char(unsigned int c, int nb)
{
  while (g_bool == 0);
  (c) ? kill(nb, SIGUSR1) : kill(nb, SIGUSR2);
  g_bool = 0;
}

void		read_str(char c, int nb)
{
  t_char	ch;

  ch.c = c;
  read_char(ch.bits.one, nb);
  read_char(ch.bits.two, nb);
  read_char(ch.bits.tre, nb);
  read_char(ch.bits.fou, nb);
  read_char(ch.bits.fiv, nb);
  read_char(ch.bits.six, nb);
  read_char(ch.bits.sev, nb);
  read_char(ch.bits.eig, nb);
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

void		ignore(int nb, siginfo_t *siginfo, UNUSED void *data)
{
  static int	server = 0;

  if (!server)
    server = siginfo->si_pid;
  else if (siginfo->si_pid == server)
    {
      if (nb == SIGUSR1)
	g_bool = 1;
      else if (nb == SIGUSR2)
	g_bool = 0;
    }
}

int			main(int ac, char **av, char **ae)
{
  struct sigaction	act;
  int			nb;
  int			i;

  g_bool = 0;
  if ((nb = check_args(ac, av, ae)) < 0)
    return (1);
  i = -1;
  act.sa_sigaction = &ignore;
  act.sa_flags = SA_SIGINFO;
  if (sigaction(SIGUSR1, &act, NULL) < 0 || sigaction(SIGUSR2, &act, NULL) < 0)
    return (1);
  kill(nb, SIGUSR1);
  pause();
  while (av[2][++i])
    read_str(av[2][i], nb);
  read_str(0, nb);
  return (0);
}
