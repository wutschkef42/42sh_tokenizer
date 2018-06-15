
/*
	tree data structure with k-many children per node, k variable
	the first level of the tree has one node per ; separated command
	the second level of the tree has one node per &&,|| separated sub_command
	the third level has one node per word (cmd_name, redirect, argument or flag)
*/

#ifndef TREE_H
# define TREE_H

#include <stdio.h>
#include <stdlib.h>

#include "fsm.h"


/* non terminals */

typedef enum {
	AST_list,
	AST_logic_op,
	AST_and_if,
	AST_and_or,
	AST_pipeline,
	AST_command,
	MAX_AST
}				AstType;

typedef	struct							s_ast_node
{
	AstType								type;
	union
	{
		
		t_list							*cmd; // list of tokens that make up command including redirects flags args and command name
		struct
		{
			struct s_ast_node	*left;
			struct s_ast_node	*right;
		} 								op;
	};
}										t_ast_node;


void		add_left_child(t_ast_node **parent, t_ast_node *child);
void		add_right_child(t_ast_node **parent, t_ast_node *child);
t_ast_node	*make_node(t_list *cmd, AstType type);
void		print_tree(t_ast_node *tree);

#endif

