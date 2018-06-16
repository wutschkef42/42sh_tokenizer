

#include "fsm.h"
#include "btree.h"
#include "ast.h"


int	main(int ac, char **av)
{
	t_list	*tokens;
	t_ast_node	*root;

	if (ac !=2)
	{
		printf("usage: ./alex [string to tokenize]\n");
		return (1);
	}
	
	root = (t_ast_node*)malloc(sizeof(t_ast_node));
	root->type = AST_list;
	root->cmd = NULL;
	root->op.left = NULL;
	root->op.right = NULL;
	tokens = run_state_machine(av[1]);
	printf("\n--- before processing\n\n");
	print_tokenstream(tokens);
	process_tokens(&tokens);
	printf("\n--- after processing\n\n");
	print_tokenstream(tokens);


	/*
	t_ast_node	*tree;

	tree = NULL;

	add_left_child(&tree, make_node(tokens, AST_and_or));
	add_right_child(&tree, make_node(tokens, AST_and_if));
	add_left_child(&(tree->op.left), make_node(tokens, AST_pipeline));
	print_tree(tree);
	*/
	//printf("almost ok\n");
	parse_list(&tokens, &root);
	print_level_order(root);
	//print_tree(root);
	//printf("ok\n");
	return (1);
}