

#include <stdlib.h>
#include "ast.h"
#include "doubly_linked_list.h"
#include "hashmap.h"
#include "misc.h"


void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

/*
** does not free token->id,
** frees only list container
** necessary because eat_command makes a deep
** copy of part of the token list 
** the token list is freed including token->id fields
** so when freeing the output of eat_command
** freeing token->id causes a double free
*/

void	free_list_shallow(t_list *lst)
{
	t_list	*node;

	if (!lst)
		return ;
	while (lst)
	{
		node = lst;
		free(lst->data);
		lst = lst->next;
		free(node);
	}
}


void	free_ast(t_ast_node *ast)
{
	if (!ast)
		return ;
	if (!(ast->type == AST_command))
	{
		free_ast(ast->op.left);
		free_ast(ast->op.right);
	}
	
	if (ast->type == AST_command)
		free_list_shallow(ast->cmd);
	free(ast);
}


/* should be called free_tokens
** because it not only frees the list itself
** but also heap allocated memory pointers to which
** reside inside of the list nodes data portion
*/

void	free_list(t_list *lst)
{
	t_list	*node;

	if (!lst)
		return ;
	while (lst)
	{
		node = lst;
		free(((t_tok*)lst->data)->id);
		free(lst->data);
		lst = lst->next;
		free(node);
	}
}

void	dll_delete_head(t_dll_node **head)
{
	t_dll_node	*node;

	if (!head)
		return ;
	if (!(*head))
		return ;
	node = *head;
	*head = node->next;
	free(node->data);
	node->data = NULL;
	free(node);
	node->prev = NULL;
	node->next = NULL;
}

void	dll_delete_list(t_dll_node **head)
{
	if (!head || !(*head))
		return ;
	while (*head)
	{
		dll_delete_head(head);
		*head = (*head)->next;
	}
}

void	hm_free_entry(t_hm_entry *entry)
{
	free(entry->key->data);
	free(entry->key);
	free(entry);
}
