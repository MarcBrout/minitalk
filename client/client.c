/*
** client.c for minitalk
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Jan 29 20:37:18 2016 marc brout
** Last update Thu Feb 18 23:31:37 2016 marc brout
*/

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "minitalk_client.h"

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
  if ((nb = my_getnbr(av[1])) < 2)
    {
      write(2, "Wrong PID.\n", 12);
      return (-1);
    }
  return (nb);
}

void		ignore(int nb)
{
  static int	i = 0;
  static int	j = 0;

  if (nb == SIGUSR1)
    {
      (g_client.message[i] & (1u << j)) ? kill(g_client.server, SIGUSR1) :
	kill(g_client.server, SIGUSR2);
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

void			send_char(char c)
{
  int			j;

  j = -1;
  while (++j < 8)
    {
      (c & (1u << j)) ? kill(g_client.server, SIGUSR1) :
	kill(g_client.server, SIGUSR2);
      usleep(10000);
    }
}

void			send_pid(char *pid)
{
  int			i;

  i = -1;
  while (pid[++i]);
  while (--i >= 0)
    send_char(pid[i]);
  send_char(0);
}

int			main(int ac, char **av, char **ae)
{
  char			*pid;

  if ((g_client.server = check_args(ac, av, ae)) < 0 ||
      !(pid = put_nb_to_str(getpid())))
    return (1);
  g_client.message = av[2];
  if (signal(SIGUSR1, &ignore) == SIG_ERR ||
      signal(SIGUSR2, &ignore) == SIG_ERR)
    return (1);
  send_pid(pid);
  while (42)
    if (!sleep(5))
      break;
  return (0);
}
