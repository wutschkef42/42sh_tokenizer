

#include "lex.h"

/*
** fowards token stream by one token and returns 
** current token
*/

t_tok	*next_token(t_list **tokens)
{
	t_list	*next;

	if (!(*tokens) || !tokens)
	{
		printf("no more tokens...\n");
		return (NULL);
	}
		
	next = malloc(sizeof(t_list));
	next->data = malloc((*tokens)->data_size);
	ft_memcpy(next->data, (*tokens)->data, (*tokens)->data_size);
	next->next = NULL;
	if (*tokens)
	{
		*tokens = (*tokens)->next;
		return ((t_tok*)next->data);
	}
	return (NULL);
}


/*
** checks if type of current token fits into grammar 
*/

int	match(t_tok *current, TokType expected)
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

	command = NULL;
	if (!(*tokens))
		return (NULL);
	while (*tokens)
	{
		if (is_command(*tokens))
			ft_lstadd(&command, ft_lstnew((*tokens)->data, (*tokens)->data_size));
		else
			break ;
		next_token(tokens);
	}
	return (command);
}
