/*
** minitalk.c for minitalk
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Jan 29 15:36:56 2016 marc brout
** Last update Mon Feb  1 11:44:46 2016 marc brout
*/

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "minitalk.h"
#include "my.h"

void		test(int nb)
{
  if (nb == SIGUSR1)
    my_printf("1\n");
  else
    my_printf("0\n");
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
    }
  return (0);
}
