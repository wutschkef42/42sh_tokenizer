

#include "memager.h" 
#include "lex.h"

/*
** fowards token stream by one token and returns 
** current token
*/

void	next_token(t_list **tokens)
{
	if (!(*tokens) || !tokens)
		printf("no more tokens...\n");
	if (*tokens)
		*tokens = (*tokens)->next;
}


/*
** checks if type of current token fits into grammar 
*/

int		match(t_tok *current, TokType expected)
{
	if (!current || !(current->type))
		return (0);
	if (current->type == expected)
		return (1);
	return (0);
}


/*
** checks if token is part of a simple command
** simple commands consist of command names, flags,
** arguments and redirects
*/

int		is_command(t_list *token)
{
	if (token->data)
	{
		if (((t_tok*)token->data)->type == TYPE_word)
			return (1);
		else if (((t_tok*)token->data)->type == TYPE_less)
			return (1);
		else if (((t_tok*)token->data)->type == TYPE_dless)
			return (1);
		else if (((t_tok*)token->data)->type == TYPE_great)
			return (1);
	}
	return (0);
}


/*
** makes deep copy of consecutive command tokens
** forwards the token stream to skip the command
** returns a pointe to the deep copy
*/

t_list	*eat_command(t_list **tokens)
{
	t_list	*command;
	t_list	*new;

	command = NULL;
	if (!(*tokens))
		return (NULL);
	while (*tokens)
	{
		if (is_command(*tokens))
		{
			new = ft_lstnew((*tokens)->data, (*tokens)->data_size);
			ft_lstadd(&command, new);
			mgr_add_ref(mgr_get_category(AST), (void*)new, sizeof(t_tok));
			mgr_add_ref(mgr_get_category(AST), (void*)(new->data), sizeof(t_tok));
		}
		else
			break ;
		next_token(tokens);
	}
	return (command);
}
