
#include "libft.h"
#include "lex.h"

void	action_read_op_whitespace(t_fsm *fsm, t_list **tokens, int c)
{
	(void)	c;
	t_tok	tok;

	tok.type = TYPE_op;
	tok.id = ft_strdup(fsm->current_tok);
	ft_lstpushback(tokens, ft_lstnew((void*)&tok, sizeof(t_tok)));
	ft_bzero(fsm->current_tok, fsm->current_tok_len);
	fsm->current_tok_len = 0;
	fsm->parser_state = STATE_find_tok;
}


/* reading a reg_char after an op_char delimits the operator token.
** the token is stored
** then the token buffer is flushed
** then the buffer index reset to 0 and the current char stored
*/

void	action_read_op_reg_char(t_fsm *fsm, t_list **tokens, int c)
{
	t_tok	tok;

	tok.type = TYPE_op;
	tok.id = ft_strdup(fsm->current_tok);
	ft_lstpushback(tokens, ft_lstnew((void*)&tok, sizeof(t_tok)));
	ft_bzero(fsm->current_tok, fsm->current_tok_len);
	fsm->current_tok_len = 0;
	add_char_to_current_tok(fsm, c);
	fsm->parser_state = STATE_read_word;
}

void	action_read_op_op_char(t_fsm *fsm, t_list **tokens, int c)
{
	add_char_to_current_tok(fsm ,c);
	(void)tokens;
	(void)fsm;
}

void	action_read_op_semic(t_fsm *fsm, t_list **tokens, int c)
{
	(void)	c;
	t_tok	tok;

	tok.type = TYPE_op;
	tok.id = ft_strdup(fsm->current_tok);
	ft_lstpushback(tokens, ft_lstnew((void*)&tok, sizeof(t_tok)));
	ft_bzero(fsm->current_tok, fsm->current_tok_len);
	fsm->current_tok_len = 0;
	fsm->parser_state = STATE_find_tok;
	tok.type = TYPE_semic;
	tok.id = ft_strdup(";");
	ft_lstpushback(tokens, ft_lstnew((void*)&tok, sizeof(t_tok)));
}

void	action_read_op_squot(t_fsm *fsm, t_list **tokens, int c)
{
	t_tok	tok;

	tok.type = TYPE_op;
	tok.id = ft_strdup(fsm->current_tok);
	ft_lstpushback(tokens, ft_lstnew((void*)&tok, sizeof(t_tok)));
	ft_bzero(fsm->current_tok, fsm->current_tok_len);
	fsm->current_tok_len = 0;
	add_char_to_current_tok(fsm ,c);
	fsm->parser_state = STATE_read_squot;
}

void	action_read_op_dquot(t_fsm *fsm, t_list **tokens, int c)
{
	t_tok	tok;

	tok.type = TYPE_op;
	tok.id = ft_strdup(fsm->current_tok);
	ft_lstpushback(tokens, ft_lstnew((void*)&tok, sizeof(t_tok)));
	ft_bzero(fsm->current_tok, fsm->current_tok_len);
	fsm->current_tok_len = 0;
	add_char_to_current_tok(fsm ,c);
	fsm->parser_state = STATE_read_dquot;
}