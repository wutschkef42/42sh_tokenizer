
#include "fsm.h"
#include "libft.h"


/* state transition table */

void	(*const state_table [MAX_STATES][MAX_EVENTS])(t_fsm *fsm, t_list **tokens, int c) =
{
	{
		action_find_tok_whitespace,
		action_find_tok_reg_char,
		action_find_tok_op_char,
		action_find_tok_semic,
		action_find_tok_squot,
		action_find_tok_dquot
	},

	{
		action_read_op_whitespace,
		action_read_op_reg_char,
		action_read_op_op_char,
		action_read_op_semic,
		action_read_op_squot,
		action_read_op_dquot
	},

	{
		action_read_word_whitespace,
		action_read_word_reg_char,
		action_read_word_op_char,
		action_read_word_semic,
		action_read_word_squot,
		action_read_word_dquot
	},

	{
		action_read_squot_whitespace,
		action_read_squot_reg_char,
		action_read_squot_op_char,
		action_read_squot_semic,
		action_read_squot_squot,
		action_read_squot_dquot
	},

	{
		action_read_dquot_whitespace,
		action_read_dquot_reg_char,
		action_read_dquot_op_char,
		action_read_dquot_semic,
		action_read_dquot_squot,
		action_read_dquot_dquot
	}
};

static
void	init_state_machine(t_fsm *fsm)
{
	fsm->current_tok_len = 0;
	fsm->parser_state = STATE_find_tok;
	fsm->pos = 0;
}


EventType	get_new_event(char c)
{
	if (c == ' ' || c == '\t')
		return (EVENT_whitespace);
	else if (ft_strchr("<>|&", c))
		return (EVENT_op_char);
	else if (c == ';')
		return (EVENT_semic);
	else if (c == '\'')
		return (EVENT_squot);
	else if (c == '\"')
		return (EVENT_dquot);
	else
		return (EVENT_reg_char);
}

t_list	*run_state_machine(char *input)
{
	t_fsm	fsm;
	t_list	*tokens;
	int		c;
	size_t	i;
	t_tok	tok;

	tokens = NULL;
	init_state_machine(&fsm);
	i = 0;
	while (i < ft_strlen(input))
	{
		c = input[i];
		fsm.event_type = get_new_event(c);
		state_table[fsm.parser_state][fsm.event_type](&fsm, &tokens, c);
		i++;
	}
	// add last token remaining in fsm buffer
	tok.type = (ft_strchr("<>|&", c)) ? TYPE_op : TYPE_word;
	tok.id = ft_strdup(fsm.current_tok);
	ft_lstpushback(&tokens, ft_lstnew((void*)&tok, sizeof(t_tok)));
	return (tokens);
}
