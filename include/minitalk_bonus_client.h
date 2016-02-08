/*
** minitalk.h for minitalk
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Jan 29 15:59:52 2016 marc brout
** Last update Mon Feb  8 15:31:19 2016 marc brout
*/

#ifndef MINITALK_BONUS_CLIENT_H_
# define MINITALK_BONUS_CLIENT_H_

# define UNUSED __attribute__((__unused__))

typedef struct		s_client
{
  char			*message;
  char			gotit;
}			t_client;

int check_args(int, char **, char **);
void ignore(int, siginfo_t *, void *);

#endif /* !MINITALK_BONUS_CLIENT_H_ */
