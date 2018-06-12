
#include "libft.h"
#include "fsm.h"

void	action_read_word_whitespace(t_fsm *fsm, int c)
{
	(void)c;
	printf("word token: %s\n", fsm->current_tok);
	ft_bzero(fsm->current_tok, fsm->current_tok_len);
	fsm->current_tok_len = 0;
	fsm->parser_state = STATE_find_tok;
}


void	action_read_word_reg_char(t_fsm *fsm, int c)
{

	add_char_to_current_tok(fsm ,c);
	(void)fsm;

}

void	action_read_word_op_char(t_fsm *fsm, int c)
{
	
	printf("word token: %s\n", fsm->current_tok);
	ft_bzero(fsm->current_tok, fsm->current_tok_len);
	fsm->current_tok_len = 0;
	add_char_to_current_tok(fsm, c);
	fsm->parser_state = STATE_read_op;
}

void	action_read_word_semic(t_fsm *fsm, int c)
{
	(void)c;
	printf("operator token: %s\n", fsm->current_tok);
	ft_bzero(fsm->current_tok, fsm->current_tok_len);
	fsm->current_tok_len = 0;
	fsm->parser_state = STATE_find_tok;
}