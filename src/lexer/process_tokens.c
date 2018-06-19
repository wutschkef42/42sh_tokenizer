

#include "lex.h"
#include "libft.h"




/* consumes raw token stream and
** adds precise token_type to each token
** returns 0 on succesful parse
** returns 1 on parse error
*/
int		process_tokens(t_list **tokens)
{
	t_list	*tok;

	if (!tokens)
		return (1);
	tok = *tokens;
	while (tok)
	{
		if (ft_strcmp(get_token_id(tok), LESS) == 0)
			set_token_type(tok, TYPE_less);
		else if (ft_strcmp(get_token_id(tok), DLESS) == 0)
			set_token_type(tok, TYPE_dless);
		else if (ft_strcmp(get_token_id(tok), GREAT) == 0)
			set_token_type(tok, TYPE_great);
		else if (ft_strcmp(get_token_id(tok), AND_IF) == 0)
			set_token_type(tok, TYPE_and_if);
		else if (ft_strcmp(get_token_id(tok), AND_OR) == 0)
			set_token_type(tok, TYPE_and_or);
		else if (ft_strcmp(get_token_id(tok), SEMIC) == 0)
			set_token_type(tok, TYPE_semic);
		else if (ft_strcmp(get_token_id(tok), PIPE) == 0)
			set_token_type(tok, TYPE_pipe);
		else if (get_token_id(tok)[0] == SQUOT)
			set_token_type(tok, TYPE_squot);
		else if (get_token_id(tok)[0] == DQUOT)
			set_token_type(tok, TYPE_dquot);
		else if (get_token_type(tok) == TYPE_word)
		{
			tok = tok->next;
			continue ;
		}
		else
		{
			printf("process_tokens: parse error on: %s\n", ((t_tok*)tok->data)->id);
			return (1);
		}
		tok = tok->next;
	}
	return (0);
}