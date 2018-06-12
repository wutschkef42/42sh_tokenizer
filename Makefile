

NAME = alex

SRC =	main.c \
		fsm.c \
		transitions/action_find_tok.c \
		transitions/action_read_op.c \
		transitions/action_read_word.c \
		transitions/action_utils.c

SRCDIR = ./src
OBJDIR = ./obj
INCDIR = ./includes
INCDIR_LFT = ./libft/includes

FTDIR = ./libft
FTLIB = $(addprefix $(FTDIR)/, libft.a)
FTINC = -I $(FTDIR)
FTLNK = -L $(FTDIR) -l ft

OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
CC = gcc
FLAGS = -Wall -Werror -Wextra -g

all: obj $(FTLIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)/transitions

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(FLAGS) $(FTINC) -I $(INCDIR) -I $(INCDIR_LFT) -o $@ -c $<

$(FTLIB):
	make -C $(FTDIR)

$(NAME): $(OBJ) $(FTLIB)
	$(CC) $(FLAGS) $(OBJ) $(FTLNK) -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(FTDIR) fclean

re: fclean all

.PHONY: clean, fclean, re