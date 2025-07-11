# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/01 03:07:29 by tdaniel-          #+#    #+#              #
#    Updated: 2025/05/06 10:39:54 by tdaniel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#*********************************************#
#****              sources                ****#
#*********************************************#

SRCS1	=  src/client.c
	
SRCS2	=  src/server.c

#*********************************************#
#******        Libft                    ******#
#*********************************************#

LIBFT = ./libft/libft.a

#*********************************************#
#****       Compiler ands flags           ****#
#*********************************************#

CC = cc

CFLAGS = -Wall -Wextra -Werror

#***********************************************#
#***  Remove, lib_name, substitute .c for .o ***#
#***********************************************#

RM = rm --force

NAME1 = client

NAME2 = server

OBJS1 = ${SRCS1:.c=.o}
OBJS2 = ${SRCS2:.c=.o}

#*********************************************#
#****      Compile .c files to .o         ****#
#*********************************************#
#***  For any .c file create a .o file    ****#
#***        -c - compile only             ****#
#***     $< input   ---  $@ output        ****#
#*********************************************#

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#*********************************************#
#****  		Targets                    ***#
#*********************************************#
#************    ansi colors   ***************#
#****** 033: ascii escape in octal 033 *******#
#******    [1;35m: ansi color code     *******#
#******        1: text bold            *******#
#******      ;35: color purple         *******#
#*********************************************#

all: $(NAME1) $(NAME2)
	
$(NAME1): $(OBJS1) $(LIBFT)
	$(CC) $(OBJS1) $(LIBFT) -o $(NAME1)
	@echo "\033[1;35m************************************************************\033[0m"
	@echo "\033[1;36m  >>>>>>> The library was successfully built <<<<<<<<\033[0m"
	@echo "\033[1;35m************************************************************\033[0m"

$(NAME2): $(OBJS2) $(LIBFT)
	$(CC) $(OBJS2) $(LIBFT) -o $(NAME2)
	@echo "\033[1;35m************************************************************\033[0m"
	@echo "\033[1;36m  >>>>>>> The library was successfully built <<<<<<<<\033[0m"
	@echo "\033[1;35m************************************************************\033[0m"

$(LIBFT):
	$(MAKE) -C ./libft/

clean:
	$(RM) $(OBJS1) $(OBJS2)
	$(MAKE) -C ./libft clean
	@echo "\033[1;35m**************************************************************\033[0m"
	@echo "\033[1;36m  >>>>>>> Objects were successfully removed <<<<<<<<\033[0m"
	@echo "\033[1;35m**************************************************************\033[0m"

fclean: clean
	$(RM) $(NAME1) $(NAME2)
	$(MAKE) -C ./libft fclean
	@echo "\033[1;35m*****************************************************\033[0m"
	@echo "\033[1;36m  >>>>>>> Library successfully removed <<<<<<<<\033[0m"
	@echo "\033[1;35m*****************************************************\033[0m"

re: fclean all
	@echo "\033[1;35m***********************************************\033[0m"
	@echo "\033[1;36m  >>>>>>> Re-do successful <<<<<<<<\033[0m"
	@echo "\033[1;35m***********************************************\033[0m"

#*********************************************#
#**************    ar flags    ***************#
#****  r replaces or adds object files *******#
#****  c creates lib if it doesn't exist  ****#
#****     s flag creates an index      *******#
#*********************************************#
#*********************************************#
#****               Help target            ***#
#*********************************************#

help:
	@echo "\033[1;35m************************************************************************\033[0m"
	@echo "\033[1;35m >>>>>>> Available targets: <<<<<<<<\033[0m"
	@echo "\033[1;33m >>>>>>>  all      - Build the library <<<<<<<\033[0m"
	@echo "\033[1;33m >>>>>>>  clean    - Remove object files <<<<<<<<\033[0m"
	@echo "\033[1;33m >>>>>>>  fclean   - Remove object files and the library <<<<<<<<\033[0m"
	@echo "\033[1;33m >>>>>>>  re       - Rebuild the library <<<<<<<<\033[0m"
	@echo "\033[1;33m >>>>>>>  norm     - Run norm on proj and depedencies <<<<<<<<\033[0m"
	@echo "\033[1;33m >>>>>>>  help     - See all targets <<<<<<<<\033[0m"
	@echo "\033[1;33m >>>>>>>  normlink - G var explained <<<<<<<<\033[0m"
	@echo "\033[1;35m************************************************************************\033[0m"

#*********************************************#
#****               Norm target            ***#
#*********************************************#

norm:
	norminette src/ libft/
	@echo "\033[1;35m************************************************************\033[0m"
	@echo "\033[1;36m>>>>>>> Norminette success <<<<<<<<\033[0m"
	@echo "\033[1;35m************************************************************\033[0m"
	
	
#*********************************************#
#****               Norm target            ***#
#*********************************************#

normlink:
	@echo "\033[1;35m************************************************************\033[0m"
	@echo "\033[1;36m>>>>>>> https://github.com/42School/norminette/releases <<<<<<<<\033[0m"
	@echo "\033[1;36m>>>>>>> 3.3.50 Big update again: <<<<<<<<\033[0m"
	@echo "\033[1;36m>>>>>>> A notice pops up when a student uses a global, inviting <<<<<<<<\033[0m"
	@echo "\033[1;36m>>>>>>> justification for the use of said global. This notice <<<<<<<<\033[0m"
	@echo "\033[1;36m>>>>>>> won't trigger the moulinette error and is just here <<<<<<<<\033[0m"
	@echo "\033[1;36m>>>>>>> to spark discussion between students. <<<<<<<<\033[0m"
	@echo "\033[1;35m************************************************************\033[0m"
	


#*********************************************#
#****    not file names just actions       ***#
#*********************************************#

.PHONY: all clean fclean re help norm normlink

#*********************************************#
#*********************************************#
#*********************************************#
