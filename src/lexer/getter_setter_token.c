

#include "libft.h"
#include "lex.h"


TokType	get_token_type(t_list *node)
{
	return (((t_tok*)(node->data))->type);
}


char	*get_token_id(t_list *tok)
{
	return (((t_tok*)tok->data)->id);
}


void	set_token_type(t_list *tok, TokType type)
{
	((t_tok*)tok->data)->type = type;
}

