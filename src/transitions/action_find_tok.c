

#include "fsm.h"

void	action_find_tok_whitespace(t_fsm *fsm, t_list **tokens, int c)
{
	(void)c;
	(void)tokens;
	(void)fsm;
}

void	action_find_tok_reg_char(t_fsm *fsm, t_list **tokens, int c)
{
	(void)tokens;
	add_char_to_current_tok(fsm, c);
	fsm->parser_state = STATE_read_word;
}

void	action_find_tok_op_char(t_fsm *fsm, t_list **tokens, int c)
{
	(void)tokens;
	add_char_to_current_tok(fsm ,c);
	fsm->parser_state = STATE_read_op;
}

void	action_find_tok_semic(t_fsm *fsm, t_list **tokens, int c)
{
	(void)c;
	(void)tokens;
	fsm->parser_state = STATE_find_tok;
}

void	action_find_tok_squot(t_fsm *fsm, t_list **tokens, int c)
{
	(void)tokens;
	add_char_to_current_tok(fsm, c);
	fsm->parser_state = STATE_read_squot;
}

void	action_find_tok_dquot(t_fsm *fsm, t_list **tokens, int c)
{
	(void)tokens;
	add_char_to_current_tok(fsm, c);
	fsm->parser_state = STATE_read_dquot;
}
