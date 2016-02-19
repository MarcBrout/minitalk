/*
** minitalk.c for minitalk
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Jan 29 15:36:56 2016 marc brout
** Last update Fri Feb 19 16:01:13 2016 marc brout
*/

#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "minitalk_bonus_server.h"

t_server	g_serv;

char		change_tab(int size, int action)
{
  int		*tmp;
  int		j;
  int		i;

  if (!(tmp = malloc(sizeof(int) * (size + 1))))
    return (1);
  if (action)
    {
      i = -1;
      while (g_serv.pidtab[++i] != -1)
	tmp[i] = g_serv.pidtab[i];
      tmp[size] = -1;
    }
  else
    {
      i = 0;
      j = -1;
      while (g_serv.pidtab[++i] != -1)
	tmp[++j] = g_serv.pidtab[i];
      tmp[size] = -1;
    }
  free(g_serv.pidtab);
  g_serv.pidtab = tmp;
  return (0);
}

int		new_client(int client)
{
  int		i;

  i = -1;
  while (g_serv.pidtab[++i] != -1)
    if (g_serv.pidtab[i] == client)
      break;
  if (g_serv.pidtab[i] == -1)
    {
      usleep(10000);
      kill(client, SIGUSR2);
      g_serv.size += 1;
      if (change_tab(g_serv.size, 1))
	exit(1);
      g_serv.pidtab[g_serv.size - 1] = client;
      if (i > 0)
	return (1);
    }
  return (0);
}

void		end_client()
{
  g_serv.size -= 1;
  if (change_tab(g_serv.size, 0))
    exit(1);
}

void		receive(int nb, siginfo_t *siginfo, UNUSED void *data)
{
  static char	c = 0;
  static int	i = 0;
  char		tmp;

  g_serv.ret = 0;
  if (g_serv.timeout && !(c = 0) && !(i = 0))
    g_serv.timeout = 0;
  if (siginfo->si_pid != g_serv.pidtab[0])
    g_serv.ret = new_client(siginfo->si_pid);
  else if (g_serv.pidtab[0] > 1)
    {
      tmp = 1;
      if (nb == SIGUSR1)
	c = c | (tmp << i);
      i += 1;
      if (i == 8 && write(1, &c, 1) >= 0)
	{
	  if (c == 0)
	    end_client();
	  c = 0;
	  i = 0;
	}
    }
  if (g_serv.pidtab[0] > 1 && !g_serv.ret)
    kill(g_serv.pidtab[0], SIGUSR1);
}

int			main()
{
  struct sigaction	act;

  if (!(g_serv.pidtab = malloc(sizeof(int))))
    return (1);
  g_serv.timeout = 0;
  g_serv.pidtab[0] = -1;
  g_serv.size = 0;
  sigemptyset(&act.sa_mask);
  act.sa_sigaction = &receive;
  act.sa_flags = SA_SIGINFO;
  printf("%d\n", getpid());
  if (sigaction(SIGUSR1, &act, NULL) < 0 || sigaction(SIGUSR2, &act, NULL) < 0)
    return (1);
  while (42)
    if (!sleep(2) && g_serv.pidtab[0] > 1)
      {
	g_serv.timeout = 1;
	g_serv.ret = 0;
	change_tab(--g_serv.size, 0);
	usleep(10000);
	if (g_serv.pidtab[0] > 1)
	  kill(g_serv.pidtab[0], SIGUSR1);
      }
  return (0);
}
