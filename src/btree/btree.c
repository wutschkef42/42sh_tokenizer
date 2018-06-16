

#include "btree.h"
#include "libft.h"

void	add_left_child(t_ast_node **parent, t_ast_node *child)
{
	if (!*parent)
	{
		*parent = child;
		return ;
	}
	(*parent)->op.left = child;
}

void	add_right_child(t_ast_node **parent, t_ast_node *child)
{
	if (!*parent)
	{
		*parent = child;
		return ;
	}
	(*parent)->op.right = child;
}

t_ast_node	*make_node(t_list *cmd, AstType type)
{
	t_ast_node	*node;

	if (!(node = (t_ast_node*)malloc(sizeof(t_ast_node))))
		return (NULL);
	node->type = type;
	if (type == AST_command)
	{
		if (!(node->cmd = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		node->cmd = cmd;
	}
	node->op.left = NULL;
	node->op.right = NULL;
	return (node);
}

void	print_tree(t_ast_node *tree)
{
	if (!tree)
		return ;
	printf("%u\n", tree->type);
	if (tree->type != AST_command)
	{
		print_tree(tree->op.left);
		print_tree(tree->op.right);
	}
}