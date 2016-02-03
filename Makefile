##
## Makefile for minitalk in /home/brout_m/rendu/projet/System_unix/minitalk
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Fri Jan 29 15:30:38 2016 marc brout
## Last update Wed Feb  3 16:42:53 2016 marc brout
##

SRCP	= ./srv/

SRCP2	= ./cli/

SRC     = $(SRCP)server.c

SRC2     = $(SRCP2)client.c

OBJS    = $(SRC:.c=.o)

OBJS2	= $(SRC2:.c=.o)

NAME    = server

NAME2	= client

CC      = gcc -g

CFLAGS  =  -W -Wall -Werror

HDFLAGS = -I./include/

LDFLAGS = -L./lib/ -lmy

RM      = rm -f

.c.o:
	$(CC) -c $< -o $@ $(HDFLAGS) $(CFLAGS)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

$(NAME2): $(OBJS2)
	$(CC) -o $(NAME2) $(OBJS2) $(LDFLAGS)

all: $(NAME) $(NAME2)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS2)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME2)

re: fclean all
