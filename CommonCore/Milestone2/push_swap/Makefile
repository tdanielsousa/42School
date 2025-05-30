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

SRCS	= error_checks.c \
       main.c \
	   parsing.c \
       push.c \
       rotate_swap.c \
       sort_utils.c \
       choose_sort.c \
	   radix_sort.c \
	   ft_split.c \
       utils.c

#*********************************************#
#****       Compiler ands flags           ****#
#*********************************************#

CC = cc

CFLAGS = -Wall -Wextra -Werror

#***********************************************#
#***  Remove, lib_name, substitute .c for .o ***#
#***********************************************#

RM = rm --force

NAME = push_swap

OBJS = ${SRCS:.c=.o}

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

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	@echo "\033[1;35m************************************************************\033[0m"
	@echo "\033[1;36m  >>>>>>> The library was successfully built <<<<<<<<\033[0m"
	@echo "\033[1;35m************************************************************\033[0m"

clean:
	$(RM) $(OBJS)
	@echo "\033[1;35m**************************************************************\033[0m"
	@echo "\033[1;36m  >>>>>>> Objects were successfully removed <<<<<<<<\033[0m"
	@echo "\033[1;35m**************************************************************\033[0m"

fclean: clean
	$(RM) $(NAME)
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
	@echo " \033[1;35m>>>>>>> Available targets: <<<<<<<<\033[0m"
	@echo "\033[1;33m >>>>>>>  all      - Build the library <<<<<<<\033[0m"
	@echo "\033[1;33m >>>>>>>  clean    - Remove object files <<<<<<<<\033[0m"
	@echo "\033[1;33m >>>>>>>  fclean   - Remove object files and the library <<<<<<<<\033[0m"
	@echo "\033[1;33m >>>>>>>  re       - Rebuild the library <<<<<<<<\033[0m"
	@echo "\033[1;33m >>>>>>>  bonus    - Library with the bonus files <<<<<<<<\033[0m"
	@echo "\033[1;33m >>>>>>>  tester   - Downloads and runs testers <<<<<<<<\033[0m"
	@echo "\033[1;33m >>>>>>>  tclean   - Removes testers files <<<<<<<<\033[0m"
	@echo "\033[1;33m >>>>>>>  help     - See all targets <<<<<<<<\033[0m"
	@echo "\033[1;35m************************************************************************\033[0m"

#*********************************************#
#****               Norm target            ***#
#*********************************************#

norm:
	norminette
	@echo "\033[1;35m************************************************************\033[0m"
	@echo "\033[1;35m>>>>>>> Norminette success <<<<<<<<\033[0m"
	@echo "\033[1;35m************************************************************\033[0m"


#************************************************#
#****               Tester target            ****#
#************************************************#
#*****               rf for dirs            *****#
#*****               f for files            *****#
#************************************************#

TESTER_REPO = https://github.com/tdanielsousa/push_swap_testers_2025.git

tester:
	rm -rf push_swap_tester_YFU push_tester_GEMARTIN
	rm -f testers.sh README.md push_swap
	git clone $(TESTER_REPO)
	mv push_swap_testers_2025/* .
	rm -rf push_swap_testers_2025
	chmod +x testers.sh
	./testers.sh

tclean:
	rm -rf push_swap_tester_YFU push_tester_GEMARTIN
	rm -f testers.sh README.md   
	rm -f push_swap
	@echo "\033[1;35m*******************************************************\033[0m"
	@echo "\033[1;35m>>>>>>> Testers removed <<<<<<<<\033[0m"
	@echo "\033[1;35m*******************************************************\033[0m"


#*********************************************#
#****    not file names just actions       ***#
#*********************************************#

.PHONY: all clean fclean re help bonus norm tester tclean

#*********************************************#
#*********************************************#
#*********************************************#
