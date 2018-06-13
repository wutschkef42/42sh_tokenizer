

#include "fsm.h"
#include "libft.h"

/* consumes raw token stream and
** adds precise token_type to each token
** returns 0 on succesful parse
** returns 1 on parse error
*/
int	process_tokens(t_list **tokens)
{
	t_list	*tok;

	if (!tokens)
		return (1);
	tok = *tokens;
	while (tok)
	{
		if (ft_strcmp(((t_tok*)tok->data)->id, LESS) == 0)
			((t_tok*)tok->data)->type = TYPE_less;
		else if (ft_strcmp(((t_tok*)tok->data)->id, DLESS) == 0)
			((t_tok*)tok->data)->type = TYPE_dless;
		else if (ft_strcmp(((t_tok*)tok->data)->id, GREAT) == 0)
			((t_tok*)tok->data)->type = TYPE_great;
		else if (ft_strcmp(((t_tok*)tok->data)->id, AND_IF) == 0)
			((t_tok*)tok->data)->type = TYPE_and_if;
		else if (ft_strcmp(((t_tok*)tok->data)->id, AND_OR) == 0)
			((t_tok*)tok->data)->type = TYPE_or_if;
		else if (ft_strcmp(((t_tok*)tok->data)->id, SEMIC) == 0)
			((t_tok*)tok->data)->type = TYPE_semic;
		else if ((((t_tok*)tok->data)->id)[0] == SQUOT)
			((t_tok*)tok->data)->type = TYPE_squot;
		else if ((((t_tok*)tok->data)->id)[0] == DQUOT)
			((t_tok*)tok->data)->type = TYPE_dquot;
		else if (((t_tok*)tok->data)->type == TYPE_word)
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