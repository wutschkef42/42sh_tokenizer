

#include <stdlib.h>
#include "ast.h"


void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;

	i = 0;
	while (tab[i])
	{
		tab[i] = NULL;
		free(tab[i]);
		i++;
	}
	free(tab);
}


void	free_ast(t_ast_node *ast)
{
	if (!ast)
		return ;
	free_ast(ast->op.left);
	free_ast(ast->op.right);
	free(ast);
}