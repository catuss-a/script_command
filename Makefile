##
## Makefile for Makefile in /home/catuss_a//Desktop/my_script
## 
## Made by axel catusse
## Login   <catuss_a@epitech.net>
## 
## Started on  Fri Feb 25 17:42:01 2011 axel catusse
## Last update Sat Feb 26 23:33:47 2011 axel catusse
##

NAME		=	my_script

CC		=	gcc

RM		=       rm -f

CFLAGS		+=	-W -Wall

LDFLAGS		=	-lutil

OBJS		=	$(SRCS:.c=.o)

################################################################################################
SRCS		=	main.c				\
			get_options.c			\
			print_usage.c			\
			my_signal.c			\
			write_on_master.c		\
			exec_shell.c			\
			read_on_master.c		\
			print_start.c			\
			set_tty_cfg.c			\
			xfork.c				\
			get_ptr_sct.c			\
			my_openpty.c			

################################################################################################
$(NAME)		:	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAGS)

all             :       $(NAME)

clean           :
		$(RM) $(OBJS)
		rm -rf *~
		rm -rf *#

fclean		:	clean
		$(RM) $(NAME)

re              :       fclean all

.c.o		:
		$(CC) $(CFLAGS) -c $< -o $@

.PHONY		:	all clean fclean re

.SUFFIXES	:	.c .o
################################################################################################