/*
** minitalk.h for minitalk
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Jan 29 15:59:52 2016 marc brout
** Last update Mon Feb  8 11:18:02 2016 marc brout
*/

#ifndef MINITALK_H_
# define MINITALK_H_

# define UNUSED __attribute__((__unused__))

# ifndef SERVER
#  define SERVER

typedef struct		s_server
{
  int			size;
  int			*pidtab;
  char			timeout;
}			t_server;

char change_tab(int, int);
void new_client(int);
void end_client();
void receive(int, siginfo_t *, void *);

# endif /* !SERVER */

# ifndef CLIENT
#  define CLIENT

typedef struct		s_client
{
  char			*message;
  char			gotit;
}			t_client;

int check_args(int, char **, char **);
void ignore(int, siginfo_t *, void *);

# endif /* !CLIENT */

#endif /* !MINITALK_H_ */
