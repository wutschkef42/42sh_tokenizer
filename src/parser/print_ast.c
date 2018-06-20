
#include "ast.h"
#include "libft.h"


/* print level order traversal of tree */

void		print_level_order(t_ast_node *root)
{
	int	height;
	int	i;


	height = tree_height(root);
	i = 1;
	while (i <= height)
	{
		print_given_level(root, i);
		i++;
		printf("\n");
	}

}




/* prints string formatted representation of AST node */

void		print_node(t_ast_node *node)
{
	if (!node)
		return ;	
	if (node->type == AST_list)
		printf("{ AST_list } ");
	else if (node->type == AST_logic_op)
		printf("{ AST_logic_op } ");
	else if (node->type == AST_and_if)
		printf("{ AST_and_if } ");
	else if (node->type == AST_and_or)
		printf("{ AST_and_or } ");
	else if (node->type == AST_pipeline)
		printf("{ AST_pipeline } ");
	else if (node->type == AST_command)
	{
		printf("{ AST_command } ");
		print_tokenstream(node->cmd);
	}
	
	printf("done\n");	

}

/* print all nodes at a given level */

void		print_given_level(t_ast_node *root, int level)
{
	if (!root)
		return ;
	if (level == 1)
		print_node(root);
	else if (level > 1)
	{
		print_given_level(root->op.left, level - 1);
		print_given_level(root->op.right, level - 1);
	}
}


/* compute height of tree - longest path from root to leaf */

int			tree_height(t_ast_node *root)
{
	int	lheight;
	int	rheight;

	lheight = 0;
	rheight = 0;
	if (!root)
		return (0);
	if (root->type != AST_command)
		lheight = tree_height(root->op.left);
	if (root->type != AST_command)	
		rheight = tree_height(root->op.right);

	if (lheight > rheight)
		return (lheight + 1);
	else
		return (rheight + 1);
}
