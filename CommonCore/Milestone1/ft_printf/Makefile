# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 10:37:54 by tdaniel-          #+#    #+#              #
#    Updated: 2024/11/20 10:37:40 by tdaniel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#*********************************************#
#****              sources                ****#
#*********************************************#

SRCS	= ft_print_char.c \
		ft_print_pointer.c \
		ft_print_decimal.c \
		ft_print_hex.c \
		ft_print_string.c \
		ft_printf.c \
		ft_print_percent.c \
		ft_print_unsigned.c

#*********************************************#
#****       Compiler ands flags           ****#
#*********************************************#

CC = cc

CFLAGS = -Wall -Wextra -Werror

#***********************************************#
#***  Remove, lib_name, substitute .c for .o ***#
#***********************************************#

RM = rm --force

NAME = libftprintf.a

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
#****  		  	Targets                    ***#
#*********************************************#
#************    ansi colors   ***************#
#****** 033: ascii escape in octal 033 *******#
#******    [1;35m: ansi color code     *******#
#******        1: text bold            *******#
#******      ;35: color purple         *******#
#*********************************************#

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
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
	@echo "\033[1;33m >>>>>>>  help     - See all targets <<<<<<<<\033[0m"
	@echo "\033[1;35m************************************************************************\033[0m"

#*********************************************#
#****    not file names just actions       ***#
#*********************************************#

.PHONY: all clean fclean re help

#*********************************************#
#*********************************************#
#*********************************************#