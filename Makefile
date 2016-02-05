##
## Makefile for mysh
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Sun Jan 24 02:16:48 2016 marc brout
## Last update Fri Feb  5 18:31:23 2016 marc brout
##

SRCP	= client/

SRCPSRV	= server/

SRC     = $(SRCP)client.c \

SRCSRV  = $(SRCPSRV)server.c \

OBJS    = $(SRC:.c=.o)

OBJSRV  = $(SRCSRV:.c=.o)

NAME    = client/client

SERVER	= server/server

CC      = gcc

CFLAGS  =  -W -Wall -Werror

HDFLAGS = -I./include/

LDFLAGS = -L./lib/ -lmy

RM      = rm -f

.phony: client/client server/server

.c.o:
	$(CC) -c $< -o $@ $(HDFLAGS) $(CFLAGS)

$(NAME): $(OBJS) $(SERVER)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

$(SERVER): $(OBJSRV)
	$(CC) -o $(SERVER) $(OBJSRV) $(LDFLAGS)

all: $(NAME) $(SERVER)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJSRV)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(SERVER)

re: fclean all
