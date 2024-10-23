# Variables
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
NAME = a

# Default rule
all: $(NAME) leaks clean

# Linking
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Compiling
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)

# Memory leaks and errors check
leaks: $(NAME)
	valgrind --leak-check=full \
	         --track-origins=yes \
	         --show-leak-kinds=all \
	         --errors-for-leak-kinds=all \
	         --show-possibly-lost=yes \
	         --track-fds=yes \
	         ./$(NAME)

.PHONY: all clean leaks
