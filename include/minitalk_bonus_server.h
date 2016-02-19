/*
** minitalk_bonus_server.h for minitalk
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Feb  8 15:28:14 2016 marc brout
** Last update Fri Feb 19 14:47:52 2016 marc brout
*/

#ifndef MINITALK_BONUS_SERVER_H_
# define MINITALK_BONUS_SERVER_H_

# define UNUSED __attribute__((__unused__))

typedef struct		s_server
{
  int			ret;
  int			size;
  int			*pidtab;
  char			timeout;
}			t_server;

char change_tab(int, int);
int new_client(int);
void end_client();
void receive(int, siginfo_t *, void *);

#endif /* !MINITALK_BONUS_SERVER_H_ */
