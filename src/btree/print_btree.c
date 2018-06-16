
#include "btree.h"
#include "libft.h"


/* print level order traversal of tree */

void		print_level_order(t_ast_node *root)
{
	int	height;
	int	i;
	int	j;

	height = tree_height(root);
	i = 1;
	while (i <= height)
	{
		j = i;
		while (j++ < height)
			printf("\t\t");
		print_given_level(root, i);
		i++;
		printf("\n");
	}

}




/* prints string formatted representation of AST node */

void		print_node(t_ast_node *node)
{
	
	if (node->type == AST_list)
		printf("{ AST_list }\t\t");
	else if (node->type == AST_logic_op)
		printf("{ AST_logic_op}\t\t");
	else if (node->type == AST_and_if)
		printf("{ AST_and_if }\t\t");
	else if (node->type == AST_and_or)
		printf("{ AST_and_or }\t\t");
	else if (node->type == AST_pipeline)
		printf("{ AST_pipeline }\t\t");
	else if (node->type == AST_command)
		printf("{ AST_command }\t\t");
	
	

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

	if (!root)
		return (0);
	lheight = tree_height(root->op.left);
	rheight = tree_height(root->op.right);

	if (lheight > rheight)
		return (lheight + 1);
	else
		return (rheight + 1);
}
