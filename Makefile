##
## Makefile for Makefile in /home/t3i/06nov/ngo_t
## 
## Made by NGO tri
## Login   <ngo_t@etna-alternance.net>
## 
## Started on  Tue Nov  7 05:47:34 2017 NGO tri
## Last update Fri Nov 10 22:35:42 2017 NGO tri
##

MY_FUNC =       my_ftl

SRC =		air_shed.c \
		container.c \
		main.c \
		my_string.c \
		system_control.c \
		system_repair.c \
		readline.c \
		ran.c \
		gameplay.c \
		cbt.c \
		bonus.c


OBJ =           $(SRC:.c=.o)
RM =            rm -f


all:	$(MY_FUNC)

$(MY_FUNC):	$(OBJ)
	gcc -W -Wall -Werror $(OBJ) -o $(MY_FUNC)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(MY_FUNC)

re:    	fclean all

.PHONY:
