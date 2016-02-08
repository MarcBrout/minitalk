/*
** minitalk_client.h for minitalk
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Feb  8 15:20:17 2016 marc brout
** Last update Mon Feb  8 15:21:39 2016 marc brout
*/

#ifndef MINITALK_CLIENT_H_
# define MINITALK_CLIENT_H_

typedef struct	s_client
{
  int		server;
  char		*message;
}		t_client;

int my_getnbr(char *);
int check_args(int, char **, char **);
void ignore(int);
void send_char(char);
void send_pid(char *);
char *put_nb_to_str(int);

#endif /* !MINITALK_CLIENT_H_ */
