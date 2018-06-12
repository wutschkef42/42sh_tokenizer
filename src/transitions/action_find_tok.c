

#include "fsm.h"

void	action_find_tok_whitespace(t_fsm *fsm, int c)
{
	(void)c;
	(void)fsm;
}

void	action_find_tok_reg_char(t_fsm *fsm, int c)
{
	add_char_to_current_tok(fsm, c);
	fsm->parser_state = STATE_read_word;
}

void	action_find_tok_op_char(t_fsm *fsm, int c)
{
	add_char_to_current_tok(fsm ,c);
	fsm->parser_state = STATE_read_op;
}

void	action_find_tok_semic(t_fsm *fsm, int c)
{
	(void)c;
	fsm->parser_state = STATE_find_tok;
}