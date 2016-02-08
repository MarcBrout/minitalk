/*
** minitalk.h for minitalk
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Jan 29 15:59:52 2016 marc brout
** Last update Mon Feb  8 15:24:05 2016 marc brout
*/

#ifndef MINITALK_SERVER_H_
# define MINITALK_SERVER_H_

typedef struct	s_server
{
  int		client;
  char		go;
}		t_server;

void receive(int);
void get_pid(int);
int my_put_nbr(int);

#endif /* !MINITALK_SERVER_H_ */
