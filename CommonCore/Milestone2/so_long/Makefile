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

SRCS	=  src/main.c \
	src/map_checker.c \
	src/map_reader.c \
	src/pathfinding_validator.c \
	src/free_utils.c \
	src/draw_window.c \
	src/starting_setup.c \
	src/draw_game.c \
	src/player_input.c

#*********************************************#
#****       Libft and Mlx                 ****#
#*********************************************#

LIBFT = ./libs/libft/libft.a
MINILIBX = ./libs/minilibx-linux/libmlx_Linux.a
MLXFLAGS = -L ./libs/minilibx-linux -lm -lmlx -Ilmlx -lXext -lX11

#*********************************************#
#****       Compiler ands flags           ****#
#*********************************************#

CC = cc

CFLAGS = -Wall -Wextra -Werror

#***********************************************#
#***  Remove, lib_name, substitute .c for .o ***#
#***********************************************#

RM = rm --force

NAME = so_long

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
	
$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	@echo "\033[1;35m************************************************************\033[0m"
	@echo "\033[1;36m  >>>>>>> The library was successfully built <<<<<<<<\033[0m"
	@echo "\033[1;35m************************************************************\033[0m"

$(LIBFT):
	$(MAKE) -C ./libs/libft/

$(MINILIBX):
	$(MAKE) -C ./libs/minilibx-linux

clean:
	$(RM) $(OBJS)
	$(MAKE) -C ./libs/libft clean
	@echo "\033[1;35m**************************************************************\033[0m"
	@echo "\033[1;36m  >>>>>>> Objects were successfully removed <<<<<<<<\033[0m"
	@echo "\033[1;35m**************************************************************\033[0m"

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ./libs/libft fclean
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
	@echo "\033[1;33m >>>>>>>  tester   - Run maps tests <<<<<<<<\033[0m"
	@echo "\033[1;33m >>>>>>>  tclean   - Clean testers <<<<<<<<\033[0m"
	@echo "\033[1;33m >>>>>>>  help     - See all targets <<<<<<<<\033[0m"
	@echo "\033[1;35m************************************************************************\033[0m"

#*********************************************#
#****               Norm target            ***#
#*********************************************#

norm:
	norminette src/ libs/libft/
	@echo "\033[1;35m************************************************************\033[0m"
	@echo "\033[1;36m>>>>>>> Norminette success <<<<<<<<\033[0m"
	@echo "\033[1;35m************************************************************\033[0m"
	
#************************************************#
#****               Testers target            ***#
#************************************************#

TESTER_REPO = https://github.com/tdanielsousa/so_long_tester.git

tester:
	rm -rf so_long_tester
	rm -f tester.sh
	git clone $(TESTER_REPO)
	rm -rf maps
	mv so_long_tester/* .
	rm -rf so_long_tester
	rm so_long
	make clean
	make
	chmod +x tester.sh
	./tester.sh
	@echo "\033[1;35m*******************************************************\033[0m"
	@echo "\033[1;36m>>>>>>> Tests ran successfully <<<<<<<<\033[0m"
	@echo "\033[1;35m*******************************************************\033[0m"

tclean:
	rm -rf so_long_tester
	rm -f tester.sh
	rm -rf maps
	mkdir maps
	rm so_long
	make clean
	@echo "\033[1;35m*******************************************************\033[0m"
	@echo "\033[1;36m>>>>>>> Testers removed <<<<<<<<\033[0m"
	@echo "\033[1;35m*******************************************************\033[0m"
		
#*********************************************#
#****    not file names just actions       ***#
#*********************************************#

.PHONY: all clean fclean re help norm tester tclean

#*********************************************#
#*********************************************#
#*********************************************#
