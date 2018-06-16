

#include "fsm.h"

/*
** returns the next token from token stream
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