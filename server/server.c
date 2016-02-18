/*
** minitalk.c for minitalk
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Jan 29 15:36:56 2016 marc brout
** Last update Tue Feb  9 16:12:31 2016 marc brout
*/

#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "minitalk_server.h"

t_server	g_server;

void		get_pid(int nb)
{
  static int	pow = 1;
  static char	c = 0;
  static int	i = 0;

  if (nb == SIGUSR1)
    c = c | (1u << i);
  i += 1;
  if (i == 8)
    {
      if (c == 0)
	{
	  g_server.go = 1;
	  c = 0;
	  i = 0;
	  pow = 1;
	  return ;
	}
      g_server.client += (c - 48) * pow;
      c = 0;
      i = 0;
      pow *= 10;
    }
}

void		receive(int nb)
{
  static char	c = 0;
  static int	i = 0;

  if (nb == SIGUSR1)
    c = c | (1u << i);
  i += 1;
  if (i == 8 && write(1, &c, 1) >= 0)
    {
      if (c == 0)
	g_server.go = 0;
      c = 0;
      i = 0;
    }
  kill(g_server.client, SIGUSR1);
}

int			main()
{
  my_put_nbr(getpid());
  write(1, "\n", 1);
  while (42)
    {
      g_server.client = 0;
      g_server.go = 0;
      if (signal(SIGUSR1, &get_pid) == SIG_ERR ||
	  signal(SIGUSR2, &get_pid) == SIG_ERR)
	return (1);
      while (!g_server.go)
	sleep(3);
      usleep(50);
      if (signal(SIGUSR1, &receive) == SIG_ERR ||
	  signal(SIGUSR2, &receive) == SIG_ERR)
	return (1);
      kill(g_server.client, SIGUSR1);
      while (g_server.go)
	if (!sleep(3))
	  break;
    }
  return (0);
}
