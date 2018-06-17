

NAME = alex

SRC =	main.c \
		lexer/fsm.c \
		lexer/util.c \
		lexer/process_tokens.c \
		lexer/transitions/action_find_tok.c \
		lexer/transitions/action_read_op.c \
		lexer/transitions/action_read_word.c \
		lexer/transitions/action_read_squot.c \
		lexer/transitions/action_read_dquot.c \
		lexer/transitions/action_utils.c \
		parser/binary_tree.c \
		parser/print_ast.c \
		parser/build_ast.c \
		parser/helper.c
		

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
	mkdir -p $(OBJDIR)/lexer/transitions
	mkdir -p $(OBJDIR)/btree
	mkdir -p $(OBJDIR)/parser

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