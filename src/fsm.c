
#include "fsm.h"
#include "libft.h"


/* state transition table */

void	(*const state_table [MAX_STATES][MAX_EVENTS])(t_fsm *fsm, int c) =
{
	{
		action_find_tok_whitespace,
		action_find_tok_reg_char,
		action_find_tok_op_char,
		action_find_tok_semic
	},

	{
		action_read_op_whitespace,
		action_read_op_reg_char,
		action_read_op_op_char,
		action_read_op_semic
	},

	{
		action_read_word_whitespace,
		action_read_word_reg_char,
		action_read_word_op_char,
		action_read_word_semic
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
	else
		return (EVENT_reg_char);
}

int	run_state_machine(char *input)
{
	t_fsm	fsm;
	int		c;
	size_t	i;

	init_state_machine(&fsm);
	i = 0;
	while (i < ft_strlen(input))
	{
		c = input[i];
		fsm.event_type = get_new_event(c);
		state_table[fsm.parser_state][fsm.event_type](&fsm, c);
		i++;
	}
	printf("last token: %s\n", fsm.current_tok);
	return (0);
}
