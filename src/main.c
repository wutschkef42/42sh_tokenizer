

#include "lex.h"
#include "ast.h"
#include "eval.h"


int	main(void)
{
	event_loop();


	/*
	root = (t_ast_node*)malloc(sizeof(t_ast_node));
	root->type = AST_list;
	root->cmd = NULL;
	root->op.left = NULL;
	root->op.right = NULL;
	tokens = run_state_machine(av[1]);
	process_tokens(&tokens);
	//print_tokenstream(tokens);
	parse_list(&tokens, &root);
	//char ** args = get_leftmost_command(&root);
	//print_args(args);
	print_level_order(root);
	*/


	return (1);
}