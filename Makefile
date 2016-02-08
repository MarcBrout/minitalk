##
## Makefile for mysh
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Sun Jan 24 02:16:48 2016 marc brout
## Last update Mon Feb  8 11:38:10 2016 marc brout
##

SRCP		= client/

SRCPSRV		= server/

SRCPBONUSSRV	= bonus/server/

SRCPBONUSCLI	= bonus/client/

SRC     	= $(SRCP)client.c \

SRCSRV  	= $(SRCPSRV)server.c \

SRCBONUSSRV 	= $(SRCPBONUSSRV)server.c \

SRCBONUSCLI	= $(SRCPBONUSCLI)client.c \

OBJS    	= $(SRC:.c=.o)

OBJSRV  	= $(SRCSRV:.c=.o)

BONUSOBJSSRV	= $(SRCBONUSSRV:.c=.o)

BONUSOBJSCLI	= $(SRCBONUSCLI:.c=.o)

NAME    	= client/client

SERVER		= server/server

BONUSSRV	= bonus/server/server

BONUSCLI	= bonus/client/client

CC      	= gcc

CFLAGS  	=  -W -Wall -Werror

HDFLAGS 	= -I./include/

LDFLAGS 	= -L./lib/ -lmy

RM      	= rm -f

.phony: client/client server/server bonus/client/client bonus/server/server

.c.o:
	$(CC) -c $< -o $@ $(HDFLAGS) $(CFLAGS)

$(NAME): $(OBJS) $(SERVER)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

$(SERVER): $(OBJSRV)
	$(CC) -o $(SERVER) $(OBJSRV) $(LDFLAGS)

$(BONUSSRV): $(BONUSOBJSSRV) $(BONUSCLI)
	$(CC) -o $(BONUSSRV) $(BONUSOBJSSRV) $(LDFLAGS)

$(BONUSCLI): $(BONUSOBJSCLI)
	$(CC) -o $(BONUSCLI) $(BONUSOBJSCLI) $(LDFLAGS)

bonus: $(BONUSSRV) $(BONUSCLI)

all: $(NAME) $(SERVER)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJSRV)
	$(RM) $(BONUSOBJSSRV)
	$(RM) $(BONUSOBJSCLI)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(SERVER)
	$(RM) $(BONUSCLI)
	$(RM) $(BONUSSRV)

re: fclean all
