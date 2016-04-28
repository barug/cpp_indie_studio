##
## Makefile for cpp_indie_studio in /home/dupard_e/rendus/cpp_indie_studio/source
## 
## Made by Erwan Dupard
## Login   <dupard_e@epitech.net>
## 
## Started on  Wed Apr 27 12:35:04 2016 Erwan Dupard
## Last update Thu Apr 28 17:20:10 2016 Thomas Bogard
##

CC		= g++

RM		= rm -f

CXXFLAGS	+= -I./include -I/usr/X11R6/include

CPPFLAGS	+= -L/usr/X11R6/lib$(LIBSELECT) -L./lib -lIrrlicht -lGL -lGLU -lXrandr -lXext -lX11 -lXxf86vm

NAME		= cpp_indie_studio

SRCS		= Main.cpp		\

OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CXXFLAGS) $(CPPFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

#multilib handling
ifeq ($(HOSTTYPE), x86_64)
LIBSELECT	= 64
endif
#solaris real-time features
ifeq ($(HOSTTYPE), sun4)
LDFLAGS 	+= -lrt
endif

