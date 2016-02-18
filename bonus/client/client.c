/*
** client.c for minitalk
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Jan 29 20:37:18 2016 marc brout
** Last update Thu Feb 18 23:34:53 2016 marc brout
*/

#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "minitalk_bonus_client.h"

t_client	g_client;

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
  if ((nb = atoi(av[1])) < 2)
    {
      write(2, "Wrong PID.\n", 12);
      return (-1);
    }
  return (nb);
}

void		ignore(int nb, siginfo_t *siginfo, UNUSED void *data)
{
  static int	server = 0;
  static int	i = 0;
  static int	j = 0;

  if (!server)
    {
      server = siginfo->si_pid;
      g_client.gotit = 1;
    }
  if (siginfo->si_pid == server && nb == SIGUSR1)
    {
      (g_client.message[i] & (1u << j)) ?
      kill(server, SIGUSR1) : kill(server, SIGUSR2);
      j += 1;
      if (!g_client.message[i] && j == 8)
	exit(0);
      if (j == 8)
	{
	  i += 1;
	  j = 0;
	}
    }
}

int			main(int ac, char **av, char **ae)
{
  struct sigaction	act;
  int			nb;

  if ((nb = check_args(ac, av, ae)) < 0)
    return (1);
  g_client.gotit = 0;
  g_client.message = av[2];
  act.sa_sigaction = &ignore;
  act.sa_flags = SA_SIGINFO;
  if (sigaction(SIGUSR1, &act, NULL) < 0 || sigaction(SIGUSR2, &act, NULL) < 0)
    return (1);
  while (g_client.gotit == 0)
    {
      kill(nb, SIGUSR1);
      sleep(1);
    }
  while (42)
    if (!sleep(120))
      break;
  return (0);
}
