

#include "ast.h"
#include "libft.h"
#include "memager.h"


void		add_left_child(t_ast_node **parent, t_ast_node *child)
{
	if (!*parent)
	{
		*parent = child;
		return ;
	}
	(*parent)->op.left = child;
}


void		add_right_child(t_ast_node **parent, t_ast_node *child)
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

	if (!(node = (t_ast_node*)mgr_alloc(mgr_get_category(AST), sizeof(t_ast_node))))
		return (NULL);
	node->type = type;
	if (type == AST_command)
		node->cmd = cmd;
	else
	{
		node->op.left = NULL;
		node->op.right = NULL;
	}
	return (node);
}

