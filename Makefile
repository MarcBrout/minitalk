##
## Makefile for mysh
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Sun Jan 24 02:16:48 2016 marc brout
## Last update Mon Feb  8 15:17:11 2016 marc brout
##

SRCP		= client/

SRCPSRV		= server/

SRCPBONUSSRV	= bonus/server/

SRCPBONUSCLI	= bonus/client/

SRC     	= $(SRCP)client.c \
		$(SRCP)my_putnbr_to_str.c \
		$(SRCP)my_getnbr.c

SRCSRV  	= $(SRCPSRV)server.c \
		$(SRCPSRV)my_put_nbr.c

SRCBONUSSRV 	= $(SRCPBONUSSRV)server.c \

SRCBONUSCLI	= $(SRCPBONUSCLI)client.c \

OBJS    	= $(SRC:.c=.o)

OBJSRV  	= $(SRCSRV:.c=.o)

BONUSOBJSSRV	= $(SRCBONUSSRV:.c=.o)

BONUSOBJSCLI	= $(SRCBONUSCLI:.c=.o)

CLIENT    	= client/client

SERVER		= server/server

BONUSSRV	= bonus/server/server

BONUSCLI	= bonus/client/client

CC      	= gcc

CFLAGS  	=  -W -Wall -Werror

HDFLAGS 	= -I./include/

LDFLAGS 	= 

RM      	= rm -f

.phony: client/client server/server bonus/client/client bonus/server/server

.c.o:
	$(CC) -c $< -o $@ $(HDFLAGS) $(CFLAGS)

$(CLIENT): $(OBJS) $(SERVER)
	$(CC) -o $(CLIENT) $(OBJS) $(LDFLAGS)

$(SERVER): $(OBJSRV)
	$(CC) -o $(SERVER) $(OBJSRV) $(LDFLAGS)

$(BONUSCLI): $(BONUSSRV) $(BONUSOBJSCLI)
	$(CC) -o $(BONUSCLI) $(BONUSOBJSCLI) $(LDFLAGS)

$(BONUSSRV): $(BONUSOBJSSRV)
	$(CC) -o $(BONUSSRV) $(BONUSOBJSSRV) $(LDFLAGS)

all: $(CLIENT) $(SERVER)

bonus: $(BONUSCLI) $(BONUSSRV)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJSRV)
	$(RM) $(BONUSOBJSSRV)
	$(RM) $(BONUSOBJSCLI)

fclean: clean
	$(RM) $(CLIENT)
	$(RM) $(SERVER)
	$(RM) $(BONUSCLI)
	$(RM) $(BONUSSRV)

re: fclean all
