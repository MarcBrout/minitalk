/*
** minitalk.h for minitalk
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Jan 29 15:59:52 2016 marc brout
** Last update Thu Feb  4 00:01:38 2016 marc brout
*/

#ifndef MINITALK_H_
# define MINITALK_H_
# define UNUSED __attribute__((__unused__))

/* 
** Structure décomposée d'un character :
*/

typedef struct		s_bit
{
  unsigned int		one : 1;
  unsigned int		two : 1;
  unsigned int		tre : 1;
  unsigned int		fou : 1;
  unsigned int		fiv : 1;
  unsigned int		six : 1;
  unsigned int		sev : 1;
  unsigned int		eig : 1;
}			t_bit;

/* 
** Union de la structure t_bit et d'un character :
*/

typedef union		u_char
{
  char			c;
  t_bit			bits;
}			t_char;

/*
** Prototypes de fonctions :
*/

#endif /* !MINITALK_H_ */
