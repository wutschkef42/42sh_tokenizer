

NAME = alex

SRC =	main.c \
		memory_stuff.c \
		misc.c \
		lexer/read_input.c \
		lexer/getter_setter_token.c \
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
		parser/getter_setter_ast.c \
		parser/helper.c \
		interpreter/evaluate_ast.c \
		interpreter/event_loop.c \
		interpreter/env.c \
		interpreter/launch_executable.c \
		interpreter/link_executable.c \
		data_structures/hashmap.c \
		data_structures/hashmap_2.c \
		data_structures/hashmap_insert.c \
		data_structures/serialize.c \
		data_structures/doubly_linked_list.c \
		memory_manager/category_functions.c \
		memory_manager/mem_ref_functions.c
		

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
	mkdir -p $(OBJDIR)/parser
	mkdir -p $(OBJDIR)/interpreter
	mkdir -p $(OBJDIR)/data_structures
	mkdir -p $(OBJDIR)/memory_manager

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