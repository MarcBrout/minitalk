/*
** minitalk.c for minitalk
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Jan 29 15:36:56 2016 marc brout
** Last update Wed Feb  3 17:32:09 2016 marc brout
*/

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "minitalk.h"
#include "my.h"

void		test(int nb)
{
  static char	c = 0;
  static int	i = 0;
  char		tmp;

  if (nb == SIGUSR1)
    tmp = 1;
  else
    tmp = 0;
  i += 1;
  c = c | tmp << i;
  if (i == 8)
    {
      my_printf("%c", c);
      c = 0;
      i = 0;
    }
}

int		main()
{
  pid_t		pid;

  pid = getpid();
  my_printf("%d\n", pid);
  while (42)
    {
       signal(SIGUSR1, test);
       signal(SIGUSR2, test);
       usleep(100);
    }
  return (0);
}
