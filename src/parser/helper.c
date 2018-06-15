

#include "fsm.h"

/*
** returns the next token from token stream
*/

t_tok	*next_token(t_list **tokens)
{
	t_list	*next;

	if (*tokens)
	{
		next = *tokens;
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
	if (current->type == expected)
		return (1);
	return (0);
}