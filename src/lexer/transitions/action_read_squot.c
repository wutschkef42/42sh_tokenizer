
#include "libft.h"
#include "fsm.h"

void	action_read_squot_whitespace(t_fsm *fsm, t_list **tokens, int c)
{
	(void)tokens;
	add_char_to_current_tok(fsm ,c);
}


void	action_read_squot_reg_char(t_fsm *fsm, t_list **tokens, int c)
{
	(void)tokens;
	add_char_to_current_tok(fsm ,c);
}

void	action_read_squot_op_char(t_fsm *fsm, t_list **tokens, int c)
{
	(void)tokens;
	add_char_to_current_tok(fsm ,c);
}

void	action_read_squot_semic(t_fsm *fsm, t_list **tokens, int c)
{
	(void)tokens;
	add_char_to_current_tok(fsm, c);
}

void	action_read_squot_squot(t_fsm *fsm, t_list **tokens, int c)
{
	t_tok	tok;

	tok.type = TYPE_word;
	add_char_to_current_tok(fsm, c);
	tok.id = ft_strdup(fsm->current_tok);
	ft_lstpushback(tokens, ft_lstnew((void*)&tok, sizeof(tok)));
	ft_bzero(fsm->current_tok, fsm->current_tok_len);
	fsm->current_tok_len = 0;
	fsm->parser_state = STATE_find_tok;
}

void	action_read_squot_dquot(t_fsm *fsm, t_list **tokens, int c)
{
	(void)tokens;
	add_char_to_current_tok(fsm ,c);
}