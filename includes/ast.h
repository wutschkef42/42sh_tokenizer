

#ifndef AST_H
# define AST_H


/* BNF grammar 

	program = command (command ";")*
	command = factor ("||" | "&&"") factor


*/

#include "btree.h"

typedef enum
{
	less,
	dless,
	great,
	semic
}			Terminals;





int	parse_list(t_list **tokens, t_ast_node **ast);
int	parse_logic_op(t_list **tokens, t_ast_node **ast);
int	parse_pipeline(t_list **tokens, t_ast_node **ast);
int	parse_command(t_list **tokens, t_ast_node **ast);

int	match(t_tok *current, TokType expected);
t_tok	*next_token(t_list **tokens);

t_list		*eat_command(t_list **tokens);
int		is_command(t_list *token);



#endif