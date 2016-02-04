/*
** minitalk.c for minitalk
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Jan 29 15:36:56 2016 marc brout
** Last update Thu Feb  4 18:02:50 2016 marc brout
*/

#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include "minitalk.h"
#include "my.h"

int		*g_pidtab;

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
      while (g_pidtab[++i] != -1)
	tmp[i] = g_pidtab[i];
      tmp[size] = -1;
    }
  else
    {
      i = 0;
      j = -1;
      while (g_pidtab[++i] != -1)
	tmp[++j] = g_pidtab[i];
      tmp[size] = -1;
    }
  free(g_pidtab);
  g_pidtab = tmp;
  return (0);
}

void		new_client(int client, int *size)
{
  *size += 1;
  if (change_tab(*size, 1))
    exit(1);
  usleep(100);
  if (g_pidtab[0] > 1)
    kill(g_pidtab[0], SIGUSR2);
  g_pidtab[*size - 1] = client;
}

void		end_client(char c, int *size)
{
  if (!(c))
    {
      *size -= 1;
      write(1, "\n", 1);
      if (change_tab(*size, 0))
	exit(1);
      usleep(1);
    }
}

void		receive(int nb, siginfo_t *siginfo, UNUSED void *data)
{
  static char	c = 0;
  static int	size = 0;
  static int	i = 0;
  char		tmp;

  if (siginfo->si_pid != g_pidtab[0])
    new_client(siginfo->si_pid, &size);
  else if (g_pidtab[0] > 1)
    {
      tmp = 1;
      if (nb == SIGUSR1)
	c = c | (tmp << i);
      i += 1;
      if (i == 8 && write(1, &c, 1) >= 0)
	{
	  end_client(c, &size);
	  c = 0;
	  i = 0;
	}
    }
  if (g_pidtab[0] > 1)
    kill(g_pidtab[0], SIGUSR1);
}

int			main()
{
  struct sigaction	act;
  struct timespec	reg;

  if (!(g_pidtab = malloc(sizeof(int))))
    return (1);
  g_pidtab[0] = -1;
  act.sa_sigaction = &receive;
  act.sa_flags = SA_SIGINFO;
  reg.tv_sec = 0;
  reg.tv_nsec = 15000000;
  my_printf("%d\n", getpid());
  if (sigaction(SIGUSR1, &act, NULL) < 0 || sigaction(SIGUSR2, &act, NULL) < 0)
    return (1);
  while (42)
    if (!nanosleep(&reg, NULL))
      if (g_pidtab[0] > 1)
	kill(g_pidtab[0], SIGUSR1);
  return (0);
}
