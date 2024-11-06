# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdaniel- <tdaniel-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 10:37:54 by tdaniel-          #+#    #+#              #
#    Updated: 2024/10/28 12:50:15 by tdaniel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#*********************************************#
#****       sources and bonus sources     ****#
#*********************************************#

SRCS	= ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_strdup.c \
		ft_calloc.c \

BONUS_SRCS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstadd_back.c \
		ft_lstlast.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \

#*********************************************#
#****       Compiler ands flags           ****#
#*********************************************#

CC = cc

CFLAGS = -Wall -Wextra -Werror

#*********************************************#
#****   Remove, .o files and name of lib  ****#
#*********************************************#

RM = rm -f

NAME = libft.a

OBJS = ${SRCS:.c=.o}

BONUS_OBJ = ${BONUS_SRCS:.c=.o}

#*********************************************#
#****      Compile .c files to .o         ****#
#*********************************************#

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#*********************************************#
#****  		  	Targets                    ***#
#*********************************************#

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@echo "\033[1;35m**************************************************\033[0m"
	@echo "  >>>>>>> The library was successfully built <<<<<<<<"
	@echo "\033[1;35m**************************************************\033[0m"

clean:
	$(RM) $(OBJS) $(BONUS_OBJ)
	@echo "\033[1;35m*************************************************\033[0m"
	@echo "  >>>>>>> Objects were successfully removed <<<<<<<<"
	@echo "\033[1;35m*************************************************\033[0m"

fclean: clean
	$(RM) $(NAME)
	@echo "\033[1;35m*****************************************************\033[0m"
	@echo "\033[1;36m  >>>>>>> Library successfully removed <<<<<<<<\033[0m"
	@echo "\033[1;35m*****************************************************\033[0m"

re: fclean all
	@echo "\033[1;35m***********************************************\033[0m"
	@echo "\033[1;36m  >>>>>>> Re-do successful <<<<<<<<\033[0m"
	@echo "\033[1;35m***********************************************\033[0m"

bonus: $(NAME) $(BONUS_OBJ)
	@ar rcs $(NAME) $(BONUS_OBJ)
	@echo "\033[1;35m*****************************************************\033[0m"
	@echo "\033[1;36m  >>>>>>> Bonus successfully compiled <<<<<<<<\033[0m"
	@echo "\033[1;35m*****************************************************\033[0m"
	
#*********************************************#
#****     Help target with ansi col        ***#
#*********************************************#

help:
	@echo "\033[1;35m************************************************************************\033[0m"
	@echo " \033[1;35m>>>>>>> Available targets: <<<<<<<<\033[0m"
	@echo "\033[1;33m >>>>>>>  all      - Build the library <<<<<<<\033[0m"
	@echo "\033[1;33m >>>>>>>  clean    - Remove object files <<<<<<<<\033[0m"
	@echo "\033[1;33m >>>>>>>  fclean   - Remove object files and the library <<<<<<<<\033[0m"
	@echo "\033[1;33m >>>>>>>  re       - Rebuild the library <<<<<<<<\033[0m"
	@echo "\033[1;33m >>>>>>>  bonus    - Library with the bonus files <<<<<<<<\033[0m"
	@echo "\033[1;33m >>>>>>>  help     - See all targets <<<<<<<<\033[0m"
	@echo "\033[1;35m************************************************************************\033[0m"

#*********************************************#
#****    not file names just actions       ***#
#*********************************************#

.PHONY: all clean fclean re help bonus

#*********************************************#
#*********************************************#
#*********************************************#
