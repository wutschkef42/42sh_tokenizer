

#include "lex.h"

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
	add_char_to_current_tok(fsm, c);
	fsm->parser_state = STATE_read_op;
}

void	action_find_tok_semic(t_fsm *fsm, t_list **tokens, int c)
{
	(void)	c;
	t_tok	tok;

	tok.type = TYPE_semic;
	tok.id = ft_strdup(";");
	ft_lstpushback(tokens, ft_lstnew((void*)&tok, sizeof(t_tok)));
	ft_bzero(fsm->current_tok, fsm->current_tok_len);
	fsm->current_tok_len = 0;
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
