

#ifndef AST_H
# define AST_H


#include <stdio.h>
#include <stdlib.h>
#include "lex.h"



/* AST type symbols */

typedef enum {
	AST_list,
	AST_logic_op,
	AST_and_if,
	AST_and_or,
	AST_pipeline,
	AST_command,
	MAX_AST
}										AstType;


/* AST node */

typedef	struct							s_ast_node
{
	AstType								type;
	union
	{
		// list of tokens that make up command including redirects flags args and command name
		t_list							*cmd; 
		struct
		{
			struct s_ast_node	*left;
			struct s_ast_node	*right;
		} 								op;
	};
}										t_ast_node;


/* binary tree api */

t_ast_node	*make_node(t_list *cmd, AstType type);
void		add_left_child(t_ast_node **parent, t_ast_node *child);
void		add_right_child(t_ast_node **parent, t_ast_node *child);



/* level-traversal print of binary tree */

void		print_level_order(t_ast_node *root);
void		print_given_level(t_ast_node *root, int level);
int			tree_height(t_ast_node *root);

/* recursive descent parser */

int			parse_list(t_list **tokens, t_ast_node **ast);
int			parse_logic_op(t_list **tokens, t_ast_node **ast);
int			parse_pipeline(t_list **tokens, t_ast_node **ast);
int			parse_command(t_list **tokens, t_ast_node **ast);
int			match(t_tok *current, TokType expected);
t_tok		*next_token(t_list **tokens);
t_list		*eat_command(t_list **tokens);
int			is_command(t_list *token);

#endif